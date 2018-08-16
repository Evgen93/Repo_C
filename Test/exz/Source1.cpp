#include <iostream>
#include <fstream>
#include <ostream>
#include <istream>


//using namespace std;
// 1 \0
// 2 dest
// 3 delete
// 4 delstr
// 5 << nulp
// 6 >> nulp

using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;
using std::fstream;
using std::ifstream;
using std::ofstream;


class string
{
protected:
	unsigned int size;
	char* str;
public:
	string();
	virtual ~string() {}
	unsigned int GetSize();
	virtual void DelStr() = 0;
};
string::string()
{
	size = 0;
	str = nullptr;
}
unsigned int string::GetSize()
{
	return this->size;
}

class charString : public string
{
public:
	charString();
	charString(char* userStr);
	charString(charString const & obj);
	charString(charString const && obj);
	charString& operator=(charString const & obj);
	charString& operator=(charString const && obj);
	virtual ~charString() override;
	charString operator+(charString const & obj);
	charString& operator+=(charString const & obj);
	bool operator==(charString const & obj);
	bool operator!=(charString const & obj);
	friend ostream& operator << (std::ostream& out, const charString& obj);
	friend istream& operator >> (std::istream& in, charString& obj);
	friend ifstream& operator >> (std::ifstream& fout, charString& obj);
	friend ofstream& operator << (std::ofstream& fout, charString& obj);
	virtual void DelStr();
};
charString::charString()
{
	this->size = 1;
	this->str = new char[128];
	this->str[0] = '\0';
}
charString::charString(char* userStr)
{
	this->size = strlen(userStr) + 1;
	this->str = new char[this->size];
	strcpy_s(this->str, this->size, userStr);
	this->str[this->size - 1] = '\0';
}
charString::charString(charString const & obj)
{
	this->size = obj.size;
	this->str = new char[this->size];
	strcpy_s(this->str, this->size, obj.str);
}
charString::charString(charString const && obj)
{
	this->size = obj.size;
	this->str = new char[this->size];
	strcpy_s(this->str, this->size, obj.str);
}
void charString::DelStr()
{
	if (this->str != nullptr)
	{
		delete this->str;
	}
	this->size = 0;
	this->str = nullptr;
}
charString& charString::operator=(charString const & obj)
{
	this->size = obj.size;
	this->str = new char[this->size];
	strcpy_s(this->str, this->size, obj.str);
	return *this;
}
charString& charString::operator=(charString const && obj)
{
	this->size = obj.size;
	this->str = new char[this->size];
	strcpy_s(this->str, this->size, obj.str);
	return *this;
}
charString::~charString()
{
	if (this->str != nullptr)
	{
		delete[] this->str;
	}
}
charString charString::operator+(charString const & obj)
{
	unsigned int resSize = this->size + obj.size - 1; //com
	char* resStr = new char[resSize];
	strcpy_s(resStr, this->size, this->str);
	char* temp = &resStr[this->size - 1];
	strcpy_s(temp, obj.size, obj.str);
	charString res(resStr);
	return res;
}
charString& charString::operator+=(charString const & obj)
{
	*this = *this + obj;
	return *this;
}
bool charString::operator==(charString const & obj)
{
	if (!strcmp(this->str, obj.str)) //com
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool charString::operator!=(charString const & obj)
{
	if (strcmp(this->str, obj.str)) //com
	{
		return true;
	}
	else
	{
		return false;
	}
}
ostream& operator<< (ostream& out, const charString& obj)
{
	if (obj.str != nullptr)
	{
		out << obj.str;
		return out;
	}
	{
		out << "obj empty\0";
	}
}
istream& operator>> (istream& in, charString& obj)
{
	if (obj.str != nullptr)
	{
		in >> obj.str;
		obj.size = strlen(obj.str);
		return in;
	}
	else
	{
		obj.str = new char[128];
		in >> obj.str;
		obj.size = strlen(obj.str);
		return in;
	}
}
ifstream& operator>> (ifstream& fin, charString& obj)
{
	if (fin.is_open())
	{
		fin >> obj.str;
	}
	else
	{
		cout << "file is closed" << endl;
	}
	return fin;
}
ofstream& operator<< (ofstream& fout, charString& obj)
{
	if (fout.is_open())
	{
		fout << obj.str;
	}
	else
	{
		cout << "file is closed" << endl;
	}
	return fout;
}


class bitString : public charString
{
public:
	bitString();
	bitString(char* userStr);
	bitString(unsigned int userInt); //todo
	bitString(bitString const & obj);
	bitString& operator=(bitString const & obj);
	//virtual ~bitString() override;
	void InvStr();
	//bitString operator+(bitString const & obj);
	//bitString& operator+=(bitString const & obj);
	bool operator==(bitString const & obj);
	bool operator!=(bitString const & obj);
	friend std::ostream& operator<<(std::ostream& out, const bitString& obj);
	friend std::istream& operator >> (std::istream& in, bitString& obj);
	operator unsigned int();
private:
};

bitString::bitString()
{
	this->size = 0;
	this->str = new char[32];
	this->str[0] = '0';
}
bitString::bitString(char* userStr)
{
	this->size = strlen(userStr);
	if (size > 32)
	{
		DelStr();
		return;
	}
	this->str = new char[size + 1];
	this->size = size;
	this->str[this->size] = '\0';
	for (size_t i = 0; i < this->size; i++)
	{
		if (userStr[i] != '0' && userStr[i] != '1')
		{
			DelStr();
			break;
		}
		else
		{
			this->str[i] = userStr[i];
		}
	}
}
/*bitString::~bitString()
{
	if (this->str != nullptr)
	{
		delete[] this->str;
	}
}*/
bitString::bitString(unsigned int userInt) //todo
{
	
}
bitString::bitString(bitString const & obj)
{
	this->size = obj.size;
	this->str = new char[this->size];
	strcpy_s(this->str, this->size, obj.str);
}
bitString& bitString::operator=(bitString const & obj)
{
	this->size = obj.size;
	this->str = new char[this->size];
	strcpy_s(this->str, this->size, obj.str);
	return *this;
}
void bitString::InvStr()
{
	char temp;
	for (size_t i = 0; i < (this->size / 2); i++)
	{
		temp = this->str[i];
		this->str[i] = this->str[this->size - (i + 1)];
		this->str[this->size - (i + 1)] = temp;
	}
}
bool bitString::operator==(bitString const & obj)
{
	if (!strcmp(this->str, obj.str))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool bitString::operator!=(bitString const & obj)
{
	if (strcmp(this->str, obj.str))
	{
		return true;
	}
	else
	{
		return false;
	}
}
std::ostream& operator<<(std::ostream& out, const bitString& obj)
{
	if (obj.str != nullptr)
	{
		out << obj.str;
		return out;
	}
	else
	{
		out << "obj empty\0";
	}
}
std::istream& operator >> (std::istream& in, bitString& obj)
{
	if (obj.str != nullptr)
	{
		in >> obj.str;
		obj.size = strlen(obj.str);
		return in;
	}
	else
	{
		obj.str = new char[32];
		in >> obj.str;
		obj.size = strlen(obj.str);
		return in;
	}
}
bitString::operator unsigned int()
{
	unsigned int res = 0;
	unsigned int* arr = new unsigned[33];

	for (unsigned i = 32, j = 1; i > 0; i--, j += j)
	{
		arr[i] = j;
	}
	for (unsigned i = 32, j = (this->size - 1); i > (32 - this->size); i--, j--)
	{
		if (this->str[j] == '1')
		{
			res += arr[i];
		}
	}
	delete[] arr;
	return res;
}

void main()
{
	char* _a = new char[5];
	std::cin >> _a;

	bitString a(_a);

	cout << unsigned int(a) << endl;

	system("pause");
	return;
}