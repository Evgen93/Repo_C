#include <iostream>
#include <conio.h>

using namespace std;

struct fract
{
	int num;
	int dec;
	//int intg = 0;
	int pon;
};

fract Sum(fract x, fract y)
{
	fract res = { 0, 0, 1 };
	if (x.dec == y.dec)
	{
		res.dec = x.dec;
		res.num = x.pon * x.num + y.pon * y.num;
		if (res.num >= 0)
		{
			res.pon = 1;
		}
		else
		{
			res.pon = -1;
			res.num *= -1;
		}
	}
	else
	{
		res.dec = x.dec * y.dec;
		x.num *= y.dec;
		y.num *= x.dec;
		res.num = x.pon * x.num + y.pon * y.num;
		if (res.num >= 0)
		{
			res.pon = 1;
		}
		else
		{
			res.pon = -1;
			res.num *= -1;
		}
	}
	return res;
	
}

fract Diff(fract x, fract y)
{
	fract res = { 0, 0, 1 };
	if (x.dec == y.dec)
	{
		res.dec = x.dec;
		res.num = x.pon * x.num - y.pon * y.num;
		if (res.num >= 0)
		{
			res.pon = 1;
		}
		else
		{
			res.pon = -1;
			res.num *= -1;
		}
	}
	else
	{
		res.dec = x.dec * y.dec;
		x.num *= y.dec;
		y.num *= x.dec;
		res.num = x.pon * x.num - y.pon * y.num;
		if (res.num >= 0)
		{
			res.pon = 1;
		}
		else
		{
			res.pon = -1;
			res.num *= -1;
		}
	}
	return res;

}

fract Mul(fract a, fract b)
{
	fract res;
	res.num = (a.num * a.pon) * (b.num * b.pon);
	res.dec = a.dec * b.dec;
	if (res.num >= 0)
	{
		res.pon = 1;
	}
	else
	{
		res.pon = -1;
		res.num *= -1;
	}
	return res;
}

fract Div(fract a, fract b)
{
	fract res;
	res.num = a.num * b.dec;
	res.dec = a.dec * b.num;
	if (a.pon == 1 && b.pon == 1)
	{
		res.pon = 1;
	}
	else if (a.pon == -1 && b.pon == -1)
	{
		res.pon = 1;
	}
	else
	{
		res.pon = -1;
	}
	return res;
}

fract Red(fract a)
{
	fract res;
	int temp = 1;
	if (a.num >= a.dec)
	{
		for (size_t i = 2; i < a.num; i++)
		{
			if (a.num % i == 0 && a.dec && i == 0)
			{
				temp = i;
			}
		}
		res.num = a.num / temp;
		res.dec = a.dec / temp;
		res.pon = a.pon;
	}
	return res;
}

void main()
{
	fract a = { 4,8,1 };
	fract b = { 1,3,1 };
	fract res = { 0,0,1 };

	res = Red(a);

	if (res.pon == 1)
	{
		cout << res.num << "/" << res.dec;
	}
	else
	{
		cout << '-';
		cout << res.num << "/" << res.dec;
	}
	

	_getch();
}