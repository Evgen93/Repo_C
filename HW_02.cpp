#include <iostream>
#include <string.h>

using namespace std;

class Str
{
private:
	static int count;
	int size;
	char* s;
public:
	Str() : Str(80) {}
	Str(int _size) : size(_size)
	{
		s = InitStr(size);
		count++;
	}
	Str(char* _s, int size)
	{
		count++;
		this->size = size;
		strcpy_s(s, size, _s);
	}
	~Str()
	{
		if (s != nullptr)
		{
			delete[] s;
		}
	}

	static void CountStr()
	{
		cout << "number of objects created: " << count << endl;
	}

	void SetStr(int _size)
	{
		size = _size;
		cout << "Enter string:" << endl;
		s = InitStr(size);
		gets_s(s, size);
	}

	void Print()
	{
		cout << s << endl;
	}
private:
	char* InitStr(int _size)
	{
		size = _size;
		return s = new char[size] {'\0'};
	}
};

int Str::count = 0;

void main()
{
	// онструктор по умолчанию
	Str s0;
	s0.Print();
	s0.CountStr();

	// онструктор дл€ создани€ строки произвольного размера
	Str s1(100);
	s1.Print();
	s1.CountStr();

	//»зменение строки
	s1.SetStr(128);
	s1.Print();

	// онструктор принимающий строку от пользовател€
	char* string = new char[128];
	cout << "Enter something:" << endl;
	gets_s(string, 128);
	Str s2(string, 128);
	s2.Print();
	s2.CountStr();
	system("pause");
	return;
}