#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<locale>
#include<windows.h>
#include <vector>
#include<iomanip>
#include"Console.h"
#include"Supplier.h"
#include"Toy.h"
#include"Toy_basket.h"
#include"Shop_toy.h"
#include"Shipping.h"
using namespace std;
class User:public Toy
{
public:
	std::string name_toy;
	std::string charact;
	std::string seller;
	int year;
	int kol_toy = 0;
	int price = 0;
	std::string delivery;
	std::string type;

	void Search_Toy() {
		system("color b");
		int trueSearch = 0, choice;
		std::string NewSeller;
		std::string NewToy, Newtype;
		ifstream fin;
		fin.open("Товары.txt");
		cout << "1 - Поиск по названию\n2 - Поиск по продавцу\n3 - Фильтрация по возрастной границе\n4-Поиск по виду игрушки";
		cin >> choice;
		while (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
			cout << "Введите корректное значение!\n";
			cin.clear();
			cin.ignore(32767, '\n');
			cin >> choice;
		}
		vector<User> foundToys;
		if (choice == 1) {
			bool check_fio = true;
			while (check_fio) {
				cout << "Введите наименование игрушки: ";
				cin >> NewToy;
				check_fio = false;
				for (int i = 0; i < NewToy.size(); i++) {
					if (int(NewToy[i]) < -64 || int(NewToy[i]) > -1) {
						check_fio = true;
						break;
					}
				}
			}
			while (fin.peek() != EOF)
			{
				User toy;
				fin >> toy.name_toy;
				fin.get();
				fin >> toy.charact;
				fin.get();
				fin >> toy.price;
				fin.get();
				fin >> toy.kol_toy;
				fin.get();
				fin >> toy.year;
				fin.get();
				fin >> toy.seller;
				fin.get();
				fin >> toy.delivery;
				fin.get();
				fin >> toy.type;
				fin.get();
				if (NewToy == toy.name_toy)
				{
					foundToys.push_back(toy);
				}
			}
		}
		else if (choice == 2) {
			bool check1 = true;
			while (check1) {
				cout << "Введите имя продавца:\n";
				cin >> NewSeller;
				check1 = false;
				for (int i = 0; i < NewToy.size(); i++) {
					if (int(NewSeller[i]) < -64 || int(NewSeller[i]) > -1) {
						check1 = true;
						break;
					}
				}
			}
			while (fin.peek() != EOF)
			{
				User toy;
				fin >> toy.name_toy;
				fin.get();
				fin >> toy.charact;
				fin.get();
				fin >> toy.price;
				fin.get();
				fin >> toy.kol_toy;
				fin.get();
				fin >> toy.year;
				fin.get();
				fin >> toy.seller;
				fin.get();
				fin >> toy.delivery;
				fin.get();
				fin >> toy.type;
				fin.get();
				if (toy.seller.find(NewSeller) == 0)
				{
					foundToys.push_back(toy);
				}
			}
		}
		else {
			Filtr_year();
			trueSearch = 2;
		}
		if (choice == 4) {
			bool check5 = true;
			while (check5) {
				cout << "Введите вид игрушки:\n";
				cin >> Newtype;
				check5 = false;
				for (int i = 0; i < Newtype.size(); i++) {
					if (int(Newtype[i]) < -64 || int(Newtype[i]) > -1) {
						check5 = true;
						break;
					}
				}
			}
			while (fin.peek() != EOF)
			{
				User toy;
				fin >> toy.name_toy;
				fin.get();
				fin >> toy.charact;
				fin.get();
				fin >> toy.price;
				fin.get();
				fin >> toy.kol_toy;
				fin.get();
				fin >> toy.year;
				fin.get();
				fin >> toy.seller;
				fin.get();
				fin >> toy.delivery;
				fin.get();
				fin >> toy.type;
				fin.get();
				if (toy.type.find(Newtype) == 0)
				{
					foundToys.push_back(toy);
				}
			}
		}
		if (foundToys.empty()) {
			cout << "Товары не найдены!" << endl;
		}
		else {
			cout << "Найденные игрушки:" << endl;
			for (const auto& toy : foundToys) {
				cout << "Название игрушки: " << toy.name_toy << "\n";
				cout << "Описание: " << toy.charact << "\n";
				cout << "Цена: " << toy.price << "\n";
				cout << "Количество: " << toy.kol_toy << "\n";
				cout << "Рек. возраст: " << toy.year << "\n";
				cout << "Изготовитель: " << toy.seller << "\n";
				cout << "Доставка: " << toy.delivery << "\n";
				cout << "Вид: " << toy.type << "\n";
				cout << "-----------------------------------" << endl;
				cout << endl;
			}
		}
		fin.close();
		system("pause");
		system("cls");
	}
	void Filtr_year()
	{
		system("color b");
		int Firstyear, Lastyear;
		vector<User> Array;
		vector<User> arr;
		bool check = true;
		while (check)
		{
			cout << "Введите возраст, с которого хотите искать (от 0 до 17): ";
			cin >> Firstyear;
			if (Firstyear >= 0 && Firstyear < 18 || Firstyear == '\n')
				check = false;
		}
		bool check1 = true;
		while (check1) {
			cout << "Введите возраст, до которого хотите искать (от " << Firstyear << " до 17):";
			cin >> Lastyear;
			if (Lastyear > Firstyear && Lastyear < 18)
				check1 = false;
		}
		ifstream fin;
		fin.open("Товары.txt");
		while (fin.peek() != EOF)
		{
			fin >> this->name_toy;
			fin.get();
			fin >> this->charact;
			fin.get();
			fin >> this->price;
			fin.get();
			fin >> this->kol_toy;
			fin.get();
			fin >> this->year;
			fin.get();
			fin >> this->seller;
			fin.get();
			fin >> this->delivery;
			fin.get();
			fin >> this->type;
			fin.get();
			Array.push_back(*this);
		}
		fin.close();
		size_t size = Array.size();
		User temp;
		for (int i = 0; i < size; i++)
		{
			for (int j = i + 1; j < size; j++) {
				if (Array[i].year > Array[j].year) {
					temp = Array[i];
					Array[i] = Array[j];
					Array[j] = temp;
				}
			}
		}
		for (int i = 0; i < size; i++) {
			if (Array[i].year >= Firstyear && Array[i].year <= Lastyear)
				arr.push_back(Array[i]);
		}
		cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		cout << "|" << setw(14) << "Название" << setw(5) << "|" << setw(14) << "Описание" << setw(5) << "|" << setw(14) << "Цена" << setw(5) << "|" << setw(14) << "Количесвто<" << setw(5) << "|" << setw(14) << "Возраст" << setw(5) << "|" << setw(14) << "Имя продавца " << setw(5) << "|" << setw(14) << "Доставка" << setw(5) << "|" << setw(14) << "Вид" << setw(5) << "|\n";
		cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		for (int i = 0; i < arr.size(); i++) {
			cout << "|" << setw(14) << arr[i].name_toy << setw(5) << "|" << setw(14) << arr[i].charact << setw(5) << "|" << setw(14) << arr[i].price << setw(5) << "|" << setw(14) << arr[i].kol_toy << setw(5) << "|" << setw(14) << arr[i].year << setw(5) << "|" << setw(14) << arr[i].seller << setw(5) << "|" << setw(14) << arr[i].delivery << setw(5) << "|" << setw(14) << arr[i].type << setw(5) << "|" "\n";
			cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		}
	}
	void ReturnToy()
	{
		system("color b");
		string toyName;

		cout << "Введите название игрушки, которую хотите вернуть: ";
		cin >> toyName;
		ifstream inputFile("Товары.txt");
		vector<User> toys;

		if (!inputFile)
		{
			cout << "Ошибка открытия файла." << endl;
			system("pause");
			return;
		}

		User toy;
		bool found = false;

		while (inputFile >> toy.name_toy >> toy.charact >> toy.price >> toy.kol_toy >> toy.year >> toy.seller >> toy.delivery >> toy.type)
		{
			if (toy.name_toy == toyName)
			{
				found = true;
				toy.kol_toy++; // Увеличиваем количество возвращаемой игрушки
			}

			toys.push_back(toy);
		}

		inputFile.close();

		if (!found)
		{
			cout << "Такой игрушки нет!" << endl;
			system("pause");
			return;
		}

		ofstream outputFile("Товары.txt");

		if (!outputFile)
		{
			cout << "Ошибка открытия файла." << endl;
			return;
		}

		for (const User& t : toys)
		{
			outputFile << t.name_toy << endl; // Исправлено: использование переменной t
			outputFile << t.charact << endl;
			outputFile << t.price << endl;
			outputFile << t.kol_toy << endl;
			outputFile << t.year << endl;
			outputFile << t.seller << endl;
			outputFile << t.delivery << endl;
			outputFile << t.type << endl;
		}

		outputFile.close();

		cout << "Вы успешно вернули игрушку: " << toyName << endl;
		system("pause");
	}
	inline void Menu_Toy_user() {
		system("cls");
		bool exit = true;
		Supplier s;
		Shop m;
		Toy_bascket b;
		Shipping d;
		system("cls");
		ConsoleCursorVisible(false, 100);
		std::string Menu[] = { "Просмотр всех игрушек", "Поиск игрушки", "Корзина","Вернуть игрушку","Просмотреть информацию о поставщиках","Просмотреть информацию о физических точках магазина","Оформление доставки","Назад в главное меню"};
		int active_menu = 0;
		char ch;
		while (exit == true)
		{
			int x = 45, y = 0;
			GoToXY(x, y);
			y = 13;
			GoToXY(x, y);
			for (int i = 0; i < size(Menu); i++)
			{
				if (i == active_menu) 	SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
				else 	SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_BLUE);
				GoToXY(x, y++);
				cout << Menu[i] << endl;
			}
			ch = _getch();
			if (ch == -32) ch = _getch();
			switch (ch)
			{
			case escape:
				exit = false;
			case up:
				if (active_menu > 0)
					--active_menu;
				break;
			case down:
				if (active_menu < size(Menu) - 1)
					++active_menu;
				break;
			case enter:
				switch (active_menu)
				{
				case 0:
					system("CLS");
					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
					View_Toy();
					system("CLS");
					break;
				case 1:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
					Search_Toy();
					system("CLS");
					break;
				case 2:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
					b.Menu_bascket();
					system("CLS");
					break;

				case 3:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
					ReturnToy();
					system("CLS");
					break;
				case 4:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
					s.View_Supplier();
					system("CLS");
					break;
				case 5:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
					m.View_Shop();
					system("CLS");
					break;
				case 6:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
					d.fillShippingForm();
					system("CLS");
					break;
				case 7:
					exit = false;
					system("cls");
					break;
				}
				break;
			}
		}
	}


};
