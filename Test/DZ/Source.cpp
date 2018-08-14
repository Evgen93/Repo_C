#include <iostream>
#include <string>
#include <memory>
#include <fstream>


using namespace std;

class fileWork
{
private:
	fstream file;
	string way;
public:
	fileWork() = delete;
	fileWork(string way);
	fileWork(const fileWork & from);
	fileWork(const fileWork && from);
	fileWork& operator=(const fileWork & from);
	fileWork& operator=(const fileWork && from);
	~fileWork();

	void FindStr(string find);
	bool SubStr(string find, string sub);
	void PrintFile();
	void Reverce();
};

fileWork::fileWork(string way)
{
	this->way = way;
	file.open(way, ios::in | ios::out);
}
fileWork::fileWork(const fileWork & from)
{
	if (this->file.is_open())
	{
		this->file.close();
	}
	this->file.open(from.way, ios::in | ios::out);
}
fileWork::fileWork(const fileWork && from)
{
	if (this->file.is_open())
	{
		this->file.close();
	}
	this->file.open(from.way, ios::in | ios::out);
}
fileWork& fileWork::operator=(const fileWork & from)
{
	if (this->file.is_open())
	{
		this->file.close();
	}
	this->file.open(from.way, ios::in | ios::out);
	return *this;
}
fileWork& fileWork::operator=(const fileWork && from)
{
	if (this->file.is_open())
	{
		this->file.close();
	}
	this->file.open(from.way, ios::in | ios::out);
	return *this;
}
fileWork::~fileWork()
{
	this->file.close();
}

void fileWork::PrintFile()
{
	string out = " ";
	while (!file.eof())
	{
		getline(this->file, out);
		cout << out << endl;
	}
	file.seekg(0, ios_base::beg);
}
void fileWork::FindStr(string find)
{
	string temp;
	int i = 0;
	bool _find = false;
	while (!file.eof())
	{
		getline(this->file, temp);
		if (temp == find)
		{
			_find = true;
			cout << '"' << find << '"' << " - found in line #" << i + 1 << endl;
		}
		i++;
	}
	if (!_find)
	{
		cout << "string not found" << endl;
	}
	file.seekg(0, ios_base::beg);
}
bool fileWork::SubStr(string find, string sub)
{
	string temp;
	int i = 0;
	bool _find = false;
	while (!file.eof())
	{
		getline(this->file, temp);
		if (temp == find)
		{
			_find = true;
			cout << '"' << find << '"' << " - sub in line #" << i + 1 << endl;
		}
		i++;
	}
	if (!_find)
	{
		cout << "string not found" << endl;
		file.seekg(0, ios_base::beg);
		return false;
	}
	else
	{
		file.seekg(0, ios_base::beg);
		return true;
	}
	
}
void fileWork::Reverce()
{

}

void main()
{
	fileWork file("Text.txt");
	file.PrintFile();
	cout << endl;
	file.FindStr("11111");
	//file.SubStr("11111", "000");
	//file.PrintFile();
	system("pause");
	return;
}