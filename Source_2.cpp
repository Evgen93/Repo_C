#include <iostream>
#include <fstream>
#include <ostream>
#include <istream>

namespace ItStep
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::istream;
	using std::ostream;
	using std::fstream;
	using std::ifstream;
	using std::ofstream;

	class errorsInCharString
	{
	public:
		enum exeptionCharString
		{
			OUT_OF_STR_EXEP = 0,
			COMP_EMPTY_STR_EXEP,
			CONC_EMPTY_STR_EXEP,
			UNKNOW_EXEP
		};
	private:
		exeptionCharString exep;
	public:
		errorsInCharString();
		errorsInCharString(exeptionCharString exep);
		~errorsInCharString() = default;
		exeptionCharString getExepType() const;
		void exepMess() const;
	};

	errorsInCharString::errorsInCharString()
	{
		exep = UNKNOW_EXEP;
	}
	errorsInCharString::errorsInCharString(exeptionCharString _exep)
	{
		this->exep = _exep;
	}
	errorsInCharString::exeptionCharString errorsInCharString::getExepType() const
	{
		return exep;
	}
	void errorsInCharString::exepMess() const
	{
		switch (this->exep)
		{
		case ItStep::errorsInCharString::OUT_OF_STR_EXEP:
			cout << "out of line" << endl;
			break;
		case ItStep::errorsInCharString::COMP_EMPTY_STR_EXEP:
			cout << "attempt to compare blank lines or with an empty string" << endl;
			break;
		case ItStep::errorsInCharString::CONC_EMPTY_STR_EXEP:
			cout << "attempt to concatenate or add empty lines or with an empty string" << endl;
			break;
		default:
			cout << "unknow error" << endl;
			break;
		}
	}

	class errorsInBitString : public errorsInCharString
	{
	public:
		enum exeptionBitString
		{
			OUT_OF_STR_EXEP = 0,
			COMP_EMPTY_STR_EXEP,
			ADD_EMPTY_STR_EXEP,
			OUT_OF_UINT_EXEP,
			UNKNOW_EXEP
		};
	private:
		exeptionBitString exep;
	public:
		errorsInBitString();
		errorsInBitString(exeptionBitString exep);
		~errorsInBitString() = default;
		void exepMess() const;
		exeptionBitString getExepType() const;
	};

	errorsInBitString::errorsInBitString()
	{
		exep = UNKNOW_EXEP;
	}
	errorsInBitString::errorsInBitString(exeptionBitString exep)
	{
		this->exep = exep;
	}
	void errorsInBitString::exepMess() const
	{
		switch (this->exep)
		{
		case ItStep::errorsInBitString::OUT_OF_STR_EXEP:
			cout << "out of line" << endl;
			break;
		case ItStep::errorsInBitString::COMP_EMPTY_STR_EXEP:
			cout << "attempt to compare empty lines or with an empty string" << endl;
			break;
		case ItStep::errorsInBitString::ADD_EMPTY_STR_EXEP:
			cout << "attempt to concatenate or add empty lines or with an empty string" << endl;
			break;
		case ItStep::errorsInBitString::OUT_OF_UINT_EXEP:
			cout << "out of Uint" << endl;
			break;
		default:
			cout << "unknow error" << endl;
			break;
		}
	}
	errorsInBitString::exeptionBitString errorsInBitString::getExepType() const
	{
		return exep;
	}

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
		if (this->str == nullptr || obj.str == nullptr)
		{
			throw errorsInCharString(errorsInCharString::exeptionCharString::CONC_EMPTY_STR_EXEP);
		}
		else
		{
			unsigned int resSize = this->size + obj.size - 1;
			char* resStr = new char[resSize];
			strcpy_s(resStr, this->size, this->str);
			char* temp = &resStr[this->size - 1];
			strcpy_s(temp, obj.size, obj.str);
			charString res(resStr);
			return res;
		}
	}
	charString& charString::operator+=(charString const & obj)
	{
		*this = *this + obj;
		return *this;
	}
	bool charString::operator==(charString const & obj)
	{
		if (this->str == nullptr || obj.str == nullptr)
		{
			throw errorsInCharString(errorsInCharString::exeptionCharString::COMP_EMPTY_STR_EXEP);
		}
		else
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
	}
	bool charString::operator!=(charString const & obj)
	{
		if (this->str == nullptr || obj.str == nullptr)
		{
			throw errorsInCharString(errorsInCharString::exeptionCharString::COMP_EMPTY_STR_EXEP);
		}
		else
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
			obj.DelStr();
			obj.str = new char[128];
			in >> obj.str;
			obj.size = strlen(obj.str) + 1;
			obj.str[obj.size] = '\0';
			return in;
		}
		else
		{
			obj.str = new char[128];
			in >> obj.str;
			obj.size = strlen(obj.str) + 1;
			obj.str[obj.size] = '\0';
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
		bitString& operator=(bitString const && obj);
		virtual ~bitString() override;
		void InvStr();
		bitString operator+(bitString & obj);
		bitString& operator+=(bitString & obj);
		bool operator==(bitString const & obj);
		bool operator!=(bitString const & obj);
		friend std::ostream& operator<<(std::ostream& out, const bitString& obj);
		friend std::istream& operator >> (std::istream& in, bitString& obj);
		operator unsigned int() const;
	private:
	};

	bitString::bitString()
	{
		this->size = 1;
		this->str = new char[33];
		this->str[0] = '0';
	}
	bitString::bitString(char* userStr)
	{
		this->size = strlen(userStr) + 1;
		if (this->size > 33)
		{
			DelStr();
			return;
		}
		this->str = new char[this->size];
		for (size_t i = 0; i < (this->size - 1); i++)
		{
			if (userStr[i] != '0' && userStr[i] != '1')
			{
				DelStr();
				break;
			}
			else
			{
				this->str[i] = userStr[i];
				this->str[this->size - 1] = '\0';
			}
		}
	}
	bitString::~bitString()
	{
		if (this->str != nullptr)
		{
			delete[]this->str;
			this->str = nullptr;
		}
	}
	bitString::bitString(unsigned int userInt) //todo
	{
		this->str = new char[33];
		_itoa_s(userInt, this->str, 32, 2);
		this->size = strlen(this->str) + 1;
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
	bitString& bitString::operator=(bitString const && obj)
	{
		this->size = obj.size;
		this->str = new char[this->size];
		strcpy_s(this->str, this->size, obj.str);
		return *this;
	}
	void bitString::InvStr()
	{
		if (this->str != nullptr)
		{
			for (int i = 0; i < (this->size - 1); i++)
			{
				if (this->str[i] == '0')
				{
					this->str[i] = '1';
				}
				else
				{
					this->str[i] = '0';
				}
			}
		}
	}
	bitString bitString::operator+(bitString & obj)
	{
		if (this->str == nullptr || obj.str == nullptr)
		{
			throw errorsInBitString(errorsInBitString::exeptionBitString::ADD_EMPTY_STR_EXEP);
		}
		else
		{
			if ((UINT_MAX - unsigned int(*this)) < unsigned int(obj))
			{
				throw errorsInBitString(errorsInBitString::exeptionBitString::OUT_OF_UINT_EXEP);
			}
			else
			{
				unsigned int resUint = unsigned int(*this) + unsigned int(obj);
				bitString res(resUint);
				return res;
			}
		}
	}
	bitString& bitString::operator+=(bitString & obj)
	{
		unsigned int resUint = unsigned int(*this) + unsigned int(obj);
		bitString res(resUint);
		*this = res;
		return *this;
	}
	bool bitString::operator==(bitString const & obj)
	{
		if (this->str == nullptr || obj.str == nullptr)
		{
			throw errorsInBitString(errorsInBitString::exeptionBitString::COMP_EMPTY_STR_EXEP);
		}
		else
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
	}
	bool bitString::operator!=(bitString const & obj)
	{
		if (this->str == nullptr || obj.str == nullptr)
		{
			throw errorsInBitString(errorsInBitString::exeptionBitString::COMP_EMPTY_STR_EXEP);
		}
		else
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
	}
	std::ostream& operator<< (std::ostream& out, const bitString& obj)
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
	std::istream& operator>> (std::istream& in, bitString& obj)
	{
		if (obj.str != nullptr)
		{
			in >> obj.str;
			obj.size = strlen(obj.str) + 1;
			obj.str[obj.size] = '\0';
			return in;
		}
		else
		{
			obj.str = new char[32];
			in >> obj.str;
			obj.size = strlen(obj.str) + 1;
			obj.str[obj.size] = '\0';
			return in;
		}
	}
	bitString::operator unsigned int() const
	{
		if (this->size > 33)
		{
			throw errorsInBitString(errorsInBitString::exeptionBitString::OUT_OF_UINT_EXEP);
		}
		else
		{
			if (this->str != nullptr)
			{
				unsigned int res = 0;
				unsigned int* arr = new unsigned[33];

				for (unsigned i = 32, j = 1; i > 0; i--, j += j)
				{
					arr[i] = j;
				}
				for (unsigned i = 33, j = (this->size - 1); i > (33 - this->size); i--, j--)
				{
					if (this->str[j] == '1')
					{
						res += arr[i];
					}
				}
				delete[] arr;
				return res;
			}
		}
	}
}



