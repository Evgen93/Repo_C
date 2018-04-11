#include <iostream>
#include <conio.h>
#include <windows.h>
#define N 15

using namespace std;

struct Car
{
	char* model;
	char* prod;
	char* marks;
	double year = 0;
	struct Engine
	{
		char* type;
		double amount;
		double power;
	};
	Engine eng;
	struct Carcase
	{
		char* type;
		char* color;
	};
	Carcase kuzov;
	struct Wheel
	{
		double radius;
		double width;
		double prof;
	};
	Wheel wh;
	struct KP
	{
		char* type;
		double steps;
	};
	KP kp;
};

int ArrLen(Car arr[])
{
	int count = 0;
	for (size_t i = 0; i < 15; i++)
	{
		if (arr[i].year == 0)
		{
			count = i;
			break;
		}
	}
	if (count == 0)
	{
		return 15;
	}
	else
	{
		return count;
	}
}

void Showlist(Car arr[])
{
	int size = ArrLen(arr);
	for (size_t i = 0; i < size; i++)
	{
		cout << i + 1 << ". " << arr[i].marks << " ";
		cout << arr[i].model << " ";
		cout << arr[i].prod << " ";
		cout << arr[i].year << endl;
	}
}

void ShowCar(Car arr[], int num)
{
	num -= 1;
	cout << endl;
	cout << num + 1 << ". " << arr[num].marks << " ";
	cout << arr[num].model << " ";
	cout << arr[num].prod << " ";
	cout << arr[num].year << ":" << endl;

	cout << "Engine amount : " << arr[num].eng.amount << endl;
	cout << "Engine power : " << arr[num].eng.power << endl;
	cout << "Engine type : " << arr[num].eng.type << endl << endl;

	cout << "Carcase type : " << arr[num].kuzov.type << endl;
	cout << "Carcase color : " << arr[num].kuzov.color << endl << endl;

	cout << "Wheel radius : " << arr[num].wh.radius << endl;
	cout << "Wheel width : " << arr[num].wh.width << endl;
	cout << "Wheel prof : " << arr[num].wh.prof << endl << endl;

	cout << "KP type : " << arr[num].kp.type << endl;
	cout << "KP steps : " << arr[num].kp.steps << endl;
	cout << endl;
}

void AddCar(Car arr[])
{
	int len = ArrLen(arr);
	if (len != 15)
	{
		cout << "Enter mark : " << endl;
		arr[len].marks = new char[15];
		gets_s(arr[len].marks, 15);
		cout << "Enter model : " << endl;
		cin >> arr[len].model;
		cout << "Enter prod : " << endl;
		cin >> arr[len].prod;
		cout << "Enter year : " << endl;
		cin >> arr[len].year;
		cout << "Enter engine type : " << endl;
		cin >> arr[len].eng.type;
		cout << "Enter engine power : " << endl;
		cin >> arr[len].eng.power;
		cout << "Enter engine amount : " << endl;
		cin >> arr[len].eng.amount;
		cout << "Enter carcase color : " << endl;
		cin >> arr[len].kuzov.color;
		cout << "Enter carcase type : " << endl;
		cin >> arr[len].kuzov.type;
		cout << "Enter wheel radius : " << endl;
		cin >> arr[len].wh.radius;
		cout << "Enter wheel width : " << endl;
		cin >> arr[len].wh.width;
		cout << "Enter wheel prof : " << endl;
		cin >> arr[len].wh.prof;
		cout << "Enter Kp type : " << endl;
		cin >> arr[len].kp.type;
		cout << "Enter Kp steps : " << endl;
		cin >> arr[len].kp.steps;
	}
	else
	{
		cout << "Car List is full" << endl;
	}
}

void main()
{
	int choise = -1;
	Car* list = new Car[15];
	list[0].marks = "Ford";
	list[0].model = "Focus";
	list[0].prod = "USA";
	list[0].year = 2009;
	list[0].eng.amount = 1.6;
	list[0].eng.power = 100;
	list[0].eng.type = "Petrol";
	list[0].kp.steps = 5;
	list[0].kp.type = "Hand";
	list[0].kuzov.color = "Red";
	list[0].kuzov.type = "Sedan";
	list[0].wh.prof = 2.4;
	list[0].wh.radius = 17;
	list[0].wh.width = 7;


	while (true)
	{
		cout << "Welcome to the auto show <<Mayonnaise>>" << endl;
		cout << "Select one of the functions : " << endl;
		cout << "1. Wiew the list of cars" << endl;
		cout << "2. View a particular car" << endl;
		cout << "3. Adding a car to the list" << endl;
		cout << "If you want to exit enter 0." << endl;
		cout << endl;
		cin >> choise;
		char* c = "qwe";
		cin >> c;
		list[1].model = c;
		

		if (choise == 0)
		{
			break;
		}
		else if (choise == 1)
		{
			Showlist(list);
			_getch();
		}
		else if (choise == 2)
		{
			int num = 0;
			cout << "Enter num if car: " << endl;
			cin >> num;
			ShowCar(list, num);
			_getch();
		}
		else if (choise == 3)
		{
			cin.ignore();
			cin.clear();
			AddCar(list);
			_getch();
		}
	}

}