#include <iostream>
#include <ctime>
using namespace std;

#include <Eigen/Core>
#include <Eigen/Dense>
using namespace Eigen;

#define MATRIX_SIZE 50

int main(int argc, char **argv) {
  // All vectors and matrices in Eigen are Eigen::Matrix, which is a template
  // class
  Matrix<float, 2, 3> matrix_23;

  // These two are the same
  Vector3d v_3d;
  Matrix<float, 3, 1> vd_3d;

  Matrix3d matrix_33 = Matrix3d::Zero();           // initialized to zero
  Matrix<double, Dynamic, Dynamic> matrix_dynamic; // when unsure of the size
  MatrixXd matrix_x;                               // simpler

  // Operations
  // Input data (initialization)
  matrix_23 << 1, 2, 3, 4, 5, 6;
  // Output
  cout << "directly cout matrix 2x3: \n" << matrix_23 << endl;

  // Use () to access elements in the matrix
  cout << "print matrix 2x3 by element: " << endl;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      cout << matrix_23(i, j) << " ";
    }
    cout << endl;
  }

  v_3d << 3, 2, 1;
  vd_3d << 4, 5, 6;

  // You can't mix two different types of matrices like: Matrix<double, 2, 1>
  // result_wrong_type = matrix_23 * v_3d; It should be explicitly converted
  Matrix<double, 2, 1> result1 = matrix_23.cast<double>() * v_3d;
  cout << "[1,2,3;4,5,6] * [3,2,1] = " << result1.transpose() << endl;
  Matrix<float, 2, 1> result2 = matrix_23 * vd_3d;
  cout << "[1,2,3;4,5,6] * [4,5,6] = " << result2.transpose() << endl;

  // Some matrix operations
  matrix_33 = Matrix3d::Random(); // random number matrix
  cout << "random matrix: \n" << matrix_33 << endl;
  cout << "transpose: \n" << matrix_33.transpose() << endl;
  cout << "sum: " << matrix_33.sum() << endl;
  cout << "trace: " << matrix_33.trace() << endl;
  cout << "times 10: \n" << 10 * matrix_33 << endl;
  cout << "inverse: \n" << matrix_33.inverse() << endl;
  cout << "det: \n" << matrix_33.determinant() << endl;

  // Eigenvalues
  SelfAdjointEigenSolver<Matrix3d> eigen_solver(matrix_33.transpose() *
                                                matrix_33);
  cout << "Eigen values: \n" << eigen_solver.eigenvalues() << endl;
  cout << "Eigen vectors: \n" << eigen_solver.eigenvectors() << endl;

  // Solving Equations
  Matrix<double, MATRIX_SIZE, MATRIX_SIZE> matrix_NN =
      MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);
  matrix_NN = matrix_NN * matrix_NN.transpose();
  Matrix<double, MATRIX_SIZE, 1> v_Nd = MatrixXd::Random(MATRIX_SIZE, 1);

  // Direct inversion
  clock_t time_stt = clock();
  Matrix<double, MATRIX_SIZE, 1> x = matrix_NN.inverse() * v_Nd;
  cout << "time of direct inverse: "
       << 1000 * (clock() - time_stt) / (double)CLOCKS_PER_SEC << "ms" << endl;
  cout << "x = " << x.transpose() << endl;

  // QR Decomposition
  time_stt = clock();
  x = matrix_NN.colPivHouseholderQr().solve(v_Nd);
  cout << "time of QR decomposition: "
       << 1000 * (clock() - time_stt) / (double)CLOCKS_PER_SEC << "ms" << endl;
  cout << "x = " << x.transpose() << endl;
  
  return 0;
}
