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
	snake.stop = 0;
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
	
	TextColor(14);
	gotoXY(25, 1);
	cout << "|----------------------------------------|" << endl;
	gotoXY(25, 2);
	cout << "|              GAME_SNAKE                |" << endl;
	gotoXY(25, 3);
	cout << "|     ________   TEAM 29   _______       |" << endl;
	gotoXY(25, 4);
	cout << "|----------------------------------------|" << endl;
	TextColor(7);
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
	for (int i = 0; i < 20; i++) {
		gotoXY(71 + i, 5);
		cout << "#";
	}
	for (int i = 0; i < 15; i++)
	{
		gotoXY(90, 5 + i);
		cout << "#";
	}
	for (int i = 0; i < 20; i++) {
		gotoXY(71 + i, 20);
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
	gotoXY(19, 15);
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
	TextColor(14);
	gotoXY(72, 7);
	cout << "HIGHSCORE: " << highscore << endl;
	gotoXY(72, 8);
	cout << "SCORE: " << score;
	gotoXY(72, 9);
	cout << "W: move up";
	gotoXY(72, 10);
	cout << "S: move down";
	gotoXY(72, 11);
	cout << "A: move left";
	gotoXY(72, 12);
	cout << "D: move right";
	gotoXY(72, 13);
	cout << "P: Pause game";
	gotoXY(food.f.x, food.f.y);
	putchar(2);
	TextColor(15);
	gotoXY(snake.element[0].x, snake.element[0].y);
	putchar(3);
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
	TextColor(14);
	gotoXY(72, 7);
	cout << "HIGHSCORE: " << highscore << endl;
	gotoXY(72, 8);
	cout << "SCORE: " << score;
	gotoXY(72, 9);
	cout << "W: move up";
	gotoXY(72, 10);
	cout << "S: move down";
	gotoXY(72, 11);
	cout << "A: move left";
	gotoXY(72, 12);
	cout << "D: move right";
	gotoXY(72, 13);
	cout << "P: Pause game";
	TextColor(14);
	
	gotoXY(snake.element[0].x, snake.element[0].y);
	putchar('0');
	for (int i = 1; i < snake.length; i++)
	{
		gotoXY(snake.element[i].x, snake.element[i].y);
		cout << "o";
	}
	drawGate(pos);
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
	gotoXY(72, 10);
	cout << "W: MOVE UP";
	gotoXY(72, 11);
	cout << "S: MOVE DOWN";
	gotoXY(72, 12);
	cout << "A: MOVE LEFT";
	gotoXY(72, 13);
	cout << "D: MOVE RIGHT";
	gotoXY(72, 14);
	cout << "P: PAUSE GAME";

	cout << "\n\n\n\n\n\n\n\n\n\n\n";
}

string checkPlayerName()
{
	int checkout = 0;
	char player[30];
	fstream listx;
	listx.open("player.txt", ios::in);
	char temp[30];
	int index = 16;
	do {
		gotoXY(20, index);
		if (checkout == 0) cin.ignore();
		checkout = 0;
		cout << "Your name: ";
		cin.getline(player, 30);
		while (!listx.eof()) {
			listx.getline(temp, 30);
			if ((string)player == (string)temp)
			{
				gotoXY(20, 17);
				cout << "Player name already exists!";
				checkout = 1;
				index += 2;
			}
			if (checkout == 1) break;
		}
	} while (checkout != 0);
	listx.close();
	return (string)player;
}

void saveGame(string playerPath, Snake snake,string name,int score,Food food,int speed)
{
	fstream player;
	player.open(playerPath, ios::out);
	player << name << "\n" << score << "\n0\n";
	player << food.f.x << " " << food.f.y << endl;
	if (snake.status == UP) player << "0" << endl;
	if (snake.status == DOWN) player << "1" << endl;
	if (snake.status == LEFT) player << "2" << endl;
	if (snake.status == RIGHT) player << "3" << endl;
	player<<snake.length << endl;
	for (int i = 0; i < snake.length; i++) {
		player << snake.element[i].x << " " << snake.element[i].y<< endl;
	}
	player << speed;
	player.close();
}

