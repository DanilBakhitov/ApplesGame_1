﻿#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	char mas[10][21];
	int i;
	int n = 0;
	int x = 10, y = 5;
	char key;
	int ox, oy;
	int ax = 5, ay = 3;
	
	srand(time_t(NULL));

	do
	{		
		sprintf_s(mas[0], "####################");
		for (i = 1; i < 9; i++)
			sprintf_s(mas[i], "#                  #");
		sprintf_s(mas[9], "####################");
		mas[y][x] = '@';
		mas[ay][ax] = '*';
		
		system("cls");
		
		for (i = 0; i < 10; i++)
			printf("%s\n", mas[i]);
		printf("\nКоличество собранных яблочек:* = %d", n);
		key = _getch();
		ox = x;
		oy = y;
		if (key == 'w') --y;
		if (key == 's') ++y;
		if (key == 'a') --x;
		if (key == 'd') ++x;
		if (mas[y][x] == '#')
		{
			x = ox;
			y = oy;
		}
		if ((x == ax) && (y == ay))
		{
			ax = rand() * 1.0 / RAND_MAX * 18 +1;
			ay = rand() * 1.0 / RAND_MAX * 8 + 1;
			n++;
		}
	
	}
	while (key != 'e');
	
	
	return 0;
}

