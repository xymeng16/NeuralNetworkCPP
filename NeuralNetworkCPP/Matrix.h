#pragma once
#include <vector>
#include <stdexcept>
using namespace std;

template <class T>
class Matrix
{
public:
	Matrix(unsigned dim_x, unsigned dim_y) 
	{
		_dim_x = dim_x;
		_dim_y = dim_y;
		_inner.resize(dim_x * dim_y, 0); 
	}

	Matrix(const Matrix& mat)
	{
		_dim_x = mat.GetDimX();
		_dim_y = mat.GetDimY();
		// Copy constructor, dim set before	
		_inner.resize(_dim_x * _dim_y, 0);
		for (unsigned i = 0; i < _dim_x; i++)
		{
			for (unsigned j = 0; j < _dim_y; j++)
			{
				_inner[i * _dim_y + j] = mat(i, j);
			}
		}
	}

	~Matrix(){ _inner.~vector(); }

	const unsigned GetDimX() const { return _dim_x; }
	const unsigned GetDimY() const { return _dim_y; }

	T& operator() (const unsigned x, const unsigned y) const // Make the operator constant to avoid losing some const-volatile qualifiers...
	{
		if (x >= _dim_x || y >= _dim_y)
		{
			throw out_of_range("Matrix indices out of range error.");
		}
		return (T&)_inner[x * _dim_y + y];
	}

	const T& operator+ (const Matrix<T>)
	{
		
	}

private:
	unsigned _dim_x, _dim_y;
	vector<T> _inner;
};

