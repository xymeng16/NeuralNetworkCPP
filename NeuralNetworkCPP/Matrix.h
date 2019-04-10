#pragma once
#include <vector>
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

enum DataType
{
	UNKNOWN= -1, 
	UNSIGNED=0, // 00
	INT, // 01
	FLOAT, // 10
	DOUBLE, // 11
};
template <class T>
class Matrix
{
public:
	vector<T> _inner;
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

	Matrix(const vector<T> vec, unsigned dim_x, unsigned dim_y) :_dim_x(dim_x), _dim_y(dim_y)
	{
		if ((vec.size()) != (dim_x) * (dim_y))
		{
			throw length_error("The size of the vector doesn't match the input dimension.");
		}
		
		_inner.resize(dim_x * dim_y, 0);
		for (unsigned i = 0; i < _dim_x; i++)
		{
			for (unsigned j = 0; j < _dim_y; j++)
			{
				_inner[i * _dim_y + j] = vec[i * _dim_y + j];
			}
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

	const Matrix<double>& operator+ (const Matrix<T> mat)
	{
		if (mat.GetDimX() != this->GetDimX() || mat.GetDimY() != this->GetDimY())
		{
			throw length_error("Matrices should have same dimensions.");
		}
		// Decide the data type
		if (this->GetDataType() < 0 || mat.GetDataType() < 0)
		{
			throw logic_error("Matrices data type unknown");
		}

		Matrix<double> *result = new Matrix<double>(this->_dim_x, this->_dim_y);

		for (int i = 0; i < this->_dim_x; i++)
		{
			for (int j = 0; j < this->_dim_y; j++)
			{
				(*result)(i, j) = this->_inner[i*_dim_y + j] + mat(i, j);
			}
		}

		return *result;
	}
	friend const Matrix<double>& operator*(const double a, const Matrix<T>& mat)
	{
		Matrix<double>* result = new Matrix<double>(mat.GetDimX(), mat.GetDimY());
		unsigned x = mat.GetDimX(), y = mat.GetDimY();

		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				(*result)(i, j) = a * mat(i, j);
			}
		}

		return *result;
	}
	const Matrix<double>& operator*(const Matrix<int>& mat) const
	{
		if (this->_dim_y != mat.GetDimX())
		{
			throw length_error("Matrices size should be matched when multipling.");
		}
		Matrix<double>* result = new Matrix<double>(this->_dim_x, mat.GetDimY());

		for (int i = 0; i < this->_dim_x; i++)
		{
			for (int j = 0; j < mat.GetDimY(); j++)
			{
				for (int k = 0; k < this->_dim_y; k++)
				{
					(*result)(i, j) += (*this)(i, k) * mat(k, j);
				}
			}
		}

		return *result;
	}
	const Matrix<double>& operator*(const Matrix<double>& mat) const
	{
		if (this->_dim_y != mat.GetDimX())
		{
			throw length_error("Matrices size should be matched when multipling.");
		}
		Matrix<double>* result = new Matrix<double>(this->_dim_x, mat.GetDimY());

		for (int i = 0; i < this->_dim_x; i++)
		{
			for (int j = 0; j < mat.GetDimY(); j++)
			{
				for (int k = 0; k < this->_dim_y; k++)
				{
					(*result)(i, j) += (*this)(i, k) * mat(k, j);
				}
			}
		}

		return *result;
	}
	inline friend ostream& operator <<(ostream& out, const Matrix<T>& mat)
	{
		out << "[Matrix, type:" << const_cast<Matrix<T> &>(mat).GetDataTypeName() << ", size: " << mat.GetDimX() << "*" << mat.GetDimY() << "]" << endl;
		out << "[";
		unsigned x = mat.GetDimX(), y = mat.GetDimY();
		for (int i = 0; i < x; i++)
		{
			out << "[";
			for (int j = 0; j < y; j++)
			{
				cout << mat(i, j) << ", ";
			}
			out << "]," << endl;
		}
		out << "]" << endl;
		return out;
	}
	DataType GetDataType() const
	{
		string s(typeid(T).name());
		if (s == "unsigned int")
			return UNSIGNED;
		if (s == "int")
			return INT;
		if (s == "float")
			return FLOAT;
		if (s == "double")
			return DOUBLE;
		return UNKNOWN;
	}
	string GetDataTypeName() const
	{
		string typeName[4] = { "unsigned int", "int", "float", "double" };

		return typeName[this->GetDataType()];
	}
private:
	unsigned _dim_x, _dim_y;
	
};

