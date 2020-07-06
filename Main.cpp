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
			char* name = new char;
			int countFood = 0;
			creatSnake(snake, food);
			printListPlayer();
			loadSavedGame(snake, name,score, food,speed);
			playSavedGame(snake, food, score, highscore, list, countFood, speed, check, name);
			
		}
		 else if (choose == 'N' || choose == 'n')// Nếu người dùng chọn N thì sẽ tạo game mới
		 {
			
			int countFood = 0;
			creatSnake(snake, food);
			playNewGame(snake, food, score, highscore, list, countFood, speed, check);
			
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