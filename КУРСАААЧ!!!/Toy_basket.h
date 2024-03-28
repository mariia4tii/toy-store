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
#include"GiftCard.h"
using namespace std;
class Toy_bascket:public GiftCard
{
private:
    std::string name_toy;
    std::string charact;
    std::string seller;
    int year;
    int kol_toy;
    int price ;
    std::string delivery;
    std::string type;
    double balance;
   
public:
    Toy_bascket() {};
    Toy_bascket(const Toy_bascket& other) {
        name_toy = other.name_toy;
        charact = other.charact;
        seller = other.seller;
        year = other.year;
        kol_toy = other.kol_toy;
        price = other.price;
        delivery = other.delivery;
        type = other.type;
        balance = other.balance;
    }

    // Assignment operator
    Toy_bascket& operator=(const Toy_bascket& other) {
        if (this == &other) {
            return *this;  // Self-assignment, no need to perform any operation
        }

        name_toy = other.name_toy;
        charact = other.charact;
        seller = other.seller;
        year = other.year;
        kol_toy = other.kol_toy;
        price = other.price;
        delivery = other.delivery;
        type = other.type;
        balance = other.balance;

        return *this;
    }
    void delete_toy_tobasket()
    {
        system("color b");
        vector<Toy_bascket> Array;
        ifstream fin;
        fin.open("�������.txt");
        while (fin.peek() != EOF)
        {
            Toy_bascket toy;
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
        fout.open("�������.txt");
        for (int j = 0; j < size; j++)
        {
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

        // ��������� ������� ������ � ���� "������.txt"
        string file = "������.txt";
        ofstream fout_products;
        fout_products.open("������.txt", ios::app); // ��������� ���� � ������ ����������
        fout_products << Array[n].name_toy << endl;
        fout_products << Array[n].charact << endl;
        fout_products << Array[n].price << endl;
        fout_products << Array[n].kol_toy << endl;
        fout_products << Array[n].year << endl;
        fout_products << Array[n].seller << endl;
        fout_products << Array[n].delivery << endl;
        fout_products << Array[n].type << endl;
        fout_products.close();
    }
 void Payforcart_toy()
 {
     system("color b");
     vector<Toy_bascket> Array;
     string bascket = "�������.txt";
     ifstream fin("�������.txt");
     if (!fin) {
         cout << "������ �������� �����." << endl;
         return;
     }

     while (fin.peek() != EOF) {
         Toy_bascket toy;
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

     string tmp;
     bool checkt = true;
     int totalPayment = 0; // ����� ����� � ������

     while (checkt) {
         cout << "������� �������� �������, ������� ������ ������ (��� ������ ���� ������� ������� 'all'): ";
         cin >> tmp;
         checkt = false;
         for (int i = 0; i < tmp.size(); i++) {
             if (int(tmp[i]) < -64) {
                 checkt = true;
                 break;
             }
         }
     }

     if (tmp == "all") {
         // ������ ���� �������
         for (int j = 0; j < Array.size(); j++) {
             totalPayment += Array[j].price * Array[j].kol_toy;
             Array[j].kol_toy = 0; // ������������� ���������� ������� � ������� � 0
         }
         Array.clear();
         bascket.clear();// ������� �������
     }
     else {
         // ������ ��������� �������
         int n = -1;
         for (int j = 0; j < Array.size(); j++) {
             if (Array[j].name_toy == tmp) {
                 n = j;
                 if (Array[j].kol_toy > 0) {
                     totalPayment += Array[j].price;
                     Array[j].kol_toy--;

                     // ���� ���������� ������� ����� 0, ������� ���������� �� ������� �� �������
                     if (Array[j].kol_toy == 0) {
                         Array.erase(Array.begin() + j); // ������� ������� �� ������� Array
                         j--; // ��������� ������, ����� ��������� ������ ������ ����� �������� ��������
                     }
                 }
                 else {
                     cout << "��������, ������ ������� ��� �������!" << endl;
                     system("pause");
                     return;
                 }
             }
         }
         if (n == -1) {
             cout << "����� ������� ���!" << endl;
             system("pause");
             return;
         }
     }

     ofstream fout;
     fout.open("�������.txt");
     for (int j = 0; j < Array.size(); j++) {
         fout << Array[j].name_toy << endl;
         fout << Array[j].charact << endl;
         fout << Array[j].price << endl;
         fout << Array[j].kol_toy << endl;
         fout << Array[j].year << endl;
         fout << Array[j].seller << endl;
         fout << Array[j].delivery << endl;
     }
     fout.close();
     cout << "�� ������� ��������� �������!" << endl;
     cout << "����� � ������: " << totalPayment << endl;
     system("pause");
     system("cls");
     delete_toy_tobasket();
 }
 void Payforcartgift_toy()
 {
     system("color b");
     std::ifstream fin("�����.txt");
     if (!fin)
     {
         std::cout << "������ �������� ����� � �������." << std::endl;
         system("pause");
         return;
     }
     cout << "������� ��� ����������,�� �������� ���������������� �����:" << endl;
     cin >> ownerNames;
     ifstream finfile("�������.txt");
     if (!finfile)
     {
         std::cout << "������ �������� ����� � �������." << endl;
         system("pause");
         return;
     }
     vector<Toy_bascket> Array;
     while (finfile.peek() != EOF) {
         Toy_bascket toy;
         finfile >> toy.name_toy;
         finfile >> toy.charact;
         finfile >> toy.price;
         finfile >> toy.kol_toy;
         finfile >> toy.year;
         finfile >> toy.seller;
         finfile >> toy.delivery;
         finfile >> toy.type;
         Array.push_back(toy);
     }
     int cardNumberFromFile;
     int cardBalanceFromFile;
     std::string cardOwnerFromFile;

     fin >> cardNumberFromFile;
     fin >> cardBalanceFromFile;
     fin >> cardOwnerFromFile;

     fin.close();
     if (ownerNames != cardOwnerFromFile)
     {
         std::cout << "������: ��������� ��� ���������� �� ��������� � ���������� �����." << std::endl;
         system("pause");
         return;
     }
     Toy_bascket toy;
     if (toy.price > cardBalanceFromFile)
     {
         std::cout << "������: ������������� ������ �� ���������� �����." << std::endl;
         system("pause");
         return;
     }

     
     cardBalanceFromFile -= toy.price;

     std::ofstream fout("�����.txt");
     if (!fout)
     {
         std::cout << "������ �������� ����� � �������." << std::endl;
         system("pause");
         return;
     }

     fout << cardNumberFromFile << std::endl;
     fout << cardBalanceFromFile << std::endl;
     fout << cardOwnerFromFile << std::endl;

     fout.close();


     cout << "�� ������� ��������� �������!" << endl;

     cout << "������ ����������� � �������������� ���������� ����� ����� " << cardNumberFromFile << "." << endl;
     system("pause");
     system("cls");
     delete_toy_tobasket();

 }
    
    void Add_toy_tobascket()
    {
        system("color b");
        string Newtoy;
        ifstream fin;

        vector<Toy_bascket> foundToys;
        bool checkt = true;
        while (checkt)
        {
            cout << "������� ������������ ������, ������� ������ �������� � �������: ";
            cin >> Newtoy;
            checkt = false;
            for (int i = 0; i < Newtoy.size(); i++)
            {
                if (int(Newtoy[i]) < -64)
                {
                    checkt = true;
                    break;
                }
            }
        }
        int quantity = 0;
        cout << "������� ���������� ������ \"" << Newtoy << "\", ������� ������ �������� � �������: ";
        cin >> quantity;

        bool found = false; // Flag to track if the toy was found in the file
        fin.open("������.txt");
        while (!fin.eof())
        {
            Toy_bascket toy;
            fin >> toy.name_toy;
            fin >> toy.charact;
            fin >> toy.price;
            fin >> toy.kol_toy;
            fin >> toy.year;
            fin >> toy.seller;
            fin >> toy.delivery;
            fin >> toy.type;
            if (Newtoy == toy.name_toy)
            {
                found = true;
                if (quantity > toy.kol_toy) {
                    cout << "���������� ������ \"" << Newtoy << "\" ��������� ��������� ����������. ������� ����������." << endl;
                    system("pause");
                    return;
                }  
                if (!found) {
            cout << "����� � ������ \"" << Newtoy << "\" �� ������. ���������� �������� � �������." << endl;
            system("pause");
            return;
        }
                toy.kol_toy = quantity; // Set the quantity to the user-specified value
                foundToys.push_back(toy);
                break; // Exit the loop after finding the matching toy
            }
        }

        fin.close(); // Close the input file

      

        if (foundToys.empty()) {
            cout << "������ �� �������!" << endl;
        }
        else {
            ofstream fout;
            fout.open("�������.txt");

            for (const auto& toy : foundToys) {
                fout << toy.name_toy << "\n";
                fout << toy.charact << "\n";
                fout << toy.price << "\n";
                fout << toy.kol_toy << "\n";
                fout << toy.year << "\n";
                fout << toy.seller << "\n";
                fout << toy.delivery << "\n";
                fout << toy.type << "\n";
            }

            fout.close();
            cout << "����� ������� �������� � �������!" << endl;
            system("pause");
        }
    }
   

   void View_Toytobascket()
    {
        system("color b");
        string type;
        string filename = "�������.txt";
        ifstream fin(filename);
        if (!fin)
        {
            cout << "����� ������� ���� ������� �� �������." << endl;
            return;
        }

        cout << "--------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "|" << setw(14) << "��������" << setw(5) << "|" << setw(14) << "��������" << setw(5) << "|" << setw(14) << "����" << setw(5) << "|" << setw(14) << "����������" << setw(5) << "|" << setw(14) << "���. �������" << setw(5) << " |" << setw(14) << "������������" << setw(5) << "|" << setw(14) << "��������" << setw(5) << "|" << setw(14) << "��� �������" << setw(5) << "|\n";
        cout << "-------------------------------------------------------------------------------------------------------------------------------------------\n";

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
            cout << "|" << setw(14) << name_toy << setw(5);
            cout << "|" << setw(14) << charact << setw(5);
            cout << "|" << setw(14) << price << setw(5);
            cout << "|" << setw(14) << kol_toy << setw(5);
            cout << "|" << setw(14) << year << setw(5);
            cout << "|" << setw(14) << seller << setw(5);
            cout << "|" << setw(14) << delivery << setw(5);
            cout << "|" << setw(14) << toy_type << setw(5) << "\n";
            cout << "-------------------------------------------------------------------------------------------------------------------------------------\n";
        }

        fin.close();
        system("pause");
        system("cls");
    }
    void Menu_bascket()
    {
        system("color b");
        char n;
        do {
            int choice;
            cout << "1.�������� ������� � ������� " << endl;
            cout << "2.�������� ������� �� �������" << endl;
            cout << "3.�������� �������" << endl;
            cout << "4.���������� ���������� �����" << endl;
            cout << "5.�������� �������" << endl;
            cout << "6.�������� ������� ���������� ������" << endl;
            cout << "7.����� � ������� ����" << endl;
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                Add_toy_tobascket();
                break;
            }
            case 2:
            {
                delete_toy_tobasket();
                break;
            }
            case 3:
            {
                View_Toytobascket();
                break;
            }
            case 4:
            {
                Buy_gift_card();
                break;
            }
            case 5:
            {
                Payforcart_toy();
                break;
            }
            case 6:
            {
                Payforcartgift_toy();
                break;
            }
            case 7:
            {
                return;
            }
            default:
            {
                cout << "������������ �����." << endl;
                break;
            }
            }
            cout << "����������? (1 - ��) ";
            cin >> n;
            cin.ignore(); // ������� ����� ����� ����� ���������� �����
        } while (n == '1');
    }
};
