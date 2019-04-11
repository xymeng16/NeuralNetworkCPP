#pragma once
namespace NeuralNetworkCPP {
	template <class T>
	class BaseLayer
	{
	public:
		virtual ~BaseLayer()=0;
	protected:
		inline BaseLayer();
	};
}

