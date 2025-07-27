#include "MyContainer.h"

MyVector::MyVector()
{
}

MyVector::~MyVector()
{
	delete[] data;
}
