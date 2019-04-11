#pragma once
#include <vector>
#include <memory>

using namespace std;

namespace NeuralNetworkCPP {
	template <class T>
	class Dumpling
	{
	public:
		///	@brief Not recommended, please use <code>Dumpling(const vector&lt;int&gt;&amp; shape)</code>.
		explicit Dumpling(const int num, const int channels, const int width, 
			const int height);
		
		explicit Dumpling(const vector<int>& shape);
		~Dumpling();

	protected:
		vector<int> _shape;
		// _data stores the batch data and the model parameters,
		// _grad stores the gradient in computation process
		double *_data, *_grad; 
	};
}