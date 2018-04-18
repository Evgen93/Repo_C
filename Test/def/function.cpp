#include <iostream>
#include <time.h>

using namespace std;

void InArrInt(int arr[], int size) 
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}

void InArrDoub(double arr[], double size)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = (double)((rand() % 100)/100.0);
	}
}

void OutArrInt(int arr[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void OutArrDoub(double arr[], double size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int MinArrInt(int arr[], int size)
{
	int min = arr[0];
	for (size_t i = 1; i < size; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}

double MinArrDoub(double arr[], int size)
{
	double min = arr[0];
	for (size_t i = 1; i < size; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}

int MaxArrInt(int arr[], int size)
{
	int max = arr[0];
	for (size_t i = 1; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

double MaxArrDoub(double arr[], int size)
{
	double max = arr[0];
	for (size_t i = 1; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

void SortArrInt(int arr[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i + 1; j < size; j++)
		{
			int temp = 0;
			if (arr[i] > arr[j])
			{
				
			}
		}
	}
}