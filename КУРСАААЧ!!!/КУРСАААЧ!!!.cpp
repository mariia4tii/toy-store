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
#include "User.h"
#include"Admin.h"
#include"Console.h"
#include"Supplier.h"
#include "Shop_assistant.h"
#include"Chief.h"
#include"Toy_basket.h"
using namespace std;
 
int Authorization()
{
    string User = "User.txt";
    string Admin = "Admin.txt";
    string Shop_assistant = "Продавец.txt";
    string Chief = "Директор.txt";

    fstream user;
    fstream admin;
    fstream assistant;
    fstream chief;

    user.open(User, fstream::in | fstream::out | fstream::app);
    if (!user.is_open())
    {
       std:: cout << "Ошибка!" << endl;
    }
    else
    {
        string log_user;
        string pass_user;

        string login_correct;
        string pass_correct;
        bool credentialsCorrect = false;
        int userRole = 0; // 0: Неопределенная роль, 1: Пользователь, 2: Продавец, 3: Администратор, 4: Директор

        std::cout << "Введите свой логин: ";
        std::cin >> login_correct;
        std::cout << "Введите свой пароль: ";
        std::cin >> pass_correct;

        while (user >> log_user >> pass_user)
        {
            if (login_correct == log_user && pass_correct == pass_user)
            {
                credentialsCorrect = true;
                break;
            }
        }

        user.close();

        if (credentialsCorrect)
        {
            std::cout << "Данные введены верно!" << endl;
            std::cout << "Вы вошли как обычный пользователь" << endl;
            system("pause");
            return 1;
        }
        else
        {
      
            

                admin.open(Admin, fstream::in | fstream::out | fstream::app);
                if (!admin.is_open())
                {
                    std::cout << "Ошибка!" << endl;
                }
                else
                {
                    string log_admin;
                    string pass_admin;

                    while (admin >> log_admin >> pass_admin)
                    {
                        if (login_correct == log_admin && pass_correct == pass_admin)
                        {
                            credentialsCorrect = true;
                            userRole = 3; // Роль: Администратор
                            break;
                        }
                    }

                    admin.close();

                    if (credentialsCorrect)
                    {
                        std::cout << "Данные введены верно!" << endl;
                        if (userRole == 3)
                        {
                            std::cout << "Вы вошли как администратор" << endl;
                            system("pause");
                            return 3;
                        }
                        else
                        {
                            std::cout << "Вы вошли как обычный пользователь" << endl;
                            system("pause");
                            return 1;
                        }
                    }
                    else
                    {
                        assistant.open(Shop_assistant, fstream::in | fstream::out | fstream::app);
                        if (!assistant.is_open())
                        {
                            std::cout << "Ошибка!" << endl;
                        }
                        else
                        {
                            string log_assistant;
                            string pass_assistant;

                            while (assistant >> log_assistant >> pass_assistant)
                            {
                                if (login_correct == log_assistant && pass_correct == pass_assistant)
                                {
                                    credentialsCorrect = true;
                                    userRole = 2;
                                    break;
                                }
                            }

                            assistant.close();

                            if (credentialsCorrect)
                            {
                                std::cout << "Данные введены верно!" << endl;
                                if (userRole == 2)
                                {
                                    std::cout << "Вы вошли как продавец" << endl;
                                    system("pause");
                                    return 2;
                                }
                                else
                                {
                                    std::cout << "Вы вошли как обычный пользователь" << endl;
                                    system("pause");
                                    return 1;
                                }
                            }
                            else
                            {
                                chief.open(Chief, fstream::in | fstream::out | fstream::app);
                                if (!chief.is_open())
                                {
                                    std::cout << "Ошибка!" << endl;
                                }
                                else
                                {
                                    string log_chief;
                                    string pass_chief;

                                    while (chief >> log_chief >> pass_chief)
                                    {
                                        if (login_correct == log_chief && pass_correct == pass_chief)
                                        {
                                            credentialsCorrect = true;
                                            userRole = 4;
                                            break;
                                        }
                                    }

                                    chief.close();

                                    if (credentialsCorrect)
                                    {
                                        std::cout << "Данные введены верно!" << endl;
                                        if (userRole == 4)
                                        {
                                            std::cout << "Вы вошли как директор" << endl;
                                            system("pause");
                                            return 4;
                                        }
                                        else
                                        {
                                            std::cout << "Вы вошли как обычный пользователь" << endl;
                                            system("pause");
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            
        }
    }

    return 0;
}
void Registr_user()
{
    system("color bb");
    string User_t = "User.txt";
    ofstream user_t;
    user_t.open(User_t, fstream::in | fstream::out | fstream::app);
    if (!user_t.is_open())
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
        user_t << log_cheker << endl;
        user_t << pass_cheker << endl;
        user_t.close();
        cout << "Регистрация прошла успешно!" << endl;
        system("pause");
        system("cls");
       

    }
    user_t.close(); 
    User s;
        s.Menu_Toy_user();
}
void clearFile(const std::string& filename)
{
    std::ofstream ofs(filename, std::ios::trunc);
    ofs.close();
}



int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
    
    string User_t = "User.txt";
    fstream user_t;
	int choice;
	choice= Authorization();
	switch (choice)
	{
		case 1:
		{
            User s;
		s.Menu_Toy_user();
		}
		case 2:
		{
		Shop_assistant s;
		s.Menu_Toy_assistant();
		}
        case 3:
        {
            Admin s;
            s.Menu_Toy_admin();
        }
        case 4:
        {
            Chief s;
            s.Menu_Toy_chief();
        }
    default:
        {
            Registr_user();
        }


	}

	return 0;
 
}
