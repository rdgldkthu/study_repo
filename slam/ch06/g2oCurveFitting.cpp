#include <iostream>
#include <g2o/core/g2o_core_api.h>
#include <g2o/core/base_vertex.h>
#include <g2o/core/base_unary_edge.h>
#include <g2o/core/block_solver.h>
#include <g2o/core/optimization_algorithm_levenberg.h>
#include <g2o/core/optimization_algorithm_gauss_newton.h>
#include <g2o/core/optimization_algorithm_dogleg.h>
#include <g2o/solvers/dense/linear_solver_dense.h>
#include <Eigen/Core>
#include <opencv2/core/core.hpp>
#include <cmath>
#include <chrono>

using namespace std;

// Vertex: 3d vector
class CurveFittingVertex : public g2o::BaseVertex<3, Eigen::Vector3d> {
public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  // Override the reset function
  virtual void setToOriginImpl() override { _estimate << 0, 0, 0; }

  // Override the plus operator, just plain vector addition
  virtual void oplusImpl(const double *update) override {
    _estimate += Eigen::Vector3d(update);
  }

  virtual bool read(istream &in) { return true; }
  virtual bool write(ostream &out) const { return true; }
};

// Edge: 1d error term, connected to exactly one vertex
class CurveFittingEdge
    : public g2o::BaseUnaryEdge<1, double, CurveFittingVertex> {
public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  CurveFittingEdge(double x) : BaseUnaryEdge(), _x(x) {}

  // Define the error term computation
  virtual void computeError() override {
    const CurveFittingVertex *v =
        static_cast<const CurveFittingVertex *>(_vertices[0]);
    const Eigen::Vector3d abc = v->estimate();
    _error(0, 0) =
        _measurement - exp(abc(0, 0) * _x * _x + abc(1, 0) * _x + abc(2, 0));
  }

  // Jacobian
  virtual void linearizeOplus() override {
    const CurveFittingVertex *v =
        static_cast<const CurveFittingVertex *>(_vertices[0]);
    const Eigen::Vector3d abc = v->estimate();
    double y = exp(abc[0] * _x * _x + abc[1] * _x + abc[2]);
    _jacobianOplusXi[0] = -_x * _x * y;
    _jacobianOplusXi[1] = -_x * y;
    _jacobianOplusXi[2] = -y;
  }

  virtual bool read(istream &in) { return true; }
  virtual bool write(ostream &out) const { return true; }

public:
  double _x; // x data, note y is given in _measurement
};

int main(int argc, char **argv) {
  double ar = 1.0, br = 2.0, cr = 1.0;  // ground truth values
  double ae = 2.0, be = -1.0, ce = 5.0; // initial estimation
  int N = 100;                          // number of data points
  double w_sigma = 1.0;                 // sigma of the noise
  double inv_sigma = 1.0 / w_sigma;
  cv::RNG rng; // random number generator

  vector<double> x_data, y_data;
  for (int i = 0; i < N; i++) {
    double x = i / 100.0;
    x_data.push_back(x);
    y_data.push_back(exp(ar * x * x + br * x + cr) +
                     rng.gaussian(w_sigma * w_sigma));
  }

  typedef g2o::BlockSolver<g2o::BlockSolverTraits<3, 1>> BlockSolverType;
  typedef g2o::LinearSolverDense<BlockSolverType::PoseMatrixType>
      LinearSolverType;

  // Choose the optimization method from GN, LM, DogLeg
  //   auto solver = new g2o::OptimizationAlgorithmGaussNewton(
  //       make_unique<BlockSolverType>(make_unique<LinearSolverType>()));
  auto blockSolver =
      std::make_unique<BlockSolverType>(std::make_unique<LinearSolverType>());
  auto *solver =
      new g2o::OptimizationAlgorithmGaussNewton(std::move(blockSolver));
  g2o::SparseOptimizer optimizer;
  optimizer.setAlgorithm(solver);
  optimizer.setVerbose(true);

  // Add vertex
  CurveFittingVertex *v = new CurveFittingVertex();
  v->setEstimate(Eigen::Vector3d(ae, be, ce));
  v->setId(0);
  optimizer.addVertex(v);

  // Add edges
  for (int i = 0; i < N; i++) {
    CurveFittingEdge *edge = new CurveFittingEdge(x_data[i]);
    edge->setId(i);
    edge->setVertex(0, v);
    edge->setMeasurement(y_data[i]);
    edge->setInformation(Eigen::Matrix<double, 1, 1>::Identity() * 1 /
                         (w_sigma * w_sigma));
    optimizer.addEdge(edge);
  }

  // Carry out the optimization
  cout << "Start optimization" << endl;
  chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
  optimizer.initializeOptimization();
  optimizer.optimize(10);
  chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
  chrono::duration<double> time_used =
      chrono::duration_cast<chrono::duration<double>>(t2 - t1);
  cout << "process took " << time_used.count() * 1000.0 << "ms" << endl;

  // Print the results
  Eigen::Vector3d abc_estimate = v->estimate();
  cout << "estimated: " << abc_estimate.transpose() << endl;

  return 0;
}
