#include <iostream>
#include <cmath>
using namespace std;

#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace Eigen;
// learning eigen geometry module

int main(int argc, char **argv) {
	Matrix3d rotation_matrix = Matrix3d::Identity();
	AngleAxisd rotation_vector(M_PI / 4, Vector3d(0, 0, 1)); // 45 z-axis
	cout.precision(3);
	cout << "rotation matrix = \n" << rotation_vector.matrix() << endl;
	// alternative to rotation_vector.matrix()
	rotation_matrix = rotation_vector.toRotationMatrix();
	Vector3d v(1, 0, 0);
	Vector3d v_rotated = rotation_vector * v;
	cout << "(1,0,0) after rotation with angle axis = " << v_rotated.transpose() << endl;
	// alternative to above
	v_rotated = rotation_matrix * v;
	Vector3d euler_angles = rotation_matrix.eulerAngles(2, 1, 0); // rpy
	cout << "yaw pitch roll = " << euler_angles.transpose() << endl;

	Isometry3d T = Isometry3d::Identity();
	T.rotate(rotation_vector);
	T.pretranslate(Vector3d(1,3,4));
	cout << "transform matrix (isometry) = \n" << T.matrix() << endl;

	Vector3d v_transformed = T * v;
	cout << "v transformed = " << v_transformed.transpose() << endl;

  // quaternion 
	Quaterniond q = Quaterniond(rotation_vector);
	cout << "quaternion from rotation vector = " << q.coeffs().transpose() 
		<< endl; // comes out in (x, y, z, w) order -- real last
	q = Quaterniond(rotation_matrix);
	cout << "quaternion from rotation matrix = " << q.coeffs().transpose() 
		<< endl;
	v_rotated = q * v; // overloaded multiplication -- qvq-1
	cout << "(1, 0, 0) after rotation = " << v_rotated.transpose() << endl;
	cout << "should be equal to " << (q * Quaterniond(0,1,0,0) * q.inverse()).coeffs().transpose() << endl;
}
