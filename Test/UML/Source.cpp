#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>

int main()
{
	setlocale(LC_ALL, "Rus");
	std::ifstream file;
	std::ofstream ResFile;
	file.open("Text.txt", std::ios::out);
	ResFile.open("ResFile.txt", std::ios::in);
	if (!file.is_open() && !ResFile.is_open())
	{
		return -1;
	}
	std::string str;
	std::string tempStr;
	std::map<std::string, int> dict;
	while (file >> str)
	{
		if (!dict.count(str))
		{
			dict[str] = 1;
		}
		else
		{
			dict[str]++;
		}
	}
	for (auto it = dict.begin(); it != dict.end(); it++)
	{
		ResFile << it->first << "\t" << it->second << "\n";
	}
	file.close();
	ResFile.close();

	system("pause");
	return 0;
}
