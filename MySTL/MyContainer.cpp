#include "MyContainer.h"

MyVector::MyVector()
{
}

MyVector::MyVector(std::initializer_list<int> list) : capacity{list.size()}
{
	data = new int[list.size()];
	
	for (auto it = list.begin(); it != list.end(); ++it) {
		data[size++] = *it;
	}
}

MyVector::~MyVector()
{
	delete[] data;
}
