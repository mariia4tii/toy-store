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
#include <conio.h>
#include"User.h"
#include"Supplier.h"
#include"Shop_toy.h"
#include"Toy_basket.h"
#include"Toy.h"
#include"Shipping.h"
using namespace std;
class Shop_assistant :public User
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
	std::string inf_report = "�����.txt";
	std::string log_user;
	std::string pass_user;

	
	void delete_toy()
	{
		system("color b");
		vector <Shop_assistant> Array;
		ifstream fin;
		fin.open("������.txt");
		while (fin.peek() != EOF)
		{
			Shop_assistant toy; 
			fin >> toy.name_toy;
			fin >> toy.charact;
			fin >> toy.price;
			fin >> toy.kol_toy;
			fin >> toy.year;
			fin >> toy.seller;
			fin >> toy.delivery;
			fin >> toy.type;
			Array.push_back(toy);
			cout << "���: " << toy.name_toy << endl;
		}
		fin.close();

		size_t size = Array.size();
		int n = -1;
		std::string tmp;
		bool checkt = true;
		while (checkt)
		{
			cout << "������� �������� �������, ������� ������ �������: ";
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
			if (Array[j].name_toy == tmp)
			{
				n = j;
				size--;
				for (int i = n; i < size; i++)
					Array[i] = Array[i + 1];
				break; 
			}
		}
		if (n == -1) {
			cout << "����� ������� ���!\n";
			_getch();
			return;
		}

		ofstream fout;
		fout.open("������.txt");
		for (int j = 0; j < size; j++) {
			fout << Array[j].name_toy << endl;
			fout << Array[j].charact << endl;
			fout << Array[j].price << endl;
			fout << Array[j].kol_toy << endl;
			fout << Array[j].year << endl;
			fout << Array[j].seller << endl;
			fout << Array[j].delivery << endl;
			fout << Array[j].type << endl;
		}
		fout.close();

		ofstream foutOtch;
		foutOtch.open(inf_report);
		foutOtch << "-----------------------------------------------------------------------------------------------------------------------------------------------\n";
		foutOtch << "|" << setw(14) << "��������" << setw(5) << "|" << setw(14) << "��� �������� " << setw(5) << "|" << setw(14) << "����������" << setw(5) << "|" << setw(14) << "����" << setw(5) << "|" << setw(14) << "���. �������" << setw(5) << " |" << setw(14) << "���:" << setw(5) << "|\n";
		foutOtch << "------------------------------------------------------------------------------------------------------------------------------------------------\n";
		for (int j = 0; j < size; j++) {
			foutOtch << "|" << setw(10) << Array[j].name_toy << setw(9) << "|";
			foutOtch << "|" << setw(10) << Array[j].charact << setw(10) << "|" << setw(10) << Array[j].price << setw(10) << "|" << setw(10) << Array[j].kol_toy << setw(10) << "|" << setw(10) << Array[j].year << setw(10) << "|" << setw(10) << Array[j].seller << setw(10) << "|" << setw(10) << Array[j].delivery << setw(10) << "|" << setw(10) << Array[j].type << setw(10) << "|\n";
			foutOtch << "--------------------------------------------------------------------------------------------------------------------------------------------\n";
		}
	}
	void Edit_Toy() {
		system("color b");
		vector<Shop_assistant>Array;
		ifstream fin;
		fin.open("������.txt");
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
			fin >> this->type;
			fin.get();
			Array.push_back(*this);
			cout << "���:" << this->name_toy << endl;
		}
		fin.close();
		size_t size = Array.size();
		std::string tmp;
		int n = -1;
		bool check_fio = true;
		while (check_fio) {
			cout << "������� �������� �������, ������ � ������� ������ �������������: ";
			cin >> tmp;
			check_fio = false;
			for (int i = 0; i < tmp.size(); i++) {
				if (int(tmp[i]) < -64 || int(tmp[i]) > -1) {
					check_fio = true;
					break;
				}
			}
		}
		for (int j = 0; j < size; j++) {
			if (Array[j].name_toy == tmp) {
				n = j;
				cout << endl;
				cout << "�������� �������: " << Array[j].name_toy << endl;
				cout << "��������: " << Array[j].charact << endl;
				cout << "����: " << Array[j].price << endl;
				cout << "����������� ������� �� ��������: " << Array[j].year << endl;
				cout << "��������: " << Array[j].seller << endl;
				cout << "��������: " << Array[j].delivery << endl;
				cout << "���: " << Array[j].type << endl;

				system("pause");
				cout << endl;
			}

		}
		if (n == -1)
			cout << "������ ������ ���!" << endl;
		else {
			cout << "1 - �������� �������� �������" << endl;
			cout << "2-�������� �������� ������� " << endl;
			cout << "3 - �������� ���� �������" << endl;
			cout << "4 - �������� ����������� ������� �� ��������" << endl;
			cout << "5 - �������� ��� ��������" << endl;
			cout << "6 - �������� ��������" << endl;
			cout << "7 - �������� ��� �������" << endl;


			int change;
			cin >> change;
			int NewYear, NewPrice;
			std::string NewSeller, Newcharact, Newtype;
			std::string NewnameToy, Newdelivery;

			switch (change) {
			case 1: {
				bool check_fio = true;
				while (check_fio) {
					cout << "������� ����� �������� �������: ";
					cin >> NewnameToy;
					check_fio = false;
					for (int i = 0; i < NewnameToy.size(); i++) {
						if (int(NewnameToy[i]) < -64 || int(NewnameToy[i]) > -1) {
							check_fio = true;
							break;
						}
					}
				}
				Array[n].name_toy = NewnameToy;
				break;
			}
			case 2:
			{
				bool check3 = true;
				while (check3)
				{
					cout << "������� ����� ��������: \n";
					cin.ignore(); // ������������ ���������� ������ ����� ������
					getline(cin, Newcharact);
					check3 = false;
					for (int i = 0; i < Newcharact.size(); i++)
					{
						if (!isalnum(Newcharact[i])) // �������� �� ����� � �����
						{
							check3 = true;
							break;
						}
					}
				}
				Array[n].charact = Newcharact;
				break;
			}

			case 3: {
				bool checkp = true;
				while (checkp) {
					cout << "������� ����� ����: ";
					cin >> NewPrice;
					if (NewPrice > 0)
						checkp = false;
				}
				Array[n].price = NewPrice;
				break;
			}
			case 4: {
				bool check = true;
				while (check) {
					cout << "������� ����� ����������� ������� �� ��������: ";
					cin >> NewYear;
					if (NewYear >= 0 && NewYear < 18)
						check = false;
				}
				Array[n].year = NewYear;
				break;
			}
			case 5: {
				bool check1 = true;
				while (check1) {
					cout << "������� ����� ��� ������������: \n";
					cin >> seller;
					check1 = false;
					for (int i = 0; i < seller.size(); i++) {
						if (int(seller[i]) < -64 || int(seller[i]) > -1) {
							check1 = true;
							break;
						}
					}
				}
				for (int i = 0; i < 13; i++)
				{
					Array[n].seller[i] = NewSeller[i];
				}
				break;
			}
			case 6: {
				bool check6 = true;
				while (check6) {
					cout << "�������� ������ � ��������: ";
					cin >> Newdelivery;
					check6 = false;
					for (int i = 0; i < Newdelivery.size(); i++) {
						if (int(Newdelivery[i]) < -64 || int(Newdelivery[i]) > -1) {
							check6 = true;
							break;
						}
					}
				}
				Array[n].delivery = Newdelivery;
				break;
			}
			case 7: {
				bool check_t = true;
				while (check_t) {
					cout << "������� ����� ��� �������: ";
					cin >> Newtype;
					check_t = false;
					for (int i = 0; i < Newtype.size(); i++) {
						if (int(Newtype[i]) < -64 || int(Newtype[i]) > -1) {
							check_fio = true;
							break;
						}
					}
				}
				Array[n].name_toy = Newtype;
				break;
			}
			default: {
				cout << "����� ������� ���!" << endl;
				break;
			}
			}
			cout << "������ ������� " << tmp << " ���������������!" << endl;
		}
		
		ofstream fout;
		fout.open("������.txt");
		for (int j = 0; j < size; j++) {
			fout << Array[j].name_toy << endl;
			fout << Array[j].charact << endl;
			fout << Array[j].price << endl;
			fout << Array[j].kol_toy << endl;
			fout << Array[j].year << endl;
			fout << Array[j].seller << endl;
			fout << Array[j].delivery << endl;
			fout << Array[j].type << endl;
		}
		fout.close();
		system("pause");
		system("cls");

	}
	void delete_user()
	{
		system("color b");
		vector <Shop_assistant> Array;

		ifstream fin;
		fin.open("User.txt");
		while (fin >> log_user >> pass_user)
		{
			Shop_assistant user;
			user.log_user = log_user;
			user.pass_user = pass_user;

			Array.push_back(user);
			cout << "�����: " << user.log_user << endl;
		}
		fin.close();

		size_t size = Array.size();
		int n = -1;
		std::string tmp;
		bool checkt = true;
		while (checkt)
		{
			cout << "������� ����� ������������, �������� ������ �������: ";
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
			if (Array[j].log_user == tmp)
			{
				n = j;
				size--;
				for (int i = n; i < size; i++)
					Array[i] = Array[i + 1];
				break;
			}
		}
		if (n == -1) {
			cout << "������ ������������ ���!\n";
			_getch();
			return;
		}

		ofstream fout;
		fout.open("User.txt");
		for (int j = 0; j < size; j++) {
			fout << Array[j].log_user << endl;
			fout << Array[j].pass_user << endl;
		}
		fout.close();
	}
	
	void Menu_Toy_assistant() {

		system("cls");
		bool exit = true;
		system("cls");
		Supplier s;
		Shop m;
		Toy t;
		Toy_bascket b;
		Shipping d;
		ConsoleCursorVisible(false, 100);
		std::string Menu[] = { "�������� ���� �������", "���������� ����� �������", "�������������� ������ �� �������", "�������� �������", "����� �������", "����������� ���������� � �����������", "����������� ���������� � ���������� ������ ��������","�������", "������� �������","���������� ��������","������� ������������", "����� � ������� ����" };
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

					s.View_Supplier();
					system("CLS");
					break;
				case 6:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);

					m.View_Shop();
					system("CLS");
					break;
				case 7:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
					b.Menu_bascket();
					system("CLS");
					break;
				case 8:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
					ReturnToy();
					system("CLS");
					break;
				case 9:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
					d.fillShippingForm();
					system("CLS");
					break;
				case 10:
					system("CLS");

					SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
					delete_user();
					system("CLS");
					break;
				case 11:
					exit = false;
					system("cls");
					break;
				}
				break;
			}
		}
	}
};
