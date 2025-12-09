# include <iostream>
# include <cmath>
# include <Eigen/Core>
# include <Eigen/Geometry>
# include "sophus/se3.hpp"

using namespace std;
using namespace Eigen;

int main(int argc, char **argv) {
  // SO(3) Rotation Matrix with 90 degrees along the Z axis
  Matrix3d R = AngleAxisd(M_PI/2,Vector3d(0,0,1)).toRotationMatrix();
  // Quaternion with the same rotation
  Quaterniond q(R);
  // They are equivalent
  Sophus::SO3d SO3_R(R);
  Sophus::SO3d SO3_q(q);
  cout << "SO(3) from matrix:\n" << SO3_R.matrix() << endl;
  cout << "SO(3) from quaternion:\n" << SO3_q.matrix() << endl;

  // Use logarithmic map to get the Lie algebra
  Vector3d so3 = SO3_R.log();
  cout << "so(3):\n" << so3.transpose() << endl;
  // hat converts from vector to skew-symmetric matrix
  cout << "so(3) hat:\n" << Sophus::SO3d::hat(so3) << endl;
  // Inversely, vee converts from matrix to vector
  cout << "so(3) hat vee:\n" << Sophus::SO3d::vee(Sophus::SO3d::hat(so3)).transpose() << endl;

  // Update by perturbation model
  Vector3d update_so3(1e-4, 0, 0);
  Sophus::SO3d SO3_updated = Sophus::SO3d::exp(update_so3) * SO3_R;
  cout << "SO(3) updated:\n" << SO3_updated.matrix() << endl;

  cout << "***********************************" << endl;

  // Similar for SE(3)
  Vector3d t(1, 0, 0);
  Sophus::SE3d SE3_Rt(R, t);
  Sophus::SE3d SE3_qt(q, t);
  cout << "SE(3) from R,t:\n" << SE3_Rt.matrix() << endl;
  cout << "SE(3) from q,t:\n" << SE3_qt.matrix() << endl;

  // Lie algebra is a 6d vector
  typedef Eigen::Matrix<double, 6, 1> Vector6d;
  Vector6d se3 = SE3_Rt.log();
  // Sophus puts the translation first and then the rotation
  cout << "se(3):\n" << se3.transpose() << endl;
  // hat and vee are the same as SO(3)
  cout << "se(3) hat:\n" << Sophus::SE3d::hat(se3) << endl;
  cout << "se(3) hat vee:\n" << Sophus::SE3d::vee(Sophus::SE3d::hat(se3)).transpose() << endl;

  // Update by perturbation model
  Vector6d update_se3;
  update_se3.setZero();
  update_se3(0, 0) = 1e-4;
  Sophus::SE3d SE3_updated = Sophus::SE3d::exp(update_se3) * SE3_Rt;
  cout << "SE(3) updated:\n" << SE3_updated.matrix() << endl;

  return 0;
}