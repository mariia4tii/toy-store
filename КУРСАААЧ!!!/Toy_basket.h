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
        fin.open("Корзина.txt");
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
            cout << "Имя: " << toy.name_toy << endl;
        }
        fin.close();

        size_t size = Array.size();
        int n = -1;
        std::string tmp;
        bool checkt = true;
        while (checkt)
        {
            cout << "Введите название игрушки, которую хотите удалить: ";
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
            cout << "Такой игрушки нет!\n";
            _getch();
            return;
        }

        ofstream fout;
        fout.open("Корзина.txt");
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

        // Добавляем возврат данных в файл "Товары.txt"
        string file = "Товары.txt";
        ofstream fout_products;
        fout_products.open("Товары.txt", ios::app); // Открываем файл в режиме добавления
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
     string bascket = "Корзина.txt";
     ifstream fin("Корзина.txt");
     if (!fin) {
         cout << "Ошибка открытия файла." << endl;
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
         cout << "Имя: " << toy.name_toy << endl;
     }

     fin.close();

     string tmp;
     bool checkt = true;
     int totalPayment = 0; // Общая сумма к оплате

     while (checkt) {
         cout << "Введите название игрушки, которую хотите купить (для оплаты всей корзины введите 'all'): ";
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
         // Оплата всей корзины
         for (int j = 0; j < Array.size(); j++) {
             totalPayment += Array[j].price * Array[j].kol_toy;
             Array[j].kol_toy = 0; // Устанавливаем количество игрушек в корзине в 0
         }
         Array.clear();
         bascket.clear();// Очищаем корзину
     }
     else {
         // Оплата выбранной игрушки
         int n = -1;
         for (int j = 0; j < Array.size(); j++) {
             if (Array[j].name_toy == tmp) {
                 n = j;
                 if (Array[j].kol_toy > 0) {
                     totalPayment += Array[j].price;
                     Array[j].kol_toy--;

                     // Если количество игрушек равно 0, удаляем информацию об игрушке из вектора
                     if (Array[j].kol_toy == 0) {
                         Array.erase(Array.begin() + j); // Удаляем игрушку из вектора Array
                         j--; // Уменьшаем индекс, чтобы правильно обойти вектор после удаления элемента
                     }
                 }
                 else {
                     cout << "Извините, данная игрушка уже продана!" << endl;
                     system("pause");
                     return;
                 }
             }
         }
         if (n == -1) {
             cout << "Такой игрушки нет!" << endl;
             system("pause");
             return;
         }
     }

     ofstream fout;
     fout.open("Корзина.txt");
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
     cout << "Вы успешно приобрели игрушки!" << endl;
     cout << "Сумма к оплате: " << totalPayment << endl;
     system("pause");
     system("cls");
     delete_toy_tobasket();
 }
 void Payforcartgift_toy()
 {
     system("color b");
     std::ifstream fin("Карты.txt");
     if (!fin)
     {
         std::cout << "Ошибка открытия файла с картами." << std::endl;
         system("pause");
         return;
     }
     cout << "Введите имя покупателя,на которого зарегестрирована карта:" << endl;
     cin >> ownerNames;
     ifstream finfile("Корзина.txt");
     if (!finfile)
     {
         std::cout << "Ошибка открытия файла с картами." << endl;
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
         std::cout << "Ошибка: введенное имя покупателя не совпадает с владельцем карты." << std::endl;
         system("pause");
         return;
     }
     Toy_bascket toy;
     if (toy.price > cardBalanceFromFile)
     {
         std::cout << "Ошибка: недостаточный баланс на подарочной карте." << std::endl;
         system("pause");
         return;
     }

     
     cardBalanceFromFile -= toy.price;

     std::ofstream fout("Карты.txt");
     if (!fout)
     {
         std::cout << "Ошибка открытия файла с картами." << std::endl;
         system("pause");
         return;
     }

     fout << cardNumberFromFile << std::endl;
     fout << cardBalanceFromFile << std::endl;
     fout << cardOwnerFromFile << std::endl;

     fout.close();


     cout << "Вы успешно приобрели игрушки!" << endl;

     cout << "Оплата произведена с использованием подарочной карты номер " << cardNumberFromFile << "." << endl;
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
            cout << "Введите наименование товара, который хотите добавить в корзину: ";
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
        cout << "Введите количество товара \"" << Newtoy << "\", которое хотите добавить в корзину: ";
        cin >> quantity;

        bool found = false; // Flag to track if the toy was found in the file
        fin.open("Товары.txt");
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
                    cout << "Количество товара \"" << Newtoy << "\" превышает доступное количество. Покупка невозможна." << endl;
                    system("pause");
                    return;
                }  
                if (!found) {
            cout << "Товар с именем \"" << Newtoy << "\" не найден. Невозможно добавить в корзину." << endl;
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
            cout << "Товары не найдены!" << endl;
        }
        else {
            ofstream fout;
            fout.open("Корзина.txt");

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
            cout << "Товар успешно добавлен в корзину!" << endl;
            system("pause");
        }
    }
   

   void View_Toytobascket()
    {
        system("color b");
        string type;
        string filename = "Корзина.txt";
        ifstream fin(filename);
        if (!fin)
        {
            cout << "Файлы данного типа игрушек не найдены." << endl;
            return;
        }

        cout << "--------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "|" << setw(14) << "Название" << setw(5) << "|" << setw(14) << "Описание" << setw(5) << "|" << setw(14) << "Цена" << setw(5) << "|" << setw(14) << "Количество" << setw(5) << "|" << setw(14) << "Рек. возраст" << setw(5) << " |" << setw(14) << "Изготовитель" << setw(5) << "|" << setw(14) << "Доставка" << setw(5) << "|" << setw(14) << "Вид игрушки" << setw(5) << "|\n";
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
            cout << "1.Добавить игрушку в корзину " << endl;
            cout << "2.Удаление игрушки из корзины" << endl;
            cout << "3.Просмотр корзины" << endl;
            cout << "4.Приобрести подарочную карту" << endl;
            cout << "5.Оплатить корзину" << endl;
            cout << "6.Оплатить корзину подарочной картой" << endl;
            cout << "7.Назад в главное меню" << endl;
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
                cout << "Некорректный выбор." << endl;
                break;
            }
            }
            cout << "Продолжить? (1 - ДА) ";
            cin >> n;
            cin.ignore(); // Очищаем буфер ввода после считывания числа
        } while (n == '1');
    }
};
