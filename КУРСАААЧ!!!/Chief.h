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
#include"Supplier.h"
#include"Console.h"
#include "Admin.h"
#include"Toy_basket.h"
#include"Shop_toy.h"
#include"Toy.h"
#include"Shipping.h"

using namespace std;
class Chief:public Admin
{
public:
	string pass_Admin;
	string login_Admin;
	string User = "User.txt";
	string Admin = "Admin.txt";
	
	
	void Registr_shop_admin()
	{
		system("color bb");
		ofstream admin;
		admin.open(Admin, fstream::in | fstream::out | fstream::app);
		if (!admin.is_open())
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
			admin << log_cheker << endl;
			admin << pass_cheker << endl;
			admin.close();
			cout << "Регистрация прошла успешно!" << endl;
			system("pause");
			system("cls");
			
		}	
		admin.close();
	}
	void delete_Admin()
	{
		system("color b");
		vector <Chief> Array;

		ifstream fin;
		fin.open("Admin.txt");
		while (fin >> login_Admin >> pass_Admin)
		{
			Chief admin;
			admin.login_Admin = login_Admin;
			admin.pass_Admin = pass_Admin;

			Array.push_back(admin);
			cout << "Логин: " << admin.login_Admin << endl;
		}
		fin.close();
		fin.close();

		size_t size = Array.size();
		int n = -1;
		std::string tmp;
		bool checkt = true;
		while (checkt)
		{
			cout << "Введите логин админа, которого хотите удалить: ";
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
			if (Array[j].login_Admin == tmp)
			{
				n = j;
				size--;
				for (int i = n; i < size; i++)
					Array[i] = Array[i + 1];
				break;
			}
		}
		if (n == -1) {
			cout << "Такого админа нет!\n";
			_getch();
			return;
		}

		ofstream fout;
		fout.open("Admin.txt");
		for (int j = 0; j < size; j++) {
			fout << Array[j].login_Admin << endl;
			fout << Array[j].pass_Admin << endl;
		}
		fout.close();
	}
	void Menu_Toy_chief() {

		system("cls");
		bool exit = true;
		system("cls");
		Supplier s;
		Shop m;
		Toy t;
		Toy_bascket b;
		Shipping d;
		ConsoleCursorVisible(false, 100);
		std::string Menu[] = { "Просмотр всех игрушек", "Добавление новой игрушки", "Редактирование данных об игрушке", "Удаление игрушки", "Поиск игрушки", "Добавить поставщика","Просмотреть информацию о поставщиках","Добавить в список еще одну физическую точку","Просмотреть информацию о магазинах","Корзина", "Вернуть игрушку","Оформление доставки","Зарегестрировать продавца","Зарегестрировать админа","Удалить покупателя","Удалить продавца","Удалить админа", "Назад в главное меню" };
		int active_menu = 0;
		char ch;
		while (exit == true)
		{
			int x = 45, y = 0;
			GoToXY(x, y);
			y = 9;
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

					m.Add_shop();
					system("CLS");
					break;
				case 8:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);

					m.View_Shop();
					system("CLS");
					break;
				case 9:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
					b.Menu_bascket();
					system("CLS");
					break;
				case 10:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
					ReturnToy();
					system("CLS");
					break;
				case 11:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
					d.fillShippingForm();
					system("CLS");
					break;
				case 12:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
					Registr_shop_assistant();
					system("CLS");
					break;
				case 13:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
					Registr_shop_admin();
					system("CLS");
					break;
				case 14:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
					delete_user();
					system("CLS");
					break;
				case 15:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
					delete_shop_assistant();
					system("CLS");
					break;
				case 16:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
					delete_Admin();
					system("CLS");
					break;
				case 17:
					exit = false;
					system("cls");
					break;
				}
				break;
			}
		}
	}
};