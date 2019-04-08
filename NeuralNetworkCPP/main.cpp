#include "Matrix.h"
#include <iostream>


int main()
{
	Matrix<unsigned> mat(1, 2);
	mat(0, 0) = 3;
	Matrix<int> mat2(1,2);
	Matrix<float> mat3(1, 2);
	Matrix<double> mat4(1, 2);
	cout << mat(0, 0) << " " << mat2(0, 0) << endl;
	mat2(0, 0) = 33;
	cout << mat(0, 0) << " " << mat2(0, 0) << endl;
	// cout << typeid(mat(0,0)).name() << " " << typeid(mat2(0, 0)).name() << " " << typeid(mat3(0, 0)).name() << " " << typeid(mat4(0, 0)).name();
	cout << mat._getDataType();
	return 0;
}