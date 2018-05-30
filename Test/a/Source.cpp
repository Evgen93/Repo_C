#include <iostream>

using namespace std;

const int masCount = 5;

class selfCount
{
private:
	static int count;
	int number;
public:
	selfCount()
	{
		count++;
		number = count;
	}

	int getCount()
	{
		return count;
	}

	int getNum()
	{
		return number;
	}
};

int selfCount::count = 0;

void main()
{
	selfCount mass[masCount];
	for (size_t i = 0; i < masCount; i++)
	{
		cout << "OBJECT #" << i << endl;
		cout << mass[i].getNum() << endl;
		cout << mass[i].getCount() << endl;
	}
	selfCount obj;
	cout << obj.getCount();
	cout << obj.getNum();

	system("pause");
	return;
}