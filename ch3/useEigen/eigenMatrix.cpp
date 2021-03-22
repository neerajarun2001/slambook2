#include <iostream>
using namespace std;

#include <ctime>
#include <Eigen/Core>
#include <Eigen/Dense>
using namespace Eigen;

#define MATRIX_SIZE 50

int main(int arc, char **argv) {
	// types Eigen::Matrix (template class) -- takes data type, row, col
	Matrix<float, 2, 3> matrix_23;

	// Vector3d is the same thing as double, 3, 1
	// Matrix3d is the same thing as double, 3, 3
	Matrix3d matrix_33 = Matrix3d::Zero();
	// dynamic sizing
	MatrixXd matrix_x;
  matrix_23 << 1, 2, 3, 4, 5, 6;
	cout << "matrix 2x3 with values 1 through 6: \n" << matrix_23 << endl;

	cout << matrix_23(1, 1) << endl;
  Matrix<float, 3, 1> vec3d;
	Vector3d vec;
	vec3d << 1, 2, 3;
	vec << 4, 5, 6;
	Matrix<float, 2, 1> result = matrix_23 * vec3d;
	cout << result << endl;

	matrix_33 = Matrix3d::Random();
	SelfAdjointEigenSolver<Matrix3d> eigen_solver(matrix_33.transpose() * 
			matrix_33);
	cout << "Eigen values = \n" << eigen_solver.eigenvalues() << endl;
	cout << "Eigen vectors = \n" << eigen_solver.eigenvectors() << endl;

	Matrix<double, MATRIX_SIZE, MATRIX_SIZE> matrix_NN = 
		MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);
	matrix_NN = matrix_NN * matrix_NN.transpose();
	Matrix<double, MATRIX_SIZE, 1> v_Nd = MatrixXd::Random(MATRIX_SIZE, 1);

	clock_t time = clock();
	Matrix<double, MATRIX_SIZE, 1> x = matrix_NN.inverse() * v_Nd;
	cout << "time of normal inverse is " 
		<< 100 * (clock() - time) / (double)CLOCKS_PER_SEC << "ms" << endl;
	cout << "x = " << x.transpose() << endl;

	time = clock();
	x = matrix_NN.colPivHouseholderQr().solve(v_Nd);
  cout << "time of Qr decomposition is " 
		<< 100 * (clock() - time) / (double)CLOCKS_PER_SEC << "ms" << endl;
	cout << "x = " << x.transpose() << endl;

  time = clock();
	x = matrix_NN.ldlt().solve(v_Nd);
  cout << "time of Qr decomposition is " 
		<< 100 * (clock() - time) / (double)CLOCKS_PER_SEC << "ms" << endl;
	cout << "x = " << x.transpose() << endl;

  return 0;





}
