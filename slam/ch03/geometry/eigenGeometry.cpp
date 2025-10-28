#include <cmath>
#include <iostream>
using namespace std;

#include <Eigen/Core>
#include <Eigen/Geometry>
using namespace Eigen;

int main(int argc, char **argv) {

  // 3D rotation matrices use Matrix3d or Matrix3f
  Matrix3d rotation_matrix = Matrix3d::Identity();

  // Rotation vectors use AngleAxis (operation overloaded)
  AngleAxisd rotation_vector(
      M_PI / 4, Vector3d(0, 0, 1)); // rotate 45 degrees along the Z axis
  cout.precision(3);
  cout << "rotation matrix:\n"
       << rotation_vector.matrix() << endl; // convert to matrix with matrix()

  // Can be assigned directly
  rotation_matrix = rotation_vector.toRotationMatrix();

  // Coordinate transformation with AngleAxis
  Vector3d v(1, 0, 0);
  Vector3d v_rotated = rotation_vector * v;
  cout << "(1,0,0) after rotation (by angle axis)\t: " << v_rotated.transpose()
       << endl;

  // Coordinate transformation with rotation matrix
  v_rotated = rotation_matrix * v;
  cout << "(1,0,0) after rotation (by matrix)\t: " << v_rotated.transpose()
       << endl;

  // Euler angle conversion
  Vector3d euler_angles =
      rotation_matrix.eulerAngles(2, 1, 0); // ZYX order (roll, pitch, yaw)
  cout << "yaw pitch roll: " << euler_angles.transpose() << endl;

  // Euclidean transformation matrix using Eigen::Isometry
  Isometry3d T = Isometry3d::Identity(); // essentially a 4x4 matrix
  T.rotate(rotation_vector);         // rotate according to the rotation vector
  T.pretranslate(Vector3d(1, 3, 4)); // set the translation vector to (1,3,4)
  cout << "Transform matrix: \n" << T.matrix() << endl;

  // Use the transformation matrix for coordinate transformation
  Vector3d v_transformed = T * v; // equivalent to R*v+t
  cout << "v transformed: " << v_transformed.transpose() << endl;

  // For affine and projective transformations, use Eigen::Affine3d and
  // Eigen::Projective3d

  // Quaternion
  // Can assign AngleAxis directly to quaternions and vice versa
  Quaterniond q = Quaterniond(rotation_vector);
  cout << "quaternion from rotation vector: " << q.coeffs().transpose()
       << endl; // the order of the coeffs is (x, y, z, w) where w is the real
                // part

  // Can also assign a rotation matrix to it
  q = Quaterniond(rotation_matrix);
  cout << "quaternion from rotation matrix: " << q.coeffs().transpose() << endl;

  // Rotate a vector with a quaternion
  v_rotated = q * v; // qvq^{-1}
  cout << "(1,0,0) after rotation (by quaternion)\t: " << v_rotated.transpose() << endl;

  // Expressed with regular vector multiplication
  cout << "should be equal to " << (q * Quaterniond(0, 1, 0, 0) * q.inverse()).coeffs().transpose() << endl;

  return 0;
}
