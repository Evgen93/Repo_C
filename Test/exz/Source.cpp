#include <iostream>

//using namespace std;
// 1 \0
// 2 dest
// 3 delete
// 4 delstr
// 5 << nulp
// 6 >> nulp

class string
{
protected:
	unsigned int size;
	char* str;
public:
	string();
	virtual ~string();
	unsigned int GetSize();
	virtual void DelStr() = 0;
};
string::string()
{
	size = 0;
	str = nullptr;
}
string::~string()
{
	if (this->str != nullptr)
	{
		delete[] this->str;
	}
}
unsigned int string:: GetSize()
{
	return this->size;
}


class charString : public string
{
public:
	charString();
	charString(char* userStr);
	charString(charString const & obj);

	charString& operator=(charString const & obj);
	~charString(); //virt? todo
	charString operator+(charString const & obj);
	charString& operator+=(charString const & obj);
	bool operator==(charString const & obj);
	bool operator!=(charString const & obj);
	friend std::ostream& operator<<(std::ostream& out, const charString& obj);
	friend std::istream& operator>>(std::istream& in, charString& obj);
	virtual void DelStr();
};
charString::charString()
{
	this->size = 0;
	this->str = new char[128];
	this->str[0] = '\0';
}
charString::charString(char* userStr)
{
	this->size = strlen(userStr);
	this->str = new char[this->size];
	strcpy_s(this->str, this->size, userStr);
}
charString::charString(charString const & obj)
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
std::ostream& operator<<(std::ostream& out, const charString& obj)
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
std::istream& operator>>(std::istream& in, charString& obj)
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


class bitString : public charString
{
public:
	bitString();
	bitString(char* userStr, int size);
	bitString(unsigned int userInt); //todo
	bitString(bitString const & obj);
	bitString& operator=(bitString const & obj);
	//~bitString();
	void InvStr();
	//bitString operator+(bitString const & obj);
	//bitString& operator+=(bitString const & obj);
	bool operator==(bitString const & obj);
	bool operator!=(bitString const & obj);
	friend std::ostream& operator<<(std::ostream& out, const bitString& obj);
	friend std::istream& operator>>(std::istream& in, bitString& obj);
	operator unsigned int();
private:
	//int GetSizeOfInt(unsigned int size);
};

bitString::bitString()
{
	this->size = 0;
	this->str = new char[32];
	this->str[0] = '0';
}
bitString::bitString(char* userStr, int size)
{
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
bitString::bitString(unsigned int userInt) //todo
{
	//itoa(userInt, this->str, 2);
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
std::istream& operator>>(std::istream& in, bitString& obj)
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
	unsigned int* arr = new unsigned[32];

	for (unsigned i = 32, j = 1; i > 0; i--, j+=j)
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
	//delete[] arr;
	return res;
}

void main()
{
	charString a;
	std::cin >> a;
	std::cout << (a + a) << std::endl;
	system("pause");
	return;
}