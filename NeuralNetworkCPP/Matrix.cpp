#include "Matrix.h"

template<class T>
Matrix<T>::Matrix(unsigned dim_x, unsigned dim_y): _dim_x(dim_x), _dim_y(dim_y)
{
	_inner.resize(dim_x * dim_y, 0);
}

template<class T>
unsigned Matrix<T>::GetDimX()
{
	return _dim_x;
}

template<class T>
unsigned Matrix<T>::GetDimY()
{
	return _dim_y;
}

template<class T>
const T& Matrix<T>::operator()(const unsigned x, const unsigned y)
{
	static_assert(x < _dim_x && y < _dim_y, "Matrix index out of range.");
	return _inner[x * _dim_x + y];
}

template<class T>
Matrix<T>::Matrix(const Matrix& mat): _dim_x(mat.GetDimX()), _dim_y(mat.GetDimY())
{
	// Copy constructor, dim set before	
    _inner.resize(_dim_x * _dim_y, 0);
    for (int i = 0; i < _dim_x; i++)
    {
        for (int  j = 0; j < _dim_y; j++)
        {
            _inner[i * _dim_x + j] = mat(i,j);
        }
    }
}

template<class T>
Matrix<T>::~Matrix()
{
	_inner.~vector();
}

