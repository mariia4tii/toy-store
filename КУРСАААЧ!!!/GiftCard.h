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
#include <random>

using namespace std;

    class GiftCard
    {
    public:
        double cardNumber;
        int balance;
        string ownerNames;
        std::random_device rd;
        
        GiftCard() {};
        GiftCard( GiftCard& other)
        {
            cardNumber = other.cardNumber;
            balance = other.balance;
            ownerNames = other.ownerNames;
        }
        void Buy_gift_card()
        {
            system("color b");
            std::mt19937 gen(rd());
            int min = 1000000;
            int max = 9999999;
            bool check9 = true;
            cin.ignore();
            while (check9)
            {
                cout << "¬ведите им€ покупател€, дл€ которого хотите приобрести карту: " << endl;
                cin>> ownerNames;
                check9 = false;
                for (int i = 0; i < ownerNames.size(); i++)
                {
                    if (int(ownerNames[i]) < -64)
                    {
                        check9 = true;
                        break;
                    }
                }
            }
            bool check = true;
            while (check)
            {
                cout << "¬ведите сумму на которую хотите купить подарочную карту:";
                cin >> balance;
                if (balance >= 0 )
                    check = false;
            }
            
            
            std::uniform_int_distribution<int> dist(min, max);
            int randomNumber = dist(gen);
         
   

            ofstream fout;
            fout.open(" арты.txt");
            fout << randomNumber << endl;
            fout << balance << endl;
            fout << ownerNames << endl;
                         
            fout.close();

            cout << "¬ы успешно приобрели подарочную карту с номером: " << randomNumber << " дл€ покупател€: " << ownerNames << endl;
            system("pause");
            system("cls");
        }
     
   };

