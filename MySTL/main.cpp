#include <iostream>
#include <vector>
#include "MyContainer.h"
using namespace std;

int main()
{
	vector<int> v { 1, 2, 3, 4, 5 };

	cout << v.size() << endl;
	cout << v.capacity() << endl;

	cout << "vector 출력" << endl;
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << endl;
	}

	cout << endl;

	MyVector<int> mv{ 1, 2, 3, 4, 5 };
	cout << mv.Size() << endl;
	cout << mv.Capacity() << endl;
	cout << "MyVector 출력" << endl;
	for (int i = 0; i < mv.Size(); ++i) {
		cout << mv[i] << endl;
	}
}