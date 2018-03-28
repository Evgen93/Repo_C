#include "conio.h"
#include "iostream"
#include "time.h"

using namespace std;

//������ ������
double** CreateMatr(int sizeI, int sizeJ)
{
	double **ptr = nullptr;
	ptr = new double*[sizeI];
	for (int i = 0; i < sizeI; i++)
	{
		ptr[i] = new double[sizeJ];
	}
	return ptr;
}


//������������ ������
void DeleteMatr(double **ptr, int sizeI)
{
	for (int i = 0; i < sizeI; i++)
	{
		delete[] ptr[i];
	}
	delete[] ptr;
}

//����
void InputMatr(double **ptr, int sizeI, int sizeJ)
{
	for (int i = 0; i < sizeI; i++)
	{
		for (int j = 0; j < sizeJ; j++)
		{
			cout << "ptr[" << i << "][" << j << "] = ";
			cin >> ptr[i][j];
			cout << endl;
		}
	}
}

//�����
void OutputMatr(double **ptr, int sizeI, int sizeJ)
{
	for (int i = 0; i < sizeI; i++)
	{
		for (int j = 0; j < sizeJ; j++)
		{
			cout << ptr[i][j] << " ";
		}
		cout << endl;
	}
}

//random
void RandInMatr(double **ptr, int sizeI, int sizeJ)
{
	for (int i = 0; i < sizeI; i++)
	{
		for (int j = 0; j < sizeJ; j++)
		{
			ptr[i][j] = rand() % 10;
		}
	}
}

//����� ��������� ������
double SumRow(double **ptr, int NumRow, int sizeJ)
{
	double res = 0.0;
	for (int i = 0; i < sizeJ; i++)
	{
		res += ptr[NumRow][i];
	}
	return res;
}

//����� ��������� �������
double SumCol(double **ptr, int NumCol, int sizeI)
{
	double res = 0.0;
	for (int i = 0; i < sizeI; i++)
	{
		res += ptr[i][NumCol];
	}
	return res;
}

//����� min / max
double MinElement(double **ptr, int sizeI, int sizeJ)
{
	double min = ptr[0][0];
	for (size_t i = 0; i < sizeI; i++)
	{
		for (size_t j = 0; j < sizeJ; j++)
		{
			if (min > ptr[i][j])
			{
				min = ptr[i][j];
			}
		}
	}
	return min;
}

double MaxElement(double **ptr, int sizeI, int sizeJ)
{
	double max = ptr[0][0];
	for (size_t i = 0; i < sizeI; i++)
	{
		for (size_t j = 0; j < sizeJ; j++)
		{
			if (max < ptr[i][j])
			{
				max = ptr[i][j];
			}
		}
	}
	return max;
}

void main()
{
	srand(time(nullptr));

	double **ptr = nullptr;
	int sizeI = 3, sizeJ = 4;

	ptr = CreateMatr(sizeI, sizeJ);

	//InputMatr(ptr, sizeI, sizeJ);
	RandInMatr(ptr, sizeI, sizeJ);
	OutputMatr(ptr, sizeI, sizeJ);

	for (size_t i = 0; i < sizeI; i++)
	{
		cout << "Sum row #" << i << " = ";
		cout << SumRow(ptr, i, sizeJ) << endl;
	}

	for (size_t i = 0; i < sizeJ; i++)
	{
		cout << "Sum col #" << i << " = ";
		cout << SumCol(ptr, i, sizeI) << endl;
	}

	cout << "Min el = " << MinElement(ptr, sizeI, sizeJ) << endl;
	cout << "Max el = " << MaxElement(ptr, sizeI, sizeJ) << endl;

	DeleteMatr(ptr, sizeI);

	_getch();
}