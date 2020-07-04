#include"Header.h"

using namespace std;


int main()
{
	
	srand(time(NULL));
	Nocursortype();
	// Chuỗi mssv của các thành viên trong nhóm
	string list =  "171272318120287181204181912052219120601";
	int check = 0;
	Snake snake;
	Food food;
	int speed = 200;
	int score = 0, highscore = highScore();
	char choose;
	
	do {
		
		drawTemp();
		drawOption(choose);
		
		if (choose == 'G' || choose == 'g') {// nếu người dùng chọn G thì sẽ in ra hướng dẫn trò chơi
			
			gotoXY(11, 17);
			toGuide();
			system("pause");
			system("cls");

		}
		 else if (choose == 'T' || choose == 't')// Nếu người dùng chọn T thì sẽ in ra danh sách tên các người chơi đã từng chơi để tiếp tục chơi
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
				cout <<temp;
				index++;
			}
			listm.close();
			
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
			system("pause");
			system("cls");
			continue;
		}
		 else if (choose == 'N' || choose == 'n')// Nếu người dùng chọn N thì sẽ tạo game mới
		 {
			
			int countFood = 0;
			fstream listx;
			listx.open("player.txt", ios::out);
			ofstream listm;
			listm.open("player.txt", ios::app);

			string player = checkPlayerName();
			listm << player;
			listm.close();
			string playerPath = (string)player + ".txt";
			creatSnake(snake, food);
			 while (1)
			 {
				 
				 displaySnake(snake, food, score, highscore,list);
				 move_control(snake);
				 check = hanling(snake, food, speed, score,countFood);
				
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
						 cout << "Player: " << player << endl;
						 gotoXY(30, 15);
						 cout << "Score: " << score << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
						 check = 10;
						 saveGame(playerPath, snake, player, score);
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
								 saveGame(playerPath, snake, player, score);
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
		else if (choose == 'Q' || choose == 'q')
		 {
			 return 0;
		 }
		check = 0;
		 system("cls");
		
	} while (choose!='q' && choose != 'Q');
	return 0;
}