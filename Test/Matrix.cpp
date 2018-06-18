#include <iostream>

using namespace std;

class Matrix
{
private:
	int** arr;
	int sizeI;
	int sizeJ;
public:

	Matrix(): Matrix(3, 3){}
	Matrix(int sizeI, int sizeJ)
	{
		this->sizeI = sizeI;
		this->sizeJ = sizeJ;
		arr = new int*[sizeI];

		for (size_t i = 0; i < sizeI; i++)
		{
			arr[i] = new int[sizeJ];
			for (size_t j = 0; j < sizeJ; j++)
			{
				arr[i][j] = 0;
			}
		}
	}
	Matrix(const Matrix & obj)
	{
		this->sizeI = obj.sizeI;
		this->sizeJ = obj.sizeJ;

		this->arr = new int*[sizeI];
		for (size_t i = 0; i < sizeI; i++)
		{
			this->arr[i] = new int[sizeJ];
			for (size_t j = 0; j < sizeJ; j++)
			{
				arr[i][j] = obj.arr[i][j];
			}
		}
	}
	~Matrix()
	{
		if (arr != nullptr)
		{
			for (size_t i = 0; i < sizeI; i++)
			{
				if (arr[i] != nullptr)
				{
					delete[] arr[i];
				}
			}
			delete[] arr;
		}
	}

	void InArr()
	{
		for (size_t i = 0; i < sizeI; i++)
		{
			for (size_t j = 0; j < sizeJ; j++)
			{
				cout << "Enter " << i << j << " num:" << endl;
				cin >> arr[i][j];
			}
		}
	}

