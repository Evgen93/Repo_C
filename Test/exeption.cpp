#include <iostream>
#include <string>

using namespace std;

class exeptionMyArray
{
public:
	enum exeptionMyArrayType
	{
		UNKNOW_MY_ARR_EXEP = 0,
		INC_SIZE_MY_ARR_EXEP,
		INC_MEM_MY_ARR_EXEP,
		OUT_OF_INT_MY_ARR_EXEP
	};
private:
	exeptionMyArrayType exepType;
public:
	exeptionMyArray();
	exeptionMyArray(exeptionMyArrayType exepType);
	~exeptionMyArray();
	exeptionMyArrayType getExepType() const;
	void exepMess() const;
};

exeptionMyArray::exeptionMyArray()
{
	exepType = UNKNOW_MY_ARR_EXEP;
}
exeptionMyArray::exeptionMyArray(exeptionMyArrayType exepType)
{
	this->exepType = exepType;
}
exeptionMyArray::~exeptionMyArray()
{
	cout << "Exeption finish" << endl;
}
exeptionMyArray::exeptionMyArrayType exeptionMyArray::getExepType() const
{
	return exepType;
}
void exeptionMyArray::exepMess() const
{
	switch (exepType)
	{
	case exeptionMyArray::UNKNOW_MY_ARR_EXEP:
		cout << "Unkow error" << endl;
		break;
	case exeptionMyArray::INC_SIZE_MY_ARR_EXEP:
		cout << "Size error" << endl;
		break;
	case exeptionMyArray::INC_MEM_MY_ARR_EXEP:
		cout << "Memory error" << endl;
		break;
	case exeptionMyArray::OUT_OF_INT_MY_ARR_EXEP:
		cout << "Out of range error" << endl;
		break;
	default:
		cout << "Inc code error" << endl;
		break;
	}
}

class MyArray
{
private:
	int *mas;
	int size;
public:
	MyArray();
	MyArray(int *userMas, int userSize);
	MyArray(const MyArray & from);
	MyArray& operator=(const MyArray & right);
	MyArray operator+(const MyArray & right) const;
	void print() const;
	~MyArray();
};

MyArray::MyArray()
{
	mas = nullptr;
	size = 0;
}
MyArray::MyArray(int *userMas, int userSize)
{
	if (userMas <= 0 || userMas == nullptr)
	{
		mas = nullptr;
		size = 0;
	}
	else
	{
		size = userSize;
		mas = new int[size];
		for (size_t i = 0; i < size; i++)
		{
			mas[i] = userMas[i];
		}
	}
}
MyArray::~MyArray()
{
	if (mas != nullptr)
	{
		delete[] mas;
	}
}
MyArray::MyArray(const MyArray & from)
{
	if (from.size <= 0 || from.mas == nullptr)
	{
		this->mas = nullptr;
		this->size = 0;
	}
	else
	{
		this->size = from.size;
		this->mas = new int[this->size];
		for (size_t i = 0; i < this->size; i++)
		{
			this->mas[i] = from.mas[i];
		}
	}
}
MyArray& MyArray::operator=(const MyArray & right)
{
	if (this->mas != nullptr)
	{
		delete[] this->mas;
	}
	if (right.size <= 0 || right.mas == nullptr)
	{
		this->mas = nullptr;
		this->size = 0;
	}
	else
	{
		this->size = right.size;
		this->mas = new int[this->size];
		for (size_t i = 0; i < this->size; i++)
		{
			this->mas[i] = right.mas[i];
		}
	}
	return *this;
}
MyArray MyArray::operator+(const MyArray & right) const
{
	if (this->mas == nullptr || right.mas == nullptr)
	{
		throw exeptionMyArray(exeptionMyArray::exeptionMyArrayType::INC_MEM_MY_ARR_EXEP);
	}
	if (this->size != right.size || this->size <= 0 || right.size <=0)
	{
		throw exeptionMyArray(exeptionMyArray::exeptionMyArrayType::INC_SIZE_MY_ARR_EXEP);
	}
	

	int *tempMas = new int[this->size];
	for (size_t i = 0; i < this->size; i++)
	{
		if (this->mas[i] > 0 && right.mas[i] > 0)
		{
			if ((INT_MAX - this->mas[i]) < right.mas[i])
			{
				throw exeptionMyArray(exeptionMyArray::exeptionMyArrayType::OUT_OF_INT_MY_ARR_EXEP);
			}
		}
		else if (this->mas[i] < 0 && right.mas[i] < 0)
		{
			if ((INT_MAX - this->mas[i]) > right.mas[i])
			{
				throw exeptionMyArray(exeptionMyArray::exeptionMyArrayType::OUT_OF_INT_MY_ARR_EXEP);
			}
		}
		tempMas[i] = this->mas[i] + right.mas[i];

	}
	MyArray res(tempMas, this->size);
	delete[] tempMas;
	return res;
}
void MyArray::print() const
{	
	if (size <= 0 || mas == nullptr)
	{
		cout << "Mass empty" << endl;
	}
	else
	{
		for (size_t i = 0; i < size; i++)
		{
			cout << mas[i] << " ";
		}
		cout << endl;
	}
}

const int masSize = 10;
void main()
{
	int masA[masSize] = {2, -4, 6, -8, 10, -12, INT_MAX, INT_MIN};
	int masB[masSize] = {10, 10, 10, 20, 20, 20, 30, -30};
	//MyArray objA(masA, masSize), objB(masB, masSize);
	//MyArray objA(masA, 0), objB(masB, masSize);
	//MyArray objA(masA, masSize), objB(masB, masSize - 2);
	MyArray objA(nullptr, masSize), objB(nullptr, masSize);
	MyArray res;
	cout << "mas A:" << endl;
	objA.print();

	cout << "mas B:" << endl;
	objB.print();

	try
	{
		res = objA + objB;
	}
	catch (const exeptionMyArray& exep)
	{
		exep.exepMess();
	}
	catch (...)
	{
		cout << "catch(...)" << endl;
	}

	cout << "Res A+B:" << endl;
	res.print();

	system("pause");
	return;
}