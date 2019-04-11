#pragma once
#include <vector>
#include <memory>

using namespace std;

namespace NeuralNetworkCPP {

	template <class T>
	class Dumpling
	{
	public:
		///	<summary>
		/// @brief Not recommended, please use <code>Dumpling(const vector&lt;int&gt;&amp; shape)</code>.
		/// </summary>
		explicit Dumpling(const int num, const int channels, const int width, 
			const int height);
		explicit Dumpling(const vector<int>& size);
		
		/// <summary>
		/// @brief Not recommend, please use <code>Resize(const vector&lt;int&gt;&amp; size)</code>
		/// </summary>
		void Resize(const int num, const int channels, const int width,
			const int height);
		/// <summary>
		/// @brief Change the size of the dumpling and reallocate the memory
		/// </summary>
		/// <param name="size">The size of the dumpling that will be changed to.</param>
		void Resize(const vector<int>& size);
		void ResizeAs(const Dumpling& dumpling);

		inline const vector<int>& size() const { return _size; }
		~Dumpling();

	protected:
		vector<int> _size;
		// _data stores the batch data and the model parameters,
		// _grad stores the gradient in propagation process
		double *_data, *_grad; 
	};
}