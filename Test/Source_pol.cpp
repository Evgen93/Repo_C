#include "conio.h"
#include "iostream"
#include "ctime"

using namespace std;

void main()
{
	char* strPtr1 = new char[128];
	int lenStr1 = 0;
	int count = 0;
	gets_s(strPtr1, 128);

	cout << strPtr1 << endl;

	for (int i = 0; i < 128; i++)
	{
		if (strPtr1[i] == '\0')
		{
			break;
		}
		lenStr1++;
	}

	cout << lenStr1 << endl;

	for (int i = 0; i < lenStr1 / 2; i++)
	{
		if (strPtr1[i] == strPtr1[(lenStr1 - 1) - i])
		{
			count++;
		}
	}

	cout << count << endl;
	if (count == lenStr1 / 2)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}

	_getch();
}