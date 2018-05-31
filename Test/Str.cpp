#include <iostream>

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
	Str(char* _s)
	{
		count++;
		size = sizeof(_s);
		s = _s;
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
	// Первый конструктор
	Str* s1 = nullptr;
	s1 = new Str();
	s1->Print();

	Str::CountStr();

	s1->SetStr(80);
	s1->Print(); 

	// Второй конструктор
	Str* s2 = nullptr;
	s2 = new Str();
	s2->Print();

	Str::CountStr();

	s2->SetStr(10);
	s2->Print();

	// Третий конструктор
	Str* s3 = nullptr;
	s3 = new Str("asd");
	s3->Print();

	s3->SetStr(10);
	s3->Print();
	system("pause");
	return;
}