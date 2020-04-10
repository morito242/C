#include <stdio.h>
#include <conio.h>
#include <windows.h>

bool Checkdmy(int d, int m, int y)
{
	int maxday;
	switch (m)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			maxday = 31;
			break;
		case 4: case 6: case 9: case 11:
			maxday = 30;
			break;
		case 2:
			if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
			    maxday = 29;
			else
			    maxday = 28;
			break;
	}
	if (y > 0 && (m >= 1 && m <= 12) && (d >= 1 && d <= maxday))
		return true;
	return false;
}

int Daymax(int d, int m, int y)
{
	int maxday;
	switch (m)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			maxday = 31;
			break;
		case 4: case 6: case 9: case 11:
			maxday = 30;
			break;
		case 2:
			if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
			    maxday = 29;
			else
			    maxday = 28;
			break;
	}
	return maxday;
}

void Tangngay(int d, int m, int y)
{
	if (d == Daymax(d,m,y))
	{
		d = 1;
		if (m == 12)
		{
			m = 1;
			y++;
		}
		else m++;
	}
	else d++;
	printf("%d / %d / %d", d, m, y);
}

void Giamngay(int d, int m, int y)
{
	if (d == 1)
	{
		if (m == 1)
		{
			m = 12;
			y--;
		}
		else m--;
		d = Daymax(d,m,y);
	}
	else d--;
	printf("%d / %d / %d", d, m, y);
}

void Hethong(int d, int m, int y)
{
	char c = getch();
	if (c == -32)
	{
		c = getch();
		if (c == 72)
			Tangngay(d,m,y);
		if (c == 80)
			Giamngay(d,m,y);
	}
}

int main()
{
	int day, month, year;
	do
	{
		system("cls");
		printf("Input day = ");
		scanf("%d", &day);
		printf("Input month = ");
		scanf("%d", &month);
		printf("Input year = ");
		scanf("%d", &year);
	}
	while (Checkdmy(day,month,year) == false);
	Hethong(day,month,year);
	return 0;
}
