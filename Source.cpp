#include "Header.h"




void creatSnake(Snake& snake, Food& food)
{
	snake.element[0].x = 11;
	snake.element[0].y = 6;
	snake.element[0].x = 12;
	snake.element[0].y = 6;
	snake.element[0].x = 13;
	snake.element[0].y = 6;
	snake.length = 3;
	snake.status = RIGHT;

	food.f.x = 11 + rand() % 30;
	food.f.y = 7 + rand() % 10;

}
void move_control(Snake& snake)
{
	for (int i = snake.length - 1; i > 0; i--)
		snake.element[i] = snake.element[i - 1];
	if (_kbhit())
	{
		int key = _getch();
		if (key == 'A' || key == 'a')
			snake.status = LEFT;
		if (key == 'D' || key == 'd')
			snake.status = RIGHT;
		if (key == 'S' || key == 's')
			snake.status = DOWN;
		if (key == 'W' || key == 'w')
			snake.status = UP;
		if (key == 'P' || key == 'p')
			snake.stop = 1;
	}

	if (snake.status == UP)
		snake.element[0].y--;
	if (snake.status == DOWN)
		snake.element[0].y++;
	if (snake.status == LEFT)
		snake.element[0].x--;
	if (snake.status == RIGHT)
		snake.element[0].x++;

}

void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void drawTemp()
{
	TextColor(12);
	gotoXY(20, 1);
	cout << "|----------------------------------------|" << endl;
	gotoXY(20, 2);
	cout << "|              GAME_SNAKE                |" << endl;
	gotoXY(20, 3);
	cout << "|     ________             _______       |" << endl;
	gotoXY(20, 4);
	cout << "|----------------------------------------|" << endl;
	TextColor(8);
	gotoXY(10, 5);
	for (int i = 0; i < 60; i++)
		cout << "#";
	gotoXY(10, 20);
	for (int i = 0; i < 60; i++)
		cout << "#";
	for (int i = 0; i < 15; i++)
	{
		gotoXY(10, 5 + i);
		cout << "#";
	}
	for (int i = 0; i < 16; i++)
	{
		gotoXY(70, 5 + i);
		cout << "#";
	}
	cout << "\n\n\n\n\n\n\n\n\n";

}

void drawOption(char& choose)
{
	gotoXY(19, 7);
	cout << " _______________________________________" << endl;
	gotoXY(19, 8);
	cout << "|                                       |" << endl;
	gotoXY(19, 9);
	cout << "|------------ Choose option ------------|" << endl;
	gotoXY(19, 10);
	cout << "|--- Press key G: Guide ----            |" << endl;
	gotoXY(19, 11);
	cout << "|--- Press key N: New game ----         |" << endl;
	gotoXY(19, 12);
	cout << "|--- Press key T: Continue game ----    |" << endl;
	gotoXY(19, 13);
	cout << "|--- Press key Q: Quit Game ----        |" << endl;
	gotoXY(19, 14);
	cout << "|_______________________________________|" << endl;
	gotoXY(19, 16);
	cout << "---------> Choose: ";
	cin >> choose;
}
void drawGameOver(int score)
{
	gotoXY(23, 9);
	cout << " _________________________________ " << endl;
	gotoXY(23, 10);
	cout << "|                                 |" << endl;
	gotoXY(23, 11);
	cout << "|    -------- Game Over -------   |" << endl;
	gotoXY(23, 12);
	cout << "|       ----your score: " << score << " ----    |" << endl;
	gotoXY(23, 13);
	cout << "|_________________________________|" << endl;

	cout << "\n\n\n\n\n\n\n" << endl;
	system("pause");
}
coordinates createGate()
{
	coordinates pos;
	pos.x = 10 + rand() % 30;
	pos.y = 7 + rand() % 10;
	return pos;
}
void displaySnake(Snake snake, Food food, int score, int& highscore,string list)
{
	clrscr();
	drawTemp();

	if (score > highscore)
		highscore = score;
	gotoXY(75, 9);
	cout << "HIGHSCORE: " << highscore << endl;
	gotoXY(75, 10);
	cout << "SCORE: " << score;
	TextColor(14);
	gotoXY(food.f.x, food.f.y);
	putchar(2);
	TextColor(9);
	gotoXY(snake.element[0].x, snake.element[0].y);
	putchar('0');
	for (int i = 1; i < snake.length; i++)
	{
		gotoXY(snake.element[i].x, snake.element[i].y);
		putchar(list[i-1]);
	}
}
void displaySnake_Gate(Snake snake, coordinates pos, int score, int& highscore)
{
	clrscr();
	drawTemp();

	if (score > highscore)
		highscore = score;
	gotoXY(75, 9);
	cout << "HIGHSCORE: " << highscore << endl;
	gotoXY(75, 10);
	cout << "SCORE: " << score;
	TextColor(14);
	drawGate(pos);
	TextColor(9);
	gotoXY(snake.element[0].x, snake.element[0].y);
	putchar('0');
	for (int i = 1; i < snake.length; i++)
	{
		gotoXY(snake.element[i].x, snake.element[i].y);
		cout << "o";
	}
}
void drawGate(coordinates pos)
{
	gotoXY(pos.x, pos.y - 1);
	cout << " #### " << endl;
	gotoXY(pos.x, pos.y);
	cout << "##  ##" << endl;
	
}
int hanling(Snake& snake, Food& food, int& speed, int& score,int &countFood)
{
	if (snake.stop == 1) return 2;
	if (snake.element[0].x == food.f.x && snake.element[0].y == food.f.y)
	{
		for (int i = snake.length; i > 0; i--)
			snake.element[i] = snake.element[i - 1];
		snake.length++;

		if (snake.status == UP)
			snake.element[0].y--;
		if (snake.status == DOWN)
			snake.element[0].y++;
		if (snake.status == LEFT)
			snake.element[0].x--;
		if (snake.status == RIGHT)
			snake.element[0].x++;

		food.f.x = 11 + rand() % 58;
		food.f.y = 6 + rand() % 13;
		speed = speed - speed / 10;
		score++;
		countFood++;
	}
	if (snake.element[0].x <= 10 || snake.element[0].x >= 70 || snake.element[0].y <= 5 || snake.element[0].y >= 20)
	{

		return 1;
	}
	for (int i = 1; i < snake.length; i++)
	{
		if (snake.element[0].x == snake.element[i].x && snake.element[0].y == snake.element[i].y)
			return 1;
	}

	}

