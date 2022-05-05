#include "func.h"
#include <iostream>
#include <ctime>
#include <conio.h>
#include "windows.h"
const int rows = 21; // ������ J
const int cols = 21; // ������� I
char field[rows][cols] = {
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',}
};
bool paused = false;
int timer = 0;
int x = cols / 2;
int y = rows / 2;	
char A = field[cols/2][rows-1];
int locW1 = rand() % (cols - 1) + 1;
int locW2 = rand() % (cols - 1) + 1;

//������� ������ ����� � �������
void image() {
	srand(time(NULL));
	system("cls");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (i == 0 || j == 0 || i == cols - 1 || j == rows - 1)
				std::cout << "* ";
			else
				if (i == cols - 3)
					std::cout << "- ";
				else
					if (j == x && i == x * 2 - 1) { // field[10][20] - ����� ����� 
						A = field[cols / 2][rows - 1];
						std::cout << "A ";
					}
					else
						if (i == 1 && j == locW1 || i == 1 && j == locW2)
							std::cout << "w ";
						else
							std::cout << " " << field[i][j];
		}
		std::cout << std::endl;
	}
}
//�������, ������� �������� �� ���������� ��������, ������� �������� ������������ �� ����������
void input() {
	char sym = '1';
	while (sym != 'q' && sym != 'Q') { // Q  - ������� ��� ������ �� ���� 
		if (_kbhit()) {
			sym = _getch();
			switch (sym) {
			case 'a':case 'A': actionleft(); std::cout << "  ����� "; break; // �����
			case 'd': case 'D': actionright(); std::cout << " ������ "; break;// ������
			case 'w': case 'W': std::cout << " �������\n" ; break;
				//case 'm': case 'M':; paused = !paused; break;
				//case 'x': case 'X':; gamestop = true; break;
			}
		}
		if (timer >= 1000 && paused == false) {
			//image();
			timer = 0;
		}
		Sleep(40);
		timer += 40;

	}
}
//�������, � ������� ������� ����� ������� ������� ����� �����
void actionleft() {
	A = { };
	A = field[cols / 2 - 1][rows - 1];
}
//�������, � ������� ������� ����� ������� ������� ����� �����
void actionright() {
	A = { };
	field[cols / 2][rows - 1] = { };
	A = field[cols / 2 + 1][rows - 1];
}