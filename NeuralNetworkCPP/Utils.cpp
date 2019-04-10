#include <cmath>
#include "Utils.h"
#include <stdexcept>
#include <numeric>
#include <vector>
namespace NeuralNetworkCPP {
	Matrix<double> exp(Matrix<double> x)
	{
		Matrix<double>* result = new Matrix<double>(x.GetDimX(), x.GetDimY());
		return *result;
	}

	double sigmoid(double x)
	{
		return 1 / (1 + std::exp(-x));
	}

	double InnerProduct(Matrix<double> x, Matrix<double> y)
	{
		if ((x.GetDimX() * x.GetDimX()) != 1)
		{
			throw length_error("InnerProductError: The x dim should all be 1.");
		}
		return std::inner_product(std::begin(x._inner), std::end(x._inner), std::begin(y._inner), 0.0);
	}
}