int hanling_gate(Snake& snake, coordinates pos, int& speed, int& score, int& countFood)
{
	Food food;
	food.f = pos;
	int n = snake.length;

	if (snake.stop == 1) return 2;
	int size = snake.length;
	if (snake.element[0].x == food.f.x+2 && snake.element[0].y == food.f.y || snake.element[0].x == food.f.x + 3 && snake.element[0].y == food.f.y)
	{
		for (int i = snake.length; i > 0; i--)
			snake.element[i] = snake.element[i - 1];
		snake.length++;

		if (snake.status == UP)
			snake.element[0].y--;
		if (snake.status == DOWN)
			snake.element[0].y++;
		if (snake.status == LEFT)
			snake.element[0].x--;
		if (snake.status == RIGHT)
			snake.element[0].x++;

		food.f.x = 11 + rand() % 58;
		food.f.y = 6 + rand() % 13;
		speed = speed - speed / 10;
		score++;
		countFood++;
		
	}
	if (snake.element[size - 1].x == food.f.x + 2 && snake.element[size - 1].y == food.f.y || snake.element[size - 1].x == food.f.x + 3 && snake.element[size - 1].y == food.f.y)
	{
		return 0;
	}
	if (snake.element[0].x <= 10 || snake.element[0].x >= 70 || snake.element[0].y <= 5 || snake.element[0].y >= 20)
	{

		return 1;
	}
	for (int i = 1; i < snake.length; i++)
	{
		if (snake.element[0].x == snake.element[i].x && snake.element[0].y == snake.element[i].y)
			return 1;
	}
	if (snake.element[0].x == food.f.x && snake.element[0].y == food.f.y || snake.element[0].x == food.f.x + 1 && snake.element[0].y == food.f.y ||
		snake.element[0].x == food.f.x + 4 && snake.element[0].y == food.f.y || snake.element[0].x == food.f.x + 5 && snake.element[0].y == food.f.y ||
		snake.element[0].x == food.f.x + 1 && snake.element[0].y == food.f.y - 1 || snake.element[0].x == food.f.x + 2 && snake.element[0].y == food.f.y - 1 ||
		snake.element[0].x == food.f.x + 2 && snake.element[0].y == food.f.y - 1 || snake.element[0].x == food.f.x + 3 && snake.element[0].y == food.f.y - 1 ||
		snake.element[0].x == food.f.x + 4 && snake.element[0].y == food.f.y - 1)
	{
		return 1;
	}

}


int highScore()
{
	int data;
	ifstream highscore;
	highscore.open("HighScore.txt");
	highscore >> data;
	highscore.close();
	return data;
}
void inputHighScore(int& highscore)
{
	ofstream x;
	x.open("HighScore.txt");
	x << highscore;
	x.close();
}
void toGuide()
{
	cout << " Move up: W - Move down: S - Move left: A - Move right: D" << endl;
	gotoXY(11, 18);
	cout << "                     Pause: P                             " << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n\n";
}