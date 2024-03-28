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
using namespace std;
class Supplier
{
public:
	string name_toy;
	string country_supplier;
	string seller;
	string information;
	string contact;
	string inf_supplier = "Инфо_поставщик.txt";

	inline void Add_Supplier()
	{
		system("color b");
		bool checkt = true;
		while (checkt)
		{
			cout << "Введите название страны: ";
			cin >> country_supplier;
			checkt = false;
			for (int i = 0; i < country_supplier.size(); i++)
			{
				if (int(country_supplier[i]) < -64 || int(country_supplier[i]) > -1)
				{
					checkt = true;
					break;
				}
			}
		}

		bool check3 = true;
		cin.ignore();
		while (check3)
		{
			cout << "Напишите небольшую характеристику поставщику: " << endl;
			getline(cin, information);
			check3 = false;
			for (int i = 0; i < information.size(); i++)
			{
				if (int(information[i]) < -64 || int(information[i]) > -1)
				{
					check3 = true;
					break;
				}
			}
		}

		bool check1 = true;
		while (check1)
		{
			cout << "Введите название фирмы поставщика: \n";
			cin >> seller;
			check1 = false;
			for (int i = 0; i < seller.size(); i++)
			{
				if (int(seller[i]) < -64 || int(seller[i]) > -1)
				{
					check1 = true;
					break;
				}
			}
		}

		bool check5 = true;
		while (check5)
		{
			cout << "Введите контактные данные: \n";
			cin >> contact;
			check5 = false;
			for (int i = 0; i < contact.size(); i++)
			{
				if (int(contact[i]) < -64 || int(contact[i]) > -1)
				{
					check5 = true;
					break;
				}
			}
		}

		ofstream fout;
		fout.open("Поставщик.txt", fstream::in | fstream::out | fstream::app);
		fout << country_supplier << endl;
		fout << seller << endl;
		fout << contact << endl;
		fout << information << endl;
		fout.close();

		ofstream fouts;
		fouts.open(inf_supplier, fstream::in | fstream::out | fstream::app);
		fouts << "|" << setw(10) << "Страна поставщик" << setw(10) << "|" << setw(20) << "Характеристику поставщика" << setw(20) << "|" << setw(10) << "Фирма поставщик" << setw(10) << "|" << setw(10) << "Контактная информация" << setw(10) << "|\n";
		fouts << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		fouts << "|" << setw(10) << country_supplier << setw(10) << "|" << setw(20) << information << setw(20) << "|" << setw(10) << seller << setw(10) << "|" << setw(10) << contact << setw(10) << "|\n";
		fouts << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		fouts.close();

		system("pause");
		system("cls");
	}
	 inline void View_Supplier() {
		system("color b");
		ifstream fin;
		fin.open("Поставщик.txt");
		cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		cout << "|" << setw(10) << "Страна поставщик" << setw(10) << "|" << setw(20) << "Характеристику поставщика" << setw(20) << "|" << setw(10) << "Фирма поставщик" << setw(10) << "|" << setw(10) << "Контактная информация" << setw(10) << "|\n";
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		while (fin.peek() != EOF) {
			fin >> this->country_supplier;
			fin.get();
			fin >> this->information;
			fin.get();
			fin >> this->seller;
			fin.get();
			fin >> this->contact;
			fin.get();
			cout << "|" << setw(10) << this->country_supplier << setw(10);
			cout << "|" << setw(20) << this->information << setw(20);
			cout << "|" << setw(10) << this->seller << setw(10);
			cout << "|" << setw(10) << this->contact << setw(10) << "\n";
			cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		}
		fin.close();
		system("pause");
		system("cls");
	}

};
