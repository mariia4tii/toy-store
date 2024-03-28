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
class Shop
{
public:
	string adress;
	string chief_shop;
	string contact;
	void Add_shop()
	{
		system("color bb");
		bool checkt = true;
		while (checkt)
		{
			cout << "Введите адрес торговой точки: ";
			cin >> adress;
			checkt = false;
			for (int i = 0; i < adress.size(); i++)
			{
				if (int(adress[i]) < -64)
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
			cout << "Введите ФИО директора торговой точки:" << endl;
			cin >> chief_shop;
			check3 = false;
			for (int i = 0; i < chief_shop.size(); i++)
			{
				if (int(chief_shop[i]) < -64)
				{
					check3 = true;
					break;
				}
			}
		}

		bool check1 = true;
		while (check1)
		{
			cout << "Введите контактные данные торговой точки: \n";
			cin >> contact;
			check1 = false;
			for (int i = 0; i < contact.size(); i++)
			{
				if (int(contact[i]) < -64)
				{
					check1 = true;
					break;
				}
			}
		}
		ofstream fout;
		fout.open("Физические точки магазина.txt", fstream::in | fstream::out | fstream::app);
		fout << adress << endl;
		fout << chief_shop << endl;
		fout << contact << endl;
		fout.close();
	}
	void View_Shop()
	{
		system("color b");
		ifstream fin;
		fin.open("Физические точки магазина.txt");
		cout << "------------------------------------------------------------------------------------------------------------------------------------------------\n";
		cout << "|" << setw(14) << "Адресс" << setw(5) << "|" << setw(14) << "Директор магазина" << setw(5) << "|" << setw(14) << "Контактные данные" << setw(5) <<"|\n";
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------\n";
		while (fin.peek() != EOF)
		{
			fin >> this->adress;
			fin.get();
			fin >> this->chief_shop;
			fin.get();
			fin >> this->contact;
			fin.get();
			cout << "|" << setw(14) << this->adress << setw(5);
			cout << "|" << setw(14) << this->chief_shop << setw(5);
			cout << "|" << setw(14) << this->contact << setw(5)<< "|\n";
			cout << "-----------------------------------------------------------------------------------------------------------------------\n";
		}
		fin.close();
		system("pause");
		system("cls");
	}

};
