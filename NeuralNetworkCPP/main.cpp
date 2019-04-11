#include <iostream>
#include <vector>
#include "Matrix.h"
#include "Neuron.h"

using namespace std;
using namespace NeuralNetworkCPP;

int main()
{
	//Matrix<int> mat(1, 2);
	//mat(0, 0) = 3;
	//Matrix<int> mat2(1,2);
	//Matrix<double> mat3(2, 1);
	//mat3(0, 0) = 3;
	//Matrix<double> mat4(1, 2);
	//cout << mat.GetDimX() << mat2.GetDimY() << endl;
	//cout << mat(0, 0) << " " << mat2(0, 0) << endl;
	//mat2(0, 0) = 33;
	//cout << mat(0, 0) << " " << mat2(0, 0) << endl;
	//// cout << typeid(mat(0,0)).name() << " " << typeid(mat2(0, 0)).name() << " " << typeid(mat3(0, 0)).name() << " " << typeid(mat4(0, 0)).name();
	//cout << mat << mat2 << mat3 << mat + mat2 << 2.4 * (mat2 + mat) << 1.2 * mat * mat3;
	
	/*double wei_arr[] = { 0, 1 }, x_arr[] = { 2, 3 };
	vector<double> weights(wei_arr, wei_arr + sizeof(wei_arr)/sizeof(wei_arr[0])), \
		inputs(x_arr, x_arr+sizeof(x_arr)/sizeof(x_arr[0]));
	Neuron neuron(Matrix<double>(weights, 1, 2), 4);
	cout << neuron.FeedForward(Matrix<double>(inputs, 1, 2));*/
	return 0;
}