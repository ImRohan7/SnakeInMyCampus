#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<string>

using namespace std;

struct Snake {

	int startX, endX, startY;

}Snake_Dimensions;

bool block, gameOver, gamewon;
bool isPrint = false;
int x, y, score, level;
string time;
const int width = 50;
const int height = 25;

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection direction;

Snake snake[5];

void Setup()
{
	gamewon, gameOver = false;
	direction = STOP;
	x = 30;
	y = 24;

	snake[0].startX = 10;
	snake[0].endX = 15;
	snake[0].startY = 5;

	snake[1].startX = 15;
	snake[1].endX = 20;
	snake[1].startY = 10;

	snake[2].startX = 13;
	snake[2].endX = 18;
	snake[2].startY = 15;

	snake[3].startX = 18;
	snake[3].endX = 23;
	snake[3].startY = 20;

	score = 0;
	level = 1;
}

void Draw()
{
	system("cls");
//Top wall
	for (int i = 0; i < width - 2; i++)
	{
		if (i == 25)
		{
			cout << "    ";
		}
		else
			cout << "#";
	}
	cout << endl;

	//printing Block Heading
	cout << "  J BLOCK ###############    ############## M BLOCK" << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j >= 0 && j <= 9 || j >= 43 && j <= 50)
				cout << "#";
			else if (i == y && j == x)
			{
				cout << "O";
			}
			else
			{
				bool print = false;
				block = false;
				//Printing Snakes
				for (int k = 0; k < 4; k++)
				{
					if (j == snake[k].startX && i == snake[k].startY)
					{
						for (int l = snake[k].startX; l <= snake[k].endX; l++)
						{
							cout << "S";
						}
						block = true;
					}

					if (j <= snake[k].endX && j >= snake[k].startX && i == snake[k].startY)
					{
						block = true;
					}

				}

				if (!print && !block)
				{
					cout << " ";
				}

			}
			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}

//Bottom wall
	for (int i = 0; i < width - 2; i++)
	{
		if (i == 25)
		{
			cout << "    ";
		}
		else
			cout << "#";
	}
	cout << "\nScore :" << score;
	cout << "\tLevel :" << level;
	cout << "\tTime : " << time;
}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			direction = LEFT;
			break;
		case 'd':
			direction = RIGHT;
			break;
		case 'w':
			direction = UP;
			break;
		case 's':
			direction = DOWN;
			break;
		case 'z':
			gameOver = true;
			break;
//Numbers
		case '4':
			cout << "AA";
			direction = LEFT;
			break;
		case '6':
			direction = RIGHT;
			break;
		case '8':
			direction = UP;
			break;
		case '5':
			direction = DOWN;
			break;
		}
	}
}

