#include "Neuron.h"
#include "Utils.h"


Neuron::Neuron(Matrix<double> weights, double bias) : _bias(bias)
{
	_weights = new Matrix<double>(weights);
}


Neuron::~Neuron()
{
	delete _weights;
}

double Neuron::FeedForward(Matrix<double> inputs)
{
	double total;
	return sigmoid(InnerProduct(inputs, *(this->_weights))+_bias);
}
