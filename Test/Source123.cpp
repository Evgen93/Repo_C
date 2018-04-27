#include <stdio.h>
#include <iostream>
#include <conio.h>
#define N 5

using namespace std;

void main()
{
	/*char* str = (char*)calloc(N, sizeof(char));
	FILE* S;
	FILE* D;

	fopen_s(&S, "text.txt", "r");
	fopen_s(&D, "text1.txt", "w");

	while (fgets(str, N - 1, S) != nullptr)
	{
		printf("%s", str);
		fputs(str, D);

		for (size_t i = 0; i < N; i++)
		{
			str[i] = '\0';
		}
	}

	fclose(S);
	fclose(D);*/


	/*FILE* f;
	fopen_s(&f, "text.txt", "w");
	fputs("This is Sample.", f);
	fseek(f, -6, SEEK_CUR);
	fputs("parta", f);
	fclose(f);
	_getch();
	return;*/

	struct film
	{
		char name[16];
		int year;
	};

	film* library = new film[N];
	
	for (size_t i = 0; i < N; i++)
	{
		cout << "Enter name: ";
		cin >> library[i].name;
		cout << "Enter year: ";
		cin >> library[i].year;
	}

	FILE* f;
	size_t res = 0;
	fopen_s(&f, "text.txt", "wb");
	res = fwrite(library, sizeof(film), N, f);
	if (res == N)
	{
		cout << "OK" << endl;
	}
	else
	{
		cout << "no OK" << endl;
	}
	fclose(f);

	freopen_s(&f, "text.txt", "rb", f);
	film twoFilms[2];

	do
	{
		res = fread(twoFilms, sizeof(film), 2, f);
		for (size_t i = 0; i < res; i++)
		{
			cout << "Name: " << twoFilms[i].name << endl;
			cout << "Year: " << twoFilms[i].year << endl;
		}
	} while (res == 2);
	fclose(f);
	_getch();
}