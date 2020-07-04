#pragma once
#include<iostream>
#include"console.h"
#include<windows.h>
#include"conio.h"
#include<time.h>
#include"fstream"
#include<string>
#include<vector>
using namespace std;

enum Status { UP, DOWN, LEFT, RIGHT };
struct coordinates
{
	int x, y;
};
struct Snake
{
	coordinates element[100];
	int length;
	Status status;
	bool stop = 0;
	bool endgame = 0;
};
struct Food
{
	coordinates f;
};
// Vẽ snake
void creatSnake(Snake& snake, Food& food);
// Chuyển hướng snake khi có phím nhập vào
void move_control(Snake& snake);
void Nocursortype();
// Vẽ khung giới thiệu game và khung trò chơi
void drawTemp();

//In ra lựa chọn chức năng game
void drawOption(char &choose);

//In ra kết quả khi người chơi thua
void drawGameOver(int score);

//Khởi tạo cổng khi ăn được 4 food, vẽ cổng
coordinates createGate();
void drawGate(coordinates pos);

//Hiển thị snake khi snake di chuyển ăn food
void displaySnake(Snake snake, Food food, int score, int& highscore,string list);
// Hiển thị snake khi snake di chuyển để vào cổng
void displaySnake_Gate(Snake snake, coordinates pos, int score, int& highscore);

// Xử lí khi snake ăn food, tự ăn chính mình, va vào tường
int hanling(Snake& snake, Food& food, int& speed, int& score,int &countFood);

//Xử lí khi snake vào cổng, va vào cổng, va vào tường, tự ăn chính mình
int hanling_gate(Snake& snake, coordinates pos, int& speed, int& score, int& countFood);
//Lấy highscore từ dile highscore, in highscore ra file mỗi khi có điểm cao hơn highscore
int highScore();
void inputHighScore(int& highscore);
// In ra hướng dẫn trò chơi
void toGuide();

string checkPlayerName();
void saveGame(string playerPath,Snake snake, string name, int score);