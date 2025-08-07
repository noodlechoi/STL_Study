#include <iostream>
#include <vector>
#include "MyContainer.h"
using namespace std;

int main()
{
	vector<int> v { 1, 2, 3, 4, 5 };

	cout << v.size() << endl;
	cout << v.capacity() << endl;

	cout << endl;

	MyVector mv{ 1, 2, 3, 4, 5 };
	cout << mv.Size() << endl;
	cout << mv.Capacity() << endl;

}