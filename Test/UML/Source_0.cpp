#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>

class freqDict
{
protected:
	std::map<std::string, int> dict;
	std::string str;
	std::ifstream fileIn;
	std::ofstream fileOut;
public:
	freqDict() = delete;
	freqDict(std::string pathIn, std::string pathOut);
	~freqDict() {}
private:
	void Tolower();
};

void freqDict::Tolower()
{
	if (str[0] >= 'À' && str[0] <= 'ß')
	{
		str[0] -= ('À' - 'ß');
	}
}
freqDict::freqDict(std::string pathIn, std::string pathOut)
{
	fileIn.open(pathIn);
	if (!fileIn.is_open())
	{
		std::cout << "Error when opening fileIn" << std::endl;
	}
	else
	{
		fileOut.open(pathOut);
		if (!fileOut.is_open())
		{
			std::cout << "Error when opening fileOut" << std::endl;
		}
		else
		{
			while (fileIn >> str)
			{
				Tolower();
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
				fileOut << it->first << "\t" << it->second << "\n";
			}
		}
		fileIn.close();
		fileOut.close();
	}
}

int main()
{
	freqDict fDict("Text.txt", "ResFile.txt");
	system("pause");
	return 0;
}