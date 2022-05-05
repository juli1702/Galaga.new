#include <iostream>
#include "func.h"
using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Привет! Приветствую тебя в Galaga!\n";
	cout << "Управляй клавишами A-влево, D - вправо,  W - выстрел, Q - выход из игры\n";
	system("pause");
	image();
	input();



	return 0;
}