void Logic()
{
//Each case represents a different level
	switch (level)
	{
	case 1:
		snake[0].startX++;
		snake[0].endX++;

		snake[1].startX++;
		snake[1].endX++;

		snake[2].startX++;
		snake[2].endX++;

		snake[3].startX++;
		snake[3].endX++;

		time = "Morning";

		//setting back to original on wall touch

		for (int i = 0; i < 4; i++)
		{
			if (snake[i].endX >= 43)
			{
				snake[i].startX = 10;
				snake[i].endX = 17;
			}
		}

		break;

	case 2:
		snake[0].startX += 2;
		snake[0].endX += 2;

		snake[1].startX += 1;
		snake[1].endX += 1;

		snake[2].startX += 3;
		snake[2].endX += 3;

		snake[3].startX += 1;
		snake[3].endX += 1;

		time = "Afternoon";

		for (int i = 0; i < 4; i++)
		{
			if (snake[i].endX >= 43)
			{
				snake[i].startX = 10;
				snake[i].endX = 17;
			}
		}

		break;

	case 3:
		snake[0].startX += 3;
		snake[0].endX += 3;

		snake[1].startX += 2;
		snake[1].endX += 2;

		snake[2].startX += 4;
		snake[2].endX += 4;

		snake[3].startX += 2;
		snake[3].endX += 2;

		time = "Evening";

		for (int i = 0; i < 4; i++)
		{
			if (snake[i].endX >= 43)
			{
				snake[i].startX = 10;
				snake[i].endX = 18;
			}
		}

		break;

	case 4:
		snake[0].startX += 4;
		snake[0].endX += 4;

		snake[1].startX += 2;
		snake[1].endX += 2;

		snake[2].startX += 5;
		snake[2].endX += 5;

		snake[3].startX += 3;
		snake[3].endX += 3;

		time = "Night";

		for (int i = 0; i < 4; i++)
		{
			if (snake[i].endX >= 43)
			{
				snake[i].startX = 10;
				snake[i].endX = 17;
			}
		}

		break;

	case 5:
		snake[0].startX += 3;
		snake[0].endX += 3;

		snake[1].startX -= 5;
		snake[1].endX -= 5;

		snake[2].startX += 6;
		snake[2].endX += 6;

		snake[3].startX -= 4;
		snake[3].endX -= 4;

		time = "Midnight";

		for (int i = 0; i < 4; i++)
		{
			if (i == 0 || i == 2)
			{
				if (snake[i].endX >= 43)
				{

					snake[i].startX = 10;
					snake[i].endX = 18;

				}
			}
			else
			{
				if (snake[i].startX <= 9)
				{
					snake[i].startX = 34;
					snake[i].endX = 42;
				}
			}
		}

		break;

	default:
		break;
	}

	switch (direction)
	{
	case LEFT:
		x--;
		break;

	case RIGHT:
		x++;
		break;

	case UP:
		y--;
		break;

	case DOWN:
		y++;
		break;

	default:
		break;
	}
	
//Update LEVEL and SCORE
	if (x >= 25 && x <= 28 && y == -1)
	{
		x = 26; y = 24;
		score += 10;
		if (score % 50 == 0)
		{
			level++;
		}
		if (level == 6)
		{
			gamewon = true;
			gameOver = true;
		}
	}

//Setting Gameover to true on collapsing with Walls 

	if (x <= 24 && y == -1 || x >= 29 && y == -1) { gameOver = true; }
	if (x <= 9 || x >= 43) { gameOver = true; }
	if (y >= 25) { gameOver = true; }

//Setting Gameover to true on collapsing with Snake 

	for (int i = 0; i < 4; i++)
	{
		if (x <= snake[i].endX && x >= snake[i].startX && y == snake[i].startY)
		{
			gameOver = true;
		}
	}
}

void menu()
{
	cout << endl << "**************Welcome to Snake In My Campus**************" << endl;
	cout << "STORY :" << endl;
	cout << "\nI made this game in the memory of my first year in college. When I came to college in the \nfirst semester "
		"I came to know that there were some snakes running in my campus between the \nway of J and M block. "
		"There were some warning signs too indicating to move carefully and \nwatch out for snakes. "
		"It was a strange experience and a bit scary too. In the first year, \nmost of our lectures "
		"were being held in M block. So we had to go through that scary snake \npath multiple times in "
		"a day in order to attend lectures. In my second year, the muddy grass \narea was cleaned up and "
		"the problem solved but the memory remained in our brains forever !!!\n"
		"So I tried to link that incident to this game :) \n\n";
	cout << "GOAL :";
	cout << "\nYour goal is to survive from morning to midnight in the campus by completing runs through that \n"
		"scary snake path between J and M block. You need to make a total of 25 runs to win the game.\n"
		"******YOU CAN ONLY MAKE A SUCCESSFUL RUN IN BOTTOM TO TOP DIRECTION else GAMEOVER******\nOn "
		"every 5 successful runs, the time will move forward.Be careful, because the snake's size \nand speed"
		" will increase as time moves forward and night comes nearer.\n"
		"They might change the directions too !!!\n\n"
		"\t\tREMEMBER ONCE YOU START TO RUN YOU CAN'T STOP !!!\n\t\tGAME OVER on collapsing with snakes or walls.\n\n";
	cout << "CONTROLS :\t";
	cout << "W-up		S-down		A-left		D-right\n"
		"\t\t8-up		5-down		4-left		6-right";
	cout << "\nYou can see the score and time in the bottom of the screen.\n	Have fun : )\n\n";
	cout << "Press 'S' to start the GAME, 'Q' to Quit\n>>>>>>MAKE SURE TO SET FULL SCREEN RESOLUTION FOR BEST GAMEPLAY<<<<<<";
}

int main()
{
	menu();
	char action = _getch();
	if (action == 's') {

		Setup();

		while (!gameOver)
		{
			Draw();
			Input();
			Logic();
			Sleep(20);
		}

		if (gamewon)
		{
			system("cls");
			{
				cout << "\n\n\tCongratulations !!! YOU WON THE GAME....Survived one day in the campus\n\n\t Have some SNAKES :D ";
				Sleep(8000);
				return 0;
			}
		}
		system("cls");
		cout << "\n\n\t\t\tOUCHHH.........Game Over";
		Sleep(2000);
	}
	else if (action == 'z') 
	{
		gameOver = true;
	}
	return 0;
}
