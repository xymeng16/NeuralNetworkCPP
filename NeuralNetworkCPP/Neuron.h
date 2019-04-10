#pragma once
#include "Matrix.h"
namespace NeuralNetworkCPP {
	class Neuron
	{
	public:
		Neuron(Matrix<double> weights, double bias);
		~Neuron();
		double FeedForward(Matrix<double> inputs);
	private:
		Matrix<double>* _weights;
		double _bias;
	};

}