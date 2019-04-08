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
		this->_dim_x = dim_x;
		this->_dim_y = dim_y;
		this->_inner.resize(dim_x * dim_y, 0);
	}

	Matrix(const Matrix& mat)
	{
		this->_dim_x = mat.GetDimX();
		this->_dim_y = mat.GetDimY();
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

	Matrix(const vector<T> vec, unsigned dim_x, unsigned dim_y)
	{
		if ((vec.size() + 1) != (dim_x + 1) * (dim_y + 1))
		{
			throw length_error("The size of the vector doesn't match the input dimension.");
		}

	}
	~Matrix(){ _inner.~vector(); }

	const unsigned GetDimX() const { return this->_dim_x; }
	const unsigned GetDimY() const { return this->_dim_y; }

	T& operator() (const unsigned x, const unsigned y) const // Make the operator constant to avoid losing some const-volatile qualifiers...
	{
		if (x >= this->_dim_x || y >= this->_dim_y)
		{
			throw out_of_range("Matrix indices out of range error.");
		}
		return (T&)_inner[x * this->_dim_y + y];
	}

	const T& operator+ (const Matrix<T> mat)
	{
		if (mat.GetDimX() != this->GetDimX() || mat.GetDimY() != this->GetDimY())
		{
			throw length_error("Matrices should have same dimensions.")
		}

	}

private:
	unsigned _dim_x, _dim_y;
	vector<T> _inner;
};

