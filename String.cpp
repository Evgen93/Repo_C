#include <iostream>
#include <conio.h>

using namespace std;

class myString
{
private:
	char* str;
	int size;
public:
	myString():myString("test", 4) {}
	myString(char* str, int size)
	{
		this->size = size + 1;
		this->str = new char[this->size];
		strcpy_s(this->str, this->size, str);
	}
	myString(const myString & obj)
	{
		this->size = obj.size;
		this->str = new char[size];
		strcpy_s(this->str, size, obj.str);
	}
	myString(const myString && obj)
	{
		this->size = obj.size;
		this->str = new char[size];
		strcpy_s(this->str, size, obj.str);
	}
	myString& operator=(const myString & obj)
	{
		this->size = obj.size;
		this->str = new char[size];
		strcpy_s(this->str, size, obj.str);
		return *this;
	}
	myString& operator=(const myString && obj)
	{
		this->size = obj.size;
		this->str = new char[size];
		strcpy_s(this->str, size, obj.str);
		return *this;
	}
	~myString()
	{
		if (this->str != nullptr)
		{
			delete[] str;
		}
	}

	myString operator+(const myString & obj)
	{
		int sizeNew = this->size + obj.size - 1;
		char* s = new char[sizeNew];
		int i = 0;
		for (i; i < this->size - 1; i++)
		{
			s[i] = this->str[i];
		}
		for (size_t j = i, a = 0; j < sizeNew; j++, a++)
		{
			s[j] = obj.str[a];
		}
		//s[sizeNew] = '\0';
		myString temp(s, sizeNew);
		delete[] s;
		return temp;
	}

	myString operator*(const myString & obj)
	{
		int sizeNew = this->size + obj.size;
		char* temp = new char[sizeNew];
		int c = 0;
		for (size_t i = 0; i < this->size; i++)
		{
			for (size_t j = 0; j < obj.size; j++)
			{
				if (this->str[i] == obj.str[j])
				{
					temp[c] = str[i];
					c++;
					break;
				}
			}
		}
		char* res = new char[c];
		strcpy_s(res, c, temp);
		myString result(res, c);
		delete[] res;
		delete[] temp;
		return result;
	}

	bool operator==(const myString & obj)
	{
		if (this->size != obj.size)
		{
			return false;
		}
		
		for (size_t i = 0; i < this->size; i++)
		{
			if (this->str[i] != obj.str[i])
			{
				return false;
			}
		}
		return true;
	}

	bool operator>(const myString & obj)
	{
		char* a = new char[this->size];
		strcpy_s(a, this->size, this->str);
		char* b = new char[obj.size];
		strcpy_s(a, obj.size, obj.str);

		int i = 0;
		int j = 0;
		while ((i < this->size - 1) && (i < obj.size))
		{

		}

		if (this->size > obj.size)
		{
			return false;
		}
		else if(this->size < obj.size)
		{ 
			return false;
		}

		for (size_t i = 0; i < this->size; i++)
		{
			if (this->str[i] < obj.str[i])
			{
				return true;
			}
			else if (this->str[i] > obj.str[i])
			{
				return false;
			}
		}
		return false;
	}

	void Print()
	{
		cout << this->str << endl;
	}
};

void main()
{
	myString objA("aa", 2);
	myString objB("aa", 2);

	//myString objRes = objA + objB;
	//objRes.Print();
	//myString Res = objA * objB;
	//Res.Print();

	//cout << (objA == objB);
	cout << (objA > objB);
	system("pause");
	return;
}