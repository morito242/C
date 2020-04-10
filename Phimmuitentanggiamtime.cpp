#include <stdio.h>
#include <conio.h>
#include <windows.h>

bool Checktime(int h, int m, int s)
{
	if ((h >= 0 && h <= 23) && (m >= 0 && m <= 59) && (s >= 0 && s <= 59))
		return true;
	return false;
}

void Tangtime(int h, int m, int s)
{
	if (s == 59)
	{
		s = 0;
		if (m == 59)
		{
			m = 0;
			if (h == 23)
				h = 0;
			else h++;
		}
		else m++;
	}
	else s++;
	printf("%02d : %02d : %02d", h, m, s);
}

void Giamtime(int h, int m, int s)
{
	if (s == 0)
	{
		s = 59;
		if (m == 0)
		{
			m = 59;
			if (h == 0)
				h = 23;
			else h--;
		}
		else m--;
	}
	else s--;
	printf("%02d : %02d : %02d", h, m, s);
}

void Hethong(int h, int m, int s)
{
	char c = getch();
	if (c == -32)
	{
		c = getch();
		if (c == 72)
			Tangtime(h,m,s);
		if (c == 80)
			Giamtime(h,m,s);
	}
}

int main()
{
	int hour, minute, second;
	do
	{
		system("cls");
		printf("Input hour = ");
		scanf("%d", &hour);
		printf("Input minute = ");
		scanf("%d", &minute);
		printf("Input second = ");
		scanf("%d", &second);
	}
	while (Checktime(hour,minute,second) == false);
	Hethong(hour,minute,second);
	return 0;
}

