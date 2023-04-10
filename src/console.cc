#include <iostream>
#include <windows.h>
#include <employee2/employee2.h>
#include <stdexcept>
#include <string>


void menu() {
	system("cls");
	cout << "Здравствуйте! Введите цифру от 1 до 6" << endl;
	cout << "1 - Вставить элемент в список по указанному индексу" << endl;
	cout << "2 - Удалить элемент из списка по указанному индексу" << endl;
	cout << "3 - Вывести список на экран" << endl;
	cout << "4 - Поиск в списке первого сотрудника с максимальной заработной платой" << endl;
	cout << "5 - Расчёт заработной платы" << endl;
	cout << "6 - Завершить программу" << endl;
	cout << "> ";
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	EmployeeList EL = EmployeeList();
	Employee item = Employee();
	int input = 0;
	int idx;
	while (input != 6) {
		menu();
		cin >> input;
		switch (input) {
		case 1:
			system("cls");
			EL.show_all();
			cout << "Введите индекс: ";
			cin >> idx;
			cin >> item;
			EL.add_item(idx, item);
			break;
		case 2:
			system("cls");
			EL.show_all();
			cout << "Введите индекс: ";
			cin >> idx;
			EL.del_item(idx);
			break;
		case 3:
			system("cls");
			EL.show_all();
			break;
		case 4:
			system("cls");
			EL.show_all();
			idx = EL.find_with_max_salary();
			cout << "Индекс работника с максимальной заработной платой: " << idx << endl;
			break;
		case 5:
			system("cls");
			EL.show_all();
			cout << "Введите индекс: ";
			cin >> idx;
			EL[idx]->compute_salary();
			cout << "Заработная плата: " << EL[idx]->compute_salary() << endl;
			break;
		}
		if (input != 6)
			system("pause");
	}
}