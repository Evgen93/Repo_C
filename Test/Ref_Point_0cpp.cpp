#include "conio.h"
#include "iostream"
#include "ctime"
#define N 5

using namespace std;

//void Fun(int varI, double varD);
void Fun(int *ptrArr, double *ptrVar, int size = N);
void Fun(int varI, double varD);
void FunStatic(int (&refInt)[N], double &refVar, int size = N);
void FunPtr(int* &refInt, double &refVar, int size = N);

void main()
{
	srand(time(0));
	double userD = 5.5;
	int userI = 10;

	// Передача аргументов в функию по значению

	Fun(userI, userD);

	// Передача аргументов в функцию через указатели

	int arr[N] = {1, 2, 3, 4, 5};
	double num = 1.1;
	int *ptrA = new int[N];
	double *ptrD = new double(1.2);
	for (int i = 0; i < N; i++)
	{
		ptrA[i] = rand() % 10;
	}
	cout << "First" << endl;
	Fun(arr, &num);
	cout << num << endl;
	cout << "Main" << endl;
	Fun(ptrA, ptrD);
	cout << *ptrD << endl;

	// Передача аргументов в функцию через ссылки

	int mass[N] = { 1,2,3,4,5 };
	double varD = 5.5;
	int *ptrM = new int[N];
	double *ptr = new double(1.2);
	for (int i = 0; i < N; i++)
	{
		ptrM[i] = rand() % 10;
	}

	FunStatic(mass, varD);
	cout << varD << endl;

	int* &ref = ptrM;
	FunPtr(ref, *ptr);
	cout << *ptr << endl;

	_getch();
}

void Fun(int varI, double varD)
{
	cout << varI << endl;
	cout << varD << endl;
	return;
}

void Fun(int *ptrArr, double *ptrVar, int size)
{
	cout << "Arr: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << ptrArr[i] << " ";
	}
	cout << endl;
	cout << *ptrVar << endl;
	(*ptrVar)++;
	return;
}

void FunStatic(int(&refInt)[N], double &refVar, int size)
{
	cout << "Array: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << refInt[i] << " ";
	}
	cout << endl;
	cout << "Var: " << refVar << endl;
	refVar++;
	return;
}

void FunPtr(int* &refInt, double &refVar, int size)
{
	cout << "Array: " << endl;
	for (int o = 0; o < size; o++)
	{
		cout << refInt[o] << " ";
	}
	cout << endl;
	cout << "Var: " << refVar << endl;
	refVar++;
	return;
}