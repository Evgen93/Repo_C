#include "conio.h"
#include "iostream"

using namespace std;

char* mystrcat(char* str1, const char* str2)
{
	int i = 0;
	while (str1[i] != '\0')
	{
		i++;
	}
	int j = 0;
	while (str2[j] != '\0')
	{
		str1[i] = str2[j];
		i++;
		j++;
	}
	str1[i] = '\0';
	char*ptrstr1 = str1;
	cout << endl;
	return ptrstr1;
}

int degree(int num, int d)
{
	int n = num;
	for (int i = 1; i < d; i++)
	{
		num *= n;
	}
	return num;
}

int Mystrlen(const char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

char* Mystrrev(char* str)
{
	char* _str = new char[Mystrlen(str) + 1];

	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			_str[i] = str[i] + 32;
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			_str[i] = str[i] - 32;
		}
		else
		{
			_str[i] = str[i];
		}
		i++;
	}
	_str[i] = '\0';
	delete[] str;
	return _str;
}

char* NumberToString(int num)			// Не доделана
{
	int digit = 0;
	for (int i = 1, d = 10; i < 11; i++)
	{
		if ((num / d) < 1)
		{
			digit = i;
			break;
		}
		else
		{
			d *= 10;
		}
	}

	int* arr = new int[digit];
	int s = digit;

	for (int i = 0, d = 10; i < digit; i++)
	{

		arr[i] = num / degree(d, s);
		s--;
	}

	for (int i = 0; i < digit; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	char* str = new char[digit];
	return str;

}

void main()
{
	setlocale(LC_ALL, "Russian");

	/*char* text = new char[1000];

	gets_s(text, 1000);
	int len = Mystrlen(text);
	char* str = nullptr;
	int i = 0;

	while (i < 5)
	{
		text[len] = '\n';
		str = &text[len + 1];
		gets_s(str, 1000 - len + 1);
		len = Mystrlen(text);
		i++;
	}

	cout << text;*/

	_getch();
	 
}