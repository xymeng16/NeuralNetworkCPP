#pragma once
#include <vector>
using namespace std;

template <class T>
class Matrix
{
public:
	Matrix(unsigned dim_x, unsigned dim_y);
	Matrix(const Matrix& mat);
	~Matrix();

	unsigned GetDimX();
	unsigned GetDimY();

	const T& operator() (const unsigned x, const unsigned y);

	

private:
	unsigned _dim_x, _dim_y;
	vector<T> _inner;
};