using namespace ItStep;

void main()
{
	//regular work with the class charString:

	cout << "Class CharString:" << endl;
	charString cStrF;
	charString cStrS;

	cout << "Enter first string:" << endl;
	cin >> cStrF;
	cout << "Enter second string:" << endl;
	cin >> cStrS;

	cout << "Output string:" << endl;
	cout << cStrF << endl;
	cout << cStrS << endl;

	cout << "Concatenation and assignment (operators + and =):" << endl;
	charString cRes = cStrF + cStrS;
	cout << cRes << endl;

	cout << "Concatenation and assignment (operator+=):" << endl;
	cRes += cStrF;
	cout << cRes << endl;

	cout << "operator==:" << endl;
	cout << (cStrF == cStrS) << endl;

	cout << "operator!=:" << endl;
	cout << (cStrF != cStrS) << endl;

	//exeption charString:

	cout << endl << endl;
	cStrF.DelStr();
	try
	{
		cStrF + cStrS;
	}
	catch(const errorsInCharString& exep)
	{
		exep.exepMess();
	}

	try
	{
		cStrF == cStrS;
	}
	catch (const errorsInCharString& exep)
	{
		exep.exepMess();
	}

	//regular work with the class charString:

	cout << "Class BitString:" << endl;
	bitString bStrF;
	cout << "Enter first bit string:" << endl;
	cin >> bStrF;
	cout << "Enter unsinned int:" << endl;
	unsigned i;
	cin >> i;
	bitString bStrS(i);

	cout << "Output bit string:" << endl;
	cout << bStrF << endl;
	cout << bStrS << endl;

	cout << "inverting of bit string:" << endl;
	bStrF.InvStr();
	cout << bStrF << endl;

	cout << "operators + and =:" << endl;
	bitString res = bStrF + bStrS;
	cout << res << endl;

	cout << "operators += :" << endl;
	cout << (res += bStrF) << endl;

	cout << "operator==:" << endl;
	cout << (bStrF == bStrS) << endl;

	cout << "operator!=:" << endl;
	cout << (bStrF != bStrS) << endl;

	//exeption bitString:
	cout << endl << endl;
	bStrF.DelStr();
	try
	{
		bStrF + bStrS;
	}
	catch (const errorsInBitString& exep)
	{
		exep.exepMess();
	}

	bitString a("11111111111111111111111111111111");
	bitString b("11111111111111111111111111111111");

	try
	{
		a + b;
	}
	catch (const errorsInBitString& exep)
	{
		exep.exepMess();
	}

	system("pause");
	return;
}
