#include "function.h"
#include <iostream>
#include <conio.h>

using namespace std;

void main()
{
	int n = 0;
	cout << "Enter size of array:" << endl;
	cin >> n;
	int* arrInt = new int[n];
	//double* arrDoub = new double[n];

	InArr(arrInt, n);
	OutArr(arrInt, n);
	cout << MinArr(arrInt, n) << endl;
	cout << MaxArr(arrInt, n) << endl;
	SortArr(arrInt, n);
	OutArr(arrInt, n);
	_getch();
}