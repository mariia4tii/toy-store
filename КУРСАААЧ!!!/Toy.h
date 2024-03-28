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
using namespace std;
class Toy
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
    std::string inf_report = "Отчет.txt";

    void Add_toy()
    {
        system("color bb");
        bool checkt = true;
        while (checkt)
        {
            cout << "Введите наименование товара: ";
            cin >> name_toy;
            checkt = false;
            for (int i = 0; i < name_toy.size(); i++)
            {
                if (int(name_toy[i]) < -64)
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
            cout << "Напишите небольшую характеристику игрушке:" << endl;
            getline(cin, charact);
            check3 = false;
            for (int i = 0; i < charact.size(); i++)
            {
                if (int(charact[i]) < -64)
                {
                    check3 = true;
                    break;
                }
            }
        }

        bool check1 = true;
        while (check1)
        {
            cout << "Введите изготовителя: \n";
            cin >> seller;
            check1 = false;
            for (int i = 0; i < seller.size(); i++)
            {
                if (int(seller[i]) < -64)
                {
                    check1 = true;
                    break;
                }
            }
        }

        bool checkp = true;
        while (checkp)
        {
            cout << "Введите цену игрушки: ";
            cin >> price;
            if (price > 0)
                checkp = false;
        }

        bool checkk = true;
        while (checkk)
        {
            cout << "Введите количество: ";
            cin >> kol_toy;
            if (kol_toy > 0)
                checkk = false;
        }

        bool check = true;
        while (check)
        {
            cout << "Введите минимальную границу по возрасту: ";
            cin >> year;
            if (year >= 0 && year < 100)
                check = false;
        }

        bool check4 = true;
        cin.ignore();
        while (check4)
        {
            cout << "Доставка:" << endl;
            getline(cin, delivery);
            check4 = false;
            for (int i = 0; i < delivery.size(); i++)
            {
                if (int(delivery[i]) < -64)
                {
                    check4 = true;
                    break;
                }
            }
        }

        bool check9 = true;
        cin.ignore();
        while (check9)
        {
            cout << "Введите вид игрушки:" << endl;
            getline(cin, type);
            check9 = false;
            for (int i = 0; i < type.size(); i++)
            {
                if (int(type[i]) < -64)
                {
                    check9 = true;
                    break;
                }
            }
        }

        ofstream fout;
        string filename =  "Товары.txt";
        fout.open(filename, fstream::in | fstream::out | fstream::app);
        fout << name_toy << endl;
        fout << charact << endl;
        fout << price << endl;
        fout << kol_toy << endl;
        fout << year << endl;
        fout << seller << endl;
        fout << delivery << endl;
        fout << type << endl;
        fout.close();

        ofstream foutOtch;
        foutOtch.open(inf_report, fstream::in | fstream::out | fstream::app);
        foutOtch << "|" << setw(10) << name_toy << setw(9) << "|";
        foutOtch << "|" << setw(10) << charact << setw(10) << "|" << setw(10) << price << setw(10) << "|" << setw(10) << kol_toy << setw(10) << "|" << setw(10) << year << setw(10) << "|" << setw(10) << seller << setw(10) << "|" << setw(10) << delivery << setw(10) << "|" << setw(10) << type << setw(10) << "|\n";
        foutOtch << "---------------------------------------------------------------------------------------------------------------------------------------------------\n";
        foutOtch.close();

        system("pause");
        system("cls");
    }
    void View_Toy()
    {
        system("color b");
        string type;
        string filename = "Товары.txt";
        ifstream fin(filename);
        if (!fin)
        {
            cout << "Файлы данного типа игрушек не найдены." << endl;
            return;
        }

        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "|" << setw(10) << "Название" << setw(7) << "|" << setw(10) << "Описание" << setw(7) << "|" << setw(10) << "Цена" << setw(7) << "|" << setw(10) << "Количество" << setw(7) << "|" << setw(10) << "Рек. возраст" << setw(7) << " |" << setw(10) << "Изготовитель" << setw(7) << "|" << setw(10) << "Доставка" << setw(7) << "|" << setw(10) << "Вид игрушки" << setw(7) << "|""\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";

        string name_toy;
        string charact;
        int price;
        int kol_toy;
        int year;
        string seller;
        string delivery;
        string toy_type;

        while (fin >> name_toy >> charact >> price >> kol_toy >> year >> seller >> delivery >> toy_type)
        {
            cout << "|" << setw(10) << name_toy << setw(7);
            cout << "|" << setw(10) << charact << setw(7);
            cout << "|" << setw(10) << price << setw(7);
            cout << "|" << setw(10) << kol_toy << setw(7);
            cout << "|" << setw(10) << year << setw(7);
            cout << "|" << setw(10) << seller << setw(7);
            cout << "|" << setw(10) << delivery << setw(7);
            cout << "|" << setw(10) << toy_type << setw(7) << "|""\n";
            cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------\n";
        }

        fin.close();
        system("pause");
        system("cls");
    }
 };

