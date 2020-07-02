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
		creatSnake(snake, food);
		if (choose == 'G' || choose == 'g') {// nếu người dùng chọn G thì sẽ in ra hướng dẫn trò chơi
			gotoXY(11, 17);
			toGuide();
			system("pause");
			system("cls");

		}
		 else if (choose == 'T' || choose == 't')// Nếu người dùng chọn T thì sẽ in ra danh sách tên các người chơi đã từng chơi để tiếp tục chơi
		{
			gotoXY(31, 16);
			cout << " High Score: " << highScore() << endl;
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
			system("pause");
			system("cls");
			continue;
		}
		 else if (choose == 'N' || choose == 'n')// Nếu người dùng chọn N thì sẽ tạo game mới
		 {
			int countFood = 0;
			string player;
			gotoXY(20, 15);
			cin.ignore();
			cout << "Your name: ";
			getline(cin,player);
			string playerPath = player + ".txt";
			fstream fplayer;
			fplayer.open(playerPath, ios::out);
			 while (1)
			 {
				 displaySnake(snake, food, score, highscore,list);
				 move_control(snake);
				 check = hanling(snake, food, speed, score,countFood);
				
				 if (check == 1)
				 {
					 drawGameOver(score);
					 check = 10;
					 break;

				 }
				 if (check == 2) {

					 int mn;
					 gotoXY(75, 14);
					 cout << "Ban co muon tiep tuc?" << endl;
					 gotoXY(75, 15);
					 cout << "1: Co" << endl;
					 gotoXY(75, 16);
					 cout << "2 : Khong" << endl;
					 gotoXY(75, 17);
					 cout << "Lua chon : ";
					 cin >> mn;
					 if (mn == 2) {
						 gotoXY(30, 14);
						 cout << "Player: " << player << endl;
						 gotoXY(30, 15);
						 cout << "Score: " << score << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
						 check = 10;
						 system("pause");
						 break;
					 }
					 else {
						 snake.stop = 0;
					 }
				 }
				 if (check == 10) break;

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
							 check = 10;
						 }
						 if (check == 10) break;
						 if (check == 2) {

							 int mn;
							 gotoXY(75, 14);
							 cout << "Ban co muon tiep tuc?" << endl;
							 gotoXY(75, 15);
							 cout << "1: Co" << endl;
							 gotoXY(75, 16);
							 cout << "2 : Khong" << endl;
							 gotoXY(75, 17);
							 cout << "Lua chon : ";
							 cin >> mn;
							 if (mn == 2) {
								 gotoXY(30, 14);
								 cout << "Player: " << player << endl;
								 gotoXY(30, 15);
								 cout << "Score: " << score << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
								 check = 10;
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
			 }
			 fplayer << player <<"\n"<< score;
			 fplayer.close();
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