void loadSavedGame(Snake &snake,char* &name, int &score,Food &food,int& speed)
{
	gotoXY(20, 16);
	cout << "Your name: ";
	cin.ignore();
	cin.getline(name, 30);
	string player = (string)name + ".txt";

	fstream fplayerx;
	fplayerx.open("player.txt", ios::out);
	int checkout = 0;
	while (!fplayerx.eof()) {
		char nameplayer[30];
		fplayerx.getline(nameplayer, 30);
		if ((string)nameplayer == (string)name) {
			checkout = 1;
			break;
		}
	}
	if (checkout == 0) {
		gotoXY(20, 17);
		cout << "Playername does not exist!";
		return;
	}
	fstream fplayer;
	fplayer.open(player, ios::out);
	fplayer.getline(name, 30);
	fplayer >> score;
	fplayer >> snake.endgame;
	fplayer << food.f.x << food.f.y;
	int x, y;
	fplayer >> y;
	if (y == 1) {
		gotoXY(20, 17);
		cout << "Game of this player is over!";
		return;
	}
	fplayer >> x;
	if (x == 0) snake.status == UP;
	if (x == 1) snake.status == DOWN;
	if (x == 2) snake.status == LEFT;
	if (x == 3) snake.status == RIGHT;
	fplayer >> snake.length;

	for (int i = 0; i < snake.length; i++)
	{
		fplayer >> snake.element[i].x >> snake.element[i].y;
	}
	fplayer >> speed;
	fplayer.close();
	
}

void playNewGame(Snake snake, Food food, int score, int highscore, string list, int countFood,int speed,int check)
{
	fstream listx;
	ofstream listm;
	listm.open("player.txt", ios::app);

	string player = checkPlayerName();
	listm << "\n"<<player;
	listm.close();
	string playerPath = (string)player + ".txt";
	while (1)
	{

		displaySnake(snake, food, score, highscore, list);
		move_control(snake);
		check = hanling(snake, food, speed, score, countFood);

		if (check == 1)
		{
			drawGameOver(score);
			check = 10;
			snake.endgame = 1;

		}
		if (check == 2) {

			int mn;
			gotoXY(72, 15);
			cout << "Continue?" << endl;
			gotoXY(72, 16);
			cout << "1: Yes" << endl;
			gotoXY(72, 17);
			cout << "2: Save and quit" << endl;
			gotoXY(72, 18);
			cout << "Choose: ";
			cin >> mn;
			if (mn == 2) {
				gotoXY(30, 14);
				cout << "Player: " << player << endl;
				gotoXY(30, 15);
				cout << "Score: " << score << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				check = 10;
				saveGame(playerPath, snake, player, score,food,speed);
				system("pause");
				break;
			}
			else {
				snake.stop = 0;
			}
		}


		// Xử lí vẽ cổng và cho rắn vào cổng

		if (countFood % 4 == 0 && countFood != 0)// Khi ăn được mỗi 4 food thì sẽ in ra cổng để cho snake đi qua
		{
			coordinates pos = createGate();

			while (1) {
				displaySnake_Gate(snake, pos, score, highscore);
				move_control(snake);
				check = hanling_gate(snake, pos, speed, score, countFood);
				if (check == 1)
				{
					drawGameOver(score);
					snake.endgame = 1;
					check = 10;
				}
				if (check == 10) break;
				if (check == 2) {

					int mn;
					gotoXY(72, 15);
					cout << "Continue?" << endl;
					gotoXY(72, 16);
					cout << "1: Yes" << endl;
					gotoXY(72, 17);
					cout << "2: Save and quit" << endl;
					gotoXY(72, 18);
					cout << "Choose: ";
					cin >> mn;
					if (mn == 2) {
						gotoXY(30, 14);
						cout << "Player: " << player << endl;
						gotoXY(30, 15);
						cout << "Score: " << score << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
						check = 10;
						saveGame(playerPath, snake, player, score,food,speed);
						system("pause");
						break;
					}
					else {
						snake.stop = 0;
					}

				}
				if (check == 0) break;
				Sleep(speed);

			}


		}
		Sleep(speed);
		if (check == 10) break;
	}
	if (snake.endgame == 1) {
		fstream fplayer;
		fplayer.open(playerPath, ios::out);
		fplayer << player << "\n" << score;
		fplayer << "\n1";
		fplayer.close();
	}

	score = 0;
	speed = 200;
	inputHighScore(highscore);

}

