#include <ncurses.h>

int main() {
	int display_char = '@';
	int max_row, max_col;

	int KEY_ESC_1 = 0x1B;
	int KEY_ESC_2 = 0x5B;

	int UP_KEY = 0x41, LEFT_KEY = 0x44, RIGHT_KEY = 0x43, DOWN_KEY = 0x42;

	//Prepare the screen
	initscr();
	keypad(stdscr, true);				//enable keypad
	noecho();							//don't print typed chars
	raw();								//don't wait for return char to take input
	getmaxyx(stdscr, max_row, max_col); //store screen size
	curs_set(0); 						//hide the cursor

	//Spawn player in middle
	int cur_row, cur_col; //To store player location
	cur_row = max_row/2;
	cur_col = max_col/2;
	move(cur_row, cur_col);
	printw("%c",display_char);
	refresh();

	int input_char = getch();
	//Game loop
	while(input_char != 27){

		//Change loc if in bounds
		if(input_char == KEY_UP && cur_row > 0)
			cur_row--;

		if(input_char == KEY_LEFT && cur_col > 0)
			cur_col--;

		if(input_char == KEY_RIGHT && cur_col < (max_col-1))
			cur_col++;

		if(input_char == KEY_DOWN && cur_row < (max_row-1))
			cur_row++;


		clear();
		move(cur_row, cur_col);
		printw("%c", display_char);
		input_char = getch();
	}


	//Exit
	endwin();



	return 0;
}