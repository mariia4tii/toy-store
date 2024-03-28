#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<locale>
#include<windows.h>
#include <vector>
#include<iomanip>
#include<vector>
#include <iomanip>
#include"User.h"
#include"Supplier.h"
#include"Console.h"
#include"Shop_assistant.h"
#include"Shop_toy.h"
#include"Toy.h"
#include"Shipping.h"
using namespace std;
class Admin: public Shop_assistant
{
public:
	string pass_assistant;
	string log_assistant;
	string Shop_assistant = "Продавец.txt";
	void Registr_shop_assistant()
	{
		system("color bb");
		ofstream assistant;
		assistant.open(Shop_assistant, fstream::in | fstream::out | fstream::app);
		if (!assistant.is_open())
		{
			cout << "Ошибка!" << endl;
		}
		else
		{
			cout << "-----------Регистрация-------------" << endl;
			string log_cheker;
			string pass_cheker;
			cout << "Введите логин: ";
			cin >> log_cheker;
			cout << "Введите пароль: ";
			cin >> pass_cheker;
			assistant << log_cheker << endl;
			assistant << pass_cheker << endl;
		
			cout << "Регистрация прошла успешно!" << endl;
			system("pause");
			system("cls");

		}
			assistant.close();
	}
	void delete_shop_assistant()
	{
		system("color b");
		vector <Admin> Array;

		ifstream fin;
		fin.open("Продавец.txt");
		while (fin >> log_assistant >> pass_assistant)
		{
			Admin assistant;
			assistant.log_assistant = log_assistant;
			assistant.pass_assistant = pass_assistant;

			Array.push_back(assistant);
			cout << "Логин: " << assistant.log_assistant << endl;
		}
		fin.close();

		size_t size = Array.size();
		int n = -1;
		std::string tmp;
		bool checkt = true;
		while (checkt)
		{
			cout << "Введите логин продавца, которого хотите удалить: ";
			cin >> tmp;
			checkt = false;
			for (int i = 0; i < tmp.size(); i++)
			{
				if (int(tmp[i]) < -64 || int(tmp[i]) > -1)
				{
					checkt = true;
					break;
				}
			}
		}
		for (int j = 0; j < Array.size(); j++)
		{
			if (Array[j].log_assistant == tmp)
			{
				n = j;
				size--;
				for (int i = n; i < size; i++)
					Array[i] = Array[i + 1];
				break;
			}
		}
		if (n == -1) {
			cout << "Такого продавца нет!\n";
			_getch();
			return;
		}

		ofstream fout;
		fout.open("Продавец.txt");
		for (int j = 0; j < size; j++) {
			fout << Array[j].log_assistant << endl;
			fout << Array[j].pass_assistant << endl;
		}
		fout.close();
	}

	void Menu_Toy_admin() {

		system("cls");
		bool exit = true;
		system("cls");
		Supplier s;
		Shop m;
		Toy t;
		Toy_bascket b;
		Shipping d;
		ConsoleCursorVisible(false, 100);
		std::string Menu[] = { "Просмотр всех игрушек", "Добавление новой игрушки", "Редактирование данных об игрушке", "Удаление игрушки", "Поиск игрушки", "Добавить поставщика","Просмотреть информацию о поставщиках","Просмотреть информацию о физических точках магазина","Корзина", "Вернуть игрушку","Оформление доставки","Зарегестрировать продавца","Удалить покупателя","Удалить продавца", "Назад в главное меню" };
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
					Add_toy();
					system("CLS");
					break;
				case 2:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
					Edit_Toy();
					system("CLS");
					break;

				case 3:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
					delete_toy();
					system("CLS");
					break;
				case 4:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
					Search_Toy();
					system("CLS");
					break;
				case 5:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
					
					s.Add_Supplier();
					system("CLS");
					break;
				case 6:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);

					s.View_Supplier();
					system("CLS");
					break;
				case 7:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);

					m.View_Shop();
					system("CLS");
					break;
				case 8:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
					b.Menu_bascket();
					system("CLS");
					break;
				case 9:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
					ReturnToy();
					system("CLS");
					break;
				case 10:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
					d.fillShippingForm();
					system("CLS");
					break;
				case 11:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
					Registr_shop_assistant();
					system("CLS");
					break;
				case 12:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
					delete_user();
					system("CLS");
					break;
				case 13:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
					delete_shop_assistant();
					system("CLS");
					break;
				case 14:
					exit = false;
					system("cls");
					break;
				}
				break;
			}
		}
	}
	

};