void printListPlayer()
{
	fstream listm;
	listm.open("player.txt", ios::in);
	int index = 7;
	gotoXY(72, 6);
	cout << "<--List player-->";
	while (!listm.eof()) {
		char temp[30];
		listm.getline(temp, 30);
		gotoXY(72, index);
		cout << temp;
		index++;
	}
	listm.close();
}

void playSavedGame(Snake snake, Food food, int score, int highscore, string list, int countFood, int speed, int check,char* name)
{
	string playerPath = string(name) + ".txt";

	while (1)
	{

		displaySnake(snake, food, score, highscore, list);
		move_control(snake);
		check = hanling(snake, food, speed, score, countFood);

		if (check == 1)
		{
			drawGameOver(score);
			check = 10;
			snake.endgame = 1;
			break;

		}
		if (check == 2) {

			int mn;
			gotoXY(72, 15);
			cout << "Continue?" << endl;
			gotoXY(72, 16);
			cout << "1: Yes" << endl;
			gotoXY(72, 17);
			cout << "2: Save and quit" << endl;
			gotoXY(72, 18);
			cout << "Choose: ";
			cin >> mn;
			if (mn == 2) {
				gotoXY(30, 14);
				cout << "Player: " << name << endl;
				gotoXY(30, 15);
				cout << "Score: " << score << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				check = 10;
				saveGame(playerPath, snake, name, score, food,speed);
				system("pause");
				break;
			}
			else {
				snake.stop = 0;
			}
		}


		// Xử lí vẽ cổng và cho rắn vào cổng

		if (countFood % 4 == 0 && countFood != 0)// Khi ăn được mỗi 4 food thì sẽ in ra cổng để cho snake đi qua
		{
			coordinates pos = createGate();

			while (1) {
				displaySnake_Gate(snake, pos, score, highscore);
				move_control(snake);
				check = hanling_gate(snake, pos, speed, score, countFood);
				if (check == 1)
				{
					drawGameOver(score);
					snake.endgame = 1;
					check = 10;
				}
				if (check == 10) break;
				if (check == 2) {

					int mn;
					gotoXY(72, 15);
					cout << "Continue?" << endl;
					gotoXY(72, 16);
					cout << "1: Yes" << endl;
					gotoXY(72, 17);
					cout << "2: Save and quit" << endl;
					gotoXY(72, 18);
					cout << "Choose: ";
					cin >> mn;
					if (mn == 2) {
						gotoXY(30, 14);
						cout << "Player: " << name << endl;
						gotoXY(30, 15);
						cout << "Score: " << score << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
						check = 10;
						saveGame(playerPath, snake, name, score, food,speed);
						system("pause");
						break;
					}
					else {
						snake.stop = 0;
					}

				}
				if (check == 0) break;
				Sleep(speed);

			}


		}
		if (check == 10) break;
		Sleep(speed);
		
	}
	if (snake.endgame == 1) {
		fstream fplayer;
		fplayer.open(playerPath, ios::out);
		fplayer << name << "\n" << score;
		fplayer << "\n1";
		fplayer.close();
	}

	score = 0;
	speed = 200;
	inputHighScore(highscore);

}
