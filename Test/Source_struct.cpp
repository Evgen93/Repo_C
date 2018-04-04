#include <iostream>
#include <conio.h>
#include <math.h>
#define N 3

using namespace std;

struct PR
{
	int l = 10;
	int w = 15;
	char c = '#';

	void Print()
	{
		for (size_t j = 0; j < w; j++)
		{
			cout << c;
		}
		for (size_t i = 0; i < l; i++)
		{

			cout << endl;
			cout << c;
			for (size_t j = 1; j < w - 1; j++)
			{
				cout << " ";
			}
			cout << c;
		}
		cout << endl;
		for (size_t j = 0; j < w; j++)
		{
			cout << c;
		}
		cout << endl;
	}

	void PrintEnpty()
	{
		for (size_t i = 0; i < l; i++)
		{
			for (size_t j = 0; j < w; j++)
			{
				cout << c;
			}
			cout << endl;
		}
	}
	void ChangePr()
	{
		cout << "Enter the lenth: " << endl;
		cin >> l;
		cout << "Enter the width: " << endl;
		cin >> w;
	}
	
	void ChSym()
	{
		cout << "Enter the sym: " << endl;
		cin >> c;
	}
};

struct node
{
	int price = 0;
	char* name = nullptr;
};

struct Pifagor
{
	int x = 0;
	int y = 0;
};

void main()
{
	/*PR pr;
	pr.Print();
	pr.ChangePr();
	pr.ChSym();
	pr.Print();
	pr.PrintEnpty();
	_getch();*/
	{
	//Ã¿——»¬ —“–” “”–
	/*node shop[N];
	int sum = 0;
	for (size_t i = 0; i < N; i++)
	{
		cout << "Enter name" << endl;

		shop[i].name = new char[32];
		if (i != 0)
		{
			gets_s(shop[i].name, 32);
		}
		gets_s(shop[i].name, 32);

		cout << "Enter price" << endl;
		scanf_s("%i", &shop[i].price);
		sum += shop[i].price;
	}
	system("cls");
	cout << "Sum = " << sum;

	for (size_t i = 0; i < N; i++)
	{
		delete[] shop[i].name;
	}*/
	}

	//”Í‡Á‡ÚÂÎ¸ Ì‡ ÒÚÛÍÚÛÛ

	{
		/*node* shop;
		int N = 0;
		int sum = 0;
		cout << "Enter N" << endl;
		cin >> N;
		shop = new node[N];
		for (size_t i = 0; i < N; i++)
		{
			cout << "Enter name" << endl;

			shop[i].name = new char[32];
			//gets_s(shop[i].name, 32);
			cin.clear();
			cin.ignore();
			gets_s(shop[i].name, 32);
			cout << "Enter price" << endl;
			scanf_s("%i", &shop[i].price);
			sum += shop[i].price;
		}
		system("cls");
		cout << "Sum = " << sum;

		for (size_t i = 0; i < N; i++)
		{
			delete[] shop[i].name;
		}
		delete[] shop;*/
	}

	/*Pifagor arr[N];
	int res[N - 1];
	for (size_t i = 0; i < N; i++)
	{
		cout << "Enter x" << i << endl;
		cin >> arr[i].x;
		cout << "Enter y" << i << endl;
		cin >> arr[i].y;
	}
	for (size_t i = 0; i < N - 1; i++)
	{
		res[i] = sqrt(pow((arr[i].x - arr[i + 1].x), 2) + (pow((arr[i].y - arr[i + 1].y), 2)));
	}
	for (size_t i = 0; i < N - 1; i++)
	{
		cout << res[i] << endl;
	}*/

	Pifagor* mass;
	int res[N - 1];
	mass = new Pifagor[N];

	for (size_t i = 0; i < N; i++)
	{
		cout << "Enter x" << i << endl;
		cin >> mass[i].x;
		cout << "Enter y" << i << endl;
		cin >> mass[i].y;
	}
	for (size_t i = 0; i < N - 1; i++)
	{
		res[i] = sqrt(pow((mass[i].x - mass[i + 1].x), 2) + (pow((mass[i].y - mass[i + 1].y), 2)));
	}
	for (size_t i = 0; i < N - 1; i++)
	{
		cout << res[i] << endl;
	}
	_getch();
}