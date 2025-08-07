#pragma once
#include <initializer_list>

class MyVector
{
public:
	MyVector();
	MyVector(std::initializer_list<int> list);
	~MyVector();

	size_t Size() const { return size; }
	size_t Capacity() const { return capacity; }
private:
	int* data{};
	size_t size{};
	size_t capacity{};
};

