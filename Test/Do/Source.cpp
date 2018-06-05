#include <iostream>

using namespace std;

class Date
{
public:
	Date() :Date(0,0,0){}
	Date(int day, int mounth, int year);
private:
	int day;
	int mounth;
	int year;
public:
	void SetDay();
	void SetMounth();
	void SetYear();
	void SetDate(int day, int mounth, int year);
	int GetDay();
	int GetMounth();
	int GetYear();
};

Date::Date(int day, int mounth, int year)
{
	this->day = day;
	this->mounth = mounth;
	this->year = year;
}
void Date::SetDay()
{
	cout << "Enter Day:" << endl;
	cin >> day;
}
void Date::SetMounth()
{
	cout << "Enter Mounth:" << endl;
	cin >> mounth;
}
void Date::SetYear()
{
	cout << "Enter Year:" << endl;
	cin >> year;
}
void Date::SetDate(int day, int mounth, int year)
{
	this->day = day;
	this->mounth = mounth;
	this->year = year;
}
int Date::GetDay()
{
	return day;
}
int Date::GetMounth()
{
	return mounth;
}
int Date::GetYear()
{
	return year;
}



class Reader
{
public:
	Reader() :Reader("John", "Wick", "Ivanovich", 23, 7, 1973) {}
	Reader(char* fname, char* lname, char* mname, int day, int mounth, int year);
	Reader(const Reader & obj);
	~Reader();

private:
	Date date;
	char** fio = new char*[3];
	//Book** bookList;
	char** bookList = new char*[20];
public:
	void GetFio();
	void GetDate();
	void SetDate(int day, int mounth, int year);
	void SetName(char* fname, char* lname, char* mname);
};

Reader::Reader(char* fname, char* lname, char* mname, int day, int mounth, int year)
{
	fio[0] = new char[sizeof(fname)];
	fio[1] = new char[sizeof(lname)];
	fio[2] = new char[sizeof(mname)];

	strcpy_s(fio[0], sizeof(fname), fname);
	strcpy_s(fio[1], sizeof(lname), lname);
	strcpy_s(fio[2], sizeof(mname), mname);

	date.SetDate(day, mounth, year);
}
Reader::Reader(const Reader & obj)
{
	this->fio = new char*[3];
	for (size_t i = 0; i < 3; i++)
	{
		fio[i] = new char[sizeof(obj.fio[i])];
		strcpy_s(fio[i], sizeof(obj.fio[i]), obj.fio[i]);
	}
}
Reader::~Reader()
{
	for (size_t i = 0; i < 3; i++)
	{
		if (fio[i] != nullptr)
		{
			delete[] fio[i];
		}
	}
}
void Reader::GetFio()
{
	for (size_t i = 0; i < 3; i++)
	{
		cout << fio[i] << " ";
	}
	cout << endl;
}
void Reader::GetDate()
{
	cout << date.GetDay() << " " << date.GetMounth() << " " << date.GetYear() << endl;
}
void Reader::SetDate(int day, int mounth, int year)
{
	date.SetDate(day, mounth, year);
}
void Reader::SetName(char* fname, char* lname, char* mname)
{
	for (size_t i = 0; i < 3; i++)
	{
		delete[] fio[i];
	}
	fio[0] = new char[sizeof(fname)];
	fio[1] = new char[sizeof(lname)];
	fio[2] = new char[sizeof(mname)];

	strcpy_s(fio[0], sizeof(fname), fname);
	strcpy_s(fio[1], sizeof(lname), lname);
	strcpy_s(fio[2], sizeof(mname), mname);
}

class Author
{
public:
	Author():Author("John", "Wick", "Ivanovich", 23, 7, 1973) {}
	Author(char* fname, char* lname, char* mname, int day, int mounth, int year);
	Author(const Reader & obj);
	~Author();

private:
	Date date;
	char** fio = new char*[3];

public:
	void GetFio();
	void GetDate();
	void SetDate(int day, int mounth, int year);
	void SetName(char* fname, char* lname, char* mname);
};

Author::Author(char* fname, char* lname, char* mname, int day, int mounth, int year)
{
	fio[0] = new char[sizeof(fname)];
	fio[1] = new char[sizeof(lname)];
	fio[2] = new char[sizeof(mname)];

	strcpy_s(fio[0], sizeof(fname), fname);
	strcpy_s(fio[1], sizeof(lname), lname);
	strcpy_s(fio[2], sizeof(mname), mname);

	date.SetDate(day, mounth, year);
}
Author::Author(const Reader & obj)
{
	this->fio = new char*[3];
	for (size_t i = 0; i < 3; i++)
	{
		fio[i] = new char[sizeof(obj.fio[i])];
		strcpy_s(fio[i], sizeof(obj.fio[i]), obj.fio[i]);
	}
}
Author::~Author()
{
	for (size_t i = 0; i < 3; i++)
	{
		if (fio[i] != nullptr)
		{
			delete[] fio[i];
		}
	}
}
void Author::GetFio()
{
	for (size_t i = 0; i < 3; i++)
	{
		cout << fio[i] << " ";
	}
	cout << endl;
}
void Author::GetDate()
{
	cout << date.GetDay() << " " << date.GetMounth() << " " << date.GetYear() << endl;
}
void Author::SetDate(int day, int mounth, int year)
{
	date.SetDate(day, mounth, year);
}
void Author::SetName(char* fname, char* lname, char* mname)
{
	for (size_t i = 0; i < 3; i++)
	{
		delete[] fio[i];
	}
	fio[0] = new char[sizeof(fname)];
	fio[1] = new char[sizeof(lname)];
	fio[2] = new char[sizeof(mname)];

	strcpy_s(fio[0], sizeof(fname), fname);
	strcpy_s(fio[1], sizeof(lname), lname);
	strcpy_s(fio[2], sizeof(mname), mname);
}

class Book
{
public:
	Book();
	Book(char* name, int year, Author author);
	~Book();

private:
	Author author;
	char* name;
	int year;
	//Reader* red;
public:

};

Book::Book()
{
}

Book::~Book()
{
}

void main()
{
	Reader red("Ad", "Fg", "Hj", 1, 2, 3);
	red.GetFio();
	red.GetDate();
	red.SetDate(3, 2, 1);
	red.SetName("a", "b", "c");
	red.GetFio();
	red.GetDate();
	system("pause");
	return;
}