#include<Windows.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<locale.h>
#include<conio.h>



void main()
{
	const int dl = 25, dlk = 625, fr = 100;
	char xy[dl+2][dl+2], per = '#', perf = '*';
	int x[dlk], y[dlk], z = 0, xf, yf, mov = 0, t = 0, end = 1, tall = 1,tail;
	setlocale(0, "rus");
	srand(time(NULL));
	rand();
	while (true)
	{
		xf = 1 + rand() % dl;
		yf = 1 + rand() % dl;
		if (xf == 3 && yf == 3)
			continue;
		break;
	}
	for (int xch = 0;xch < dlk;xch++)
		x[xch] = dl-dl/2;
	for (int ych = 0;ych < dlk;ych++)
		y[ych] = dl-dl/2;
	for (int yi = 1;yi <= dl;yi++)
		for (int xi = 1;xi <= dl;xi++)
			xy[yi][xi] = ' ';
	for (int grgv = 0;grgv <= dl+1;grgv++)
		xy[0][grgv] = '+';
	for (int grgn = 0;grgn <= dl+1;grgn++)
		xy[dl+1][grgn] = '+';
	for (int grvl = 0;grvl <= dl+1;grvl++)
		xy[grvl][0] = '+';
	for (int grvp = 0;grvp <= dl+1;grvp++)
		xy[grvp][dl+1] = '+';
	printf("Добро пожаловать. Приятной игры.\nЧтобы выйти нажмите Esc.\nНажмите любую клавишу, чтобы продолжить.");
	getch();
	system("cls");
	for (int yi = 0;yi <= dl + 1;yi++)
	{
		for (int xi = 0;xi <= dl + 1;xi++)
			printf("%c", xy[yi][xi]);
		printf("\n");
	}
	while (end == 1)
	{
		tail = tall - 1;
		while (xy[yf][xf] != '*')
		{
			
			xf = 1 + rand() % dl;
			yf = 1 + rand() % dl;
			if (xy[yf][xf] != ' ')
				continue;
			tall++;
			break;
		}
		for (int ky = 1;ky <= dl;ky++)
			for (int kx = 1;kx <= dl;kx++)
				xy[ky][kx] = ' ';
		xy[yf][xf] = perf;
		for (int i = 0;i < tall;i++)
			xy[y[i]][x[i]] = per;
		COORD position;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		position.X = 0;
		position.Y = 1;
		SetConsoleCursorPosition(hConsole, position);
		for (int xx = 0;xx <= dl + 1;xx++)
			printf("%c", xy[1][xx]);
		printf("    Длина равна:%i\n", tail);
		for (int yi = 2;yi <= dl;yi++)
		{
			for (int xi = 0;xi <= dl+1;xi++)
				printf("%c", xy[yi][xi]);
			printf("\n");
		}
		if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(0x44))
			if (mov != 2 && mov != 1)
			{
				x[0] += 1;
				mov = 1;
				t = 0;
				for (int k = tall;k >= 1;k--)
				{
					x[k] = x[k - 1];
					y[k] = y[k - 1];
				}
			}
		if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(0x41))
			if (mov != 1 && mov != 2)
			{
				x[0] -= 1;
				mov = 2;
				t = 0;
				for (int k = tall;k >= 1;k--) 
				{
					x[k] = x[k - 1];
					y[k] = y[k - 1];
				}
			}
		if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(0x57))
			if (mov != 4 && mov != 3)
			{
				y[0] -= 1;
				mov = 3;
				t = 0;
				for (int k = tall;k >= 1;k--) 
				{
					x[k] = x[k - 1];
					y[k] = y[k - 1];
				}
			}
		if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState(0x53))
			if (mov != 3 && mov != 4)
			{
				y[0] += 1;
				mov = 4;
				t = 0;
				for (int k = tall;k >= 1;k--) 
				{
					x[k] = x[k - 1];
					y[k] = y[k - 1];
				}
			}
		if (GetAsyncKeyState(VK_ESCAPE))
			end = 2;
		if (tall >= dlk)
			end = 4;
		for (int t = 4;t <= tail;t++)
			if (x[0] == x[t] && y[0] == y[t])
				end = 3;
		switch (x[0])
		{
		case 0:end = 0;;
		case dl+1:end = 0;;
		}
		switch (y[0])
		{
		case 0:end = 0;
		case dl+1:end = 0;
		}
		if (t >= (4))
		{
			switch (mov)
			{
			case 1:x[0] += 1;
				t = 0;
				for (int k = tall;k >= 1;k--) 
				{
					x[k] = x[k - 1];
					y[k] = y[k - 1];
				}
				break;
			case 2:x[0] -= 1;
				t = 0;
				for (int k = tall;k >= 1;k--) 
				{
					x[k] = x[k - 1];
					y[k] = y[k - 1];
				}
				break;
			case 3:y[0] -= 1;
				t = 0;
				for (int k = tall;k >= 1;k--) 
				{
					x[k] = x[k - 1];
					y[k] = y[k - 1];
				}
				break;
			case 4:y[0] += 1;
				t = 0;
				for (int k = tall;k >= 1;k--) 
				{
					x[k] = x[k - 1];
					y[k] = y[k - 1];
				}
				break;
			}
		}
		Sleep(fr);
		t += 1;
	}
		system("cls");
		if (end == 3)
			puts("Вы съели сами себя");
		if (end == 4)
			puts("Вы выиграли, поздравляю");
		if (end != 2)
		{
			puts("Конец игры, нажмите Esc, чтобы выйти");
			while (true)
			{
				if (GetAsyncKeyState(VK_ESCAPE))
					break;
			}
		}
}