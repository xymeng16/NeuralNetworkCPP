#pragma once
#include "Matrix.h"
namespace NeuralNetworkCPP {
	Matrix<double> exp(Matrix<double> x);
	double sigmoid(double x);
	double InnerProduct(Matrix<double> x, Matrix<double> y);
}