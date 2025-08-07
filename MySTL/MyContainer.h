#pragma once
#include <initializer_list>

template<class T>
class MyVector
{
public:
	MyVector();
	MyVector(std::initializer_list<T> list);
	~MyVector();

	T& operator[](int i);

	size_t Size() const { return size; }
	size_t Capacity() const { return capacity; }
private:
	T* data{};
	size_t size{};
	size_t capacity{};
};

template<class T>
MyVector<T>::MyVector()
{
}

template<class T>
MyVector<T>::MyVector(std::initializer_list<T> list) : capacity{ list.size() }
{
	data = new T[list.size()];

	for (auto it = list.begin(); it != list.end(); ++it) {
		data[size++] = *it;
	}
}

template<class T>
MyVector<T>::~MyVector()
{
	delete[] data;
}

template<class T>
T& MyVector<T>::operator[](int i)
{
	return data[i];
}