	void Print() const
	{
		for (size_t i = 0; i < sizeI; i++)
		{
			for (size_t j = 0; j < sizeJ; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}

	void Resize(int sizeI, int sizeJ)
	{
		if (arr != nullptr)
		{
			for (size_t i = 0; i < this->sizeI; i++)
			{
				if (arr[i] != nullptr)
				{
					delete[] arr[i];
				}
			}
			delete[] arr;
		}
		this->sizeI = sizeI;
		this->sizeJ = sizeJ;
		arr = new int*[sizeI];
		for (size_t i = 0; i < sizeI; i++)
		{
			arr[i] = new int[sizeJ];
			for (size_t j = 0; j < sizeJ; j++)
			{
				arr[i][j] = 0;
			}
		}
	}

	int FindMin()
	{
		int min = arr[0][0];
		for (size_t i = 0; i < sizeI; i++)
		{
			for (size_t j = 0; j < sizeJ; j++)
			{
				if (min > arr[i][j])
				{
					min = arr[i][j];
				}
			}
		}
		return min;
	}

	int FindMax()
	{
		int max = arr[0][0];
		for (size_t i = 0; i < sizeI; i++)
		{
			for (size_t j = 0; j < sizeJ; j++)
			{
				if (max < arr[i][j])
				{
					max = arr[i][j];
				}
			}
		}
		return max;
	}

	void Sort()
	{
		int temp = 0;
		for (size_t c = 0; c < sizeJ * sizeI; c++)
		{
			for (size_t i = 0; i < sizeI; i++)
			{
				for (size_t j = sizeJ - 1; j > 0; j--)
				{
					if (arr[i][j - 1] > arr[i][j])
					{
						temp = arr[i][j];
						arr[i][j] = arr[i][j - 1];
						arr[i][j - 1] = temp;
					}
				}
				if (i < sizeI - 1)
				{
					if (arr[i][sizeJ - 1] > arr[i + 1][0])
					{
						temp = arr[i + 1][0];
						arr[i + 1][0] = arr[i][sizeJ - 1];
						arr[i][sizeJ - 1] = temp;
					}
				}
			}
		}

		int** tempArr = new int*[sizeI];
		for (size_t i = 0; i < sizeI; i++)
		{
			tempArr[i] = new int[sizeJ];
			for (size_t j = 0; j < sizeJ; j++)
			{
				tempArr[i][j] = 0;
			}
		}

		for (size_t i = 0; i < sizeI; i++)
		{
			for (size_t j = 0; j < sizeJ; j++)
			{

			}
		}
	}

	Matrix operator+(const Matrix & mat)
	{
		int newSizeI, newSizeJ;
		if (this->sizeI != mat.sizeI || this->sizeJ != mat.sizeJ)
		{
			cout << "Matrices have different sizes" << endl;
			if (this->sizeI > mat.sizeI)
			{
				newSizeI = mat.sizeI;
			}
			else
			{
				newSizeI = this->sizeI;
			}

			if (this->sizeJ > mat.sizeJ)
			{
				newSizeJ = mat.sizeJ;
			}
			else
			{
				newSizeJ = this->sizeJ;
			}
		}
		else
		{
			newSizeI = this->sizeI;
			newSizeJ = this->sizeJ;
		}
		Matrix res(newSizeI, newSizeJ);
		for (size_t i = 0; i < newSizeI; i++)
		{
			for (size_t j = 0; j <newSizeJ; j++)
			{
				res.arr[i][j] = (this->arr[i][j] + mat.arr[i][i]);
			}
		}
		return res;
	}

	Matrix operator-(const Matrix & mat)
	{
		int newSizeI, newSizeJ;
		if (this->sizeI != mat.sizeI || this->sizeJ != mat.sizeJ)
		{
			cout << "Matrices have different sizes" << endl;
			if (this->sizeI > mat.sizeI)
			{
				newSizeI = mat.sizeI;
			}
			else
			{
				newSizeI = this->sizeI;
			}

			if (this->sizeJ > mat.sizeJ)
			{
				newSizeJ = mat.sizeJ;
			}
			else
			{
				newSizeJ = this->sizeJ;
			}
		}
		else
		{
			newSizeI = this->sizeI;
			newSizeJ = this->sizeJ;
		}
		Matrix res(newSizeI, newSizeJ);
		for (size_t i = 0; i < newSizeI; i++)
		{
			for (size_t j = 0; j <newSizeJ; j++)
			{
				res.arr[i][j] = (this->arr[i][j] - mat.arr[i][i]);
			}
		}
		return res;
	}

	Matrix operator*(const Matrix & mat)
	{
		int newSizeI, newSizeJ;
		newSizeI = this->sizeI;
		newSizeJ = mat.sizeJ;
		Matrix res(newSizeI, newSizeJ);
		int temp = 0;

		for (size_t i = 0; i < newSizeI; i++)
		{
			for (size_t j = 0; j < newSizeJ; j++)
			{
				for (size_t a = 0; a < sizeI; a++)
				{
					temp += this->arr[i][a] * mat.arr[a][i];
				}
				res.arr[i][j] = temp;
				temp = 0;
			}
		}
		return res;
	}

	Matrix& operator=(const Matrix & mat)
	{
		if (this->arr != nullptr)
		{
			for (size_t i = 0; i < sizeI; i++)
			{
				if (this->arr[i] != nullptr)
				{
					delete[] this->arr[i];
				}
			}
			delete[] this->arr;
		}

		this->arr = new int*[sizeI];
		for (size_t i = 0; i < sizeI; i++)
		{
			this->arr[i] = new int[sizeJ];
		}

		for (size_t i = 0; i < sizeI; i++)
		{
			for (size_t j = 0; j < sizeJ; j++)
			{
				this->arr[i][j] = mat.arr[i][j];
			}
		}
		return *this;
	}

	
};

void main()
{
	Matrix mat(3, 2);
	Matrix tam(2, 3);
	Matrix res(2, 2);
	mat.InArr();
	tam.InArr();
	mat.Print();
	tam.Print();
	cout << endl;
	res = mat * tam;
	res.Print();
	system("pause");
	return;
}