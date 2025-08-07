//#include "MyContainer.h"
//
//template<class T>
//MyVector<T>::MyVector()
//{
//}
//
//template<class T>
//MyVector<T>::MyVector(std::initializer_list<T> list) : capacity{list.size()}
//{
//	data = new T[list.size()];
//	
//	for (auto it = list.begin(); it != list.end(); ++it) {
//		data[size++] = *it;
//	}
//}
//
//template<class T>
//MyVector<T>::~MyVector()
//{
//	delete[] data;
//}
//
//template<class T>
//T& MyVector<T>::operator[](int i)
//{
//	return data[i];
//}