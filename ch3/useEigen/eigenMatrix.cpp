#include <iostream>
using namespace std;

#include <ctime>
#include <Eigen/Core>
#include <Eigen/Dense>
using namespace Eigen;

#define MATRIX_SIZE 50

int main(int arc, char **argv) {
	Matrix<float, 2, 3> matrix_23;
	matrix_23 << 1, 2, 3, 4, 5, 6;
	cout << "please work \n" << matrix_23 << endl;
}
