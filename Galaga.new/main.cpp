#include <iostream>
#include "func.h"
using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");

	cout << "����������� ��� � Galaga!\n";
	cout << "���������� ���������:\n" <<
		"A - �������� �����\n" <<
		"D - �������� ������\n" <<
		"W - �������\n" <<
		"P - ������������ ����\n" <<
		"Q - ����� �� ����\n";
	system("pause");
	main_loop();

	return 0;
}