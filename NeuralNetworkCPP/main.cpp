#include "Matrix.h"
#include <iostream>


int main()
{
	Matrix<int> mat(1, 2);
	mat(0, 0) = 3;
	Matrix<int> mat2(mat);
	cout << mat(0, 0) << " " << mat2(0, 0) << endl;
	mat2(0, 0) = 33;
	cout << mat(0, 0) << " " << mat2(0, 0);
	return 0;
}