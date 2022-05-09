#include "func.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include "windows.h"

const int ROWS = 21;
const int COLS = 11;
int TIMER = 0;

const int tick = 50;		 // Min delay for user actions
const int W_interval = 1000; // W movement interval
const int min_interval = 2;  // Min W spawn interval value
const int max_interval = 4;  // Max W spawn interval value

char field[ROWS][COLS];		 // Main game field with characters
int score = 0;				 // Destroyed enemies
int A_col; // Character column position
int w_row = ROWS - 2; // shoot position  - позиция выстрела
int Wpos;


// Functions with a main program loop
void main_loop() {
	init_map();
	print_map();
	while (true) {
		if (_kbhit())
			switch (_getch()) {
			case 'a':case 'A': move_left(); print_map(); break;
			case 'd':case 'D': move_right(); print_map(); break;
			case 'w':case 'W': shoot(); bump(); print_map(); delShoot(); break;
			case 'q':case 'Q': std::cout << "\n*GAME OVER!*\nУничтожено вражеских кораблей --> " << score << std::endl; _exit(true); break;
			case 'p':case 'P': system("pause"); break;
			}

		// Random interval from min_interval to max_interval in seconds
		srand(time(NULL));
		int rand_interval = (rand() % (max_interval + 1 - min_interval) + min_interval) * 1000;

		Sleep(20);
		TIMER += tick;
		if (TIMER % W_interval == 0) {
			check_loose();
			W_steps();
			print_map();
		}
		if (TIMER % rand_interval == 0) {
			W_spawn();
		}
	}
}

// Fill the field with empty cells and place the character in the center
void init_map() {
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			field[i][j] = ' ';
	srand(time(NULL));
	A_col = COLS / 2;
	field[ROWS - 1][A_col] = 'A';

}

// Print current field(map) values
void print_map() {
	srand(time(NULL));
	system("cls");
	std::cout << "*GALAGA*\n";
	for (int i = 0; i < ROWS + 2; i++) {
		for (int j = 0; j < COLS + 2; j++)
			if (i == 0 || j == 0 || i == ROWS + 1 || j == COLS + 1)
				std::cout << "# ";
			else
				std::cout << field[i - 1][j - 1] << ' ';
		std::cout << std::endl;
	}
	std::cout << "SCORE: " << score << std::endl;
}

// Move character one cell to the left
void move_left() {
	if (A_col > 0) {
		std::swap(field[ROWS - 1][A_col], field[ROWS - 1][A_col - 1]);
		A_col--;
	}
}

// Move character one cell to the right
void move_right() {
	if (A_col < COLS - 1) {
		std::swap(field[ROWS - 1][A_col], field[ROWS - 1][A_col + 1]);
		A_col++;
	}
}

// Shoot in a straight line
void shoot() {
	for (int i = w_row; i > -1; i--) {
		field[i][A_col] = '.';
		w_row--;
	}

	if (w_row == -1)
		w_row = ROWS - 2;
}
//Shooting clearance
void delShoot() {
	for (int i = 0; i <= w_row; i++) {
		field[i][A_col] = ' ';
	}
}

void W_spawn() {
	srand(time(NULL));
	int Wpos = rand() % COLS;  // Раньше было ROWS
	field[0][Wpos] = 'W';
}

void W_steps() {
	for (int i = ROWS - 2; i >= 0; i--)
		for (int j = COLS - 1; j >= 0; j--)
			if (field[i][j] == 'W')
				std::swap(field[i][j], field[i + 1][j]);

}

// Returns true if there is 'W' in the bottom row
bool check_loose() {
	for (int i = 0; i < COLS; i++)
		if (field[ROWS - 1][i] == 'W')
			return true;
	return false;
}

//
void bump() {
	for (int i = 0; i < COLS; i++) {
		if (field[A_col][i] == 'W')
			score++;
	}
}

