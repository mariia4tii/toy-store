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
class Shipping
{
   
    public: 
        string recipientName;
        string address;
        string phoneNumber;
        string deliveryMethod;
        void fillShippingForm()
        {    system("color bb");
           
            cout << "��������� ������������ ��������� ���� MariaShop.by, �� ������������� ���� �������� �� ��������� ��������� ��� �������� �������� ������������ ������, � ������ :" << endl;
            cout << "����, ��������������, ����������, ��������, ���������(����������, ���������), �������������, �������� � ������������� � ����� : ������������� ��� ��� ������������" << endl;
            cout << "� / ��� �������, ������������ � ���� �������� �����, ����������� ������ ���������������(� ������ �������������), ������������� ������������� � ������� ������������" << endl;
            cout << "������, ��������������� ����(� ������ �������������), � ����� ��� ���� �����, ����������� ��� ���������� ��������� ��� �������� �������� ������������ ����� ����" << endl;
            cout << "��� ������������� � / ��� �������� � � ������������ � ������������ ������." << endl;
            std::cout << "����� ���������� ��������" << std::endl;
           
        
            bool checkt = true;
            while (checkt)
            {
                cout << "������� ��� ����������: ";
                cin.ignore();
                getline(cin,recipientName);
                checkt = false;
                for (int i = 0; i < recipientName.size(); i++)
                {
                    if (int(recipientName[i]) < -64)
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
                cout << "������� ����� ��������: " << endl;
                cin.ignore();
                getline(cin, address);
                check3 = false;
                for (int i = 0; i < address.size(); i++)
                {
                    if (int(address[i]) < -64)
                    {
                        check3 = true;
                        break;
                    }
                }
            }

            bool check1 = true;
            while (check1)
            {
                cout << "������� ����� �������� ����������: ";
                cin.ignore();
                getline(cin,phoneNumber);
                check1 = false;
                for (int i = 0; i < phoneNumber.size(); i++)
                {
                    if (int(phoneNumber[i]) < -64)
                    {
                        check1 = true;
                        break;
                    }
                }
            }
            bool check8 = true;
            while (check1)
            {
                cout << "�������� ����� �������� (���������� ��������, ����� � �.�.): ";
                cin.ignore();
                getline(cin, deliveryMethod);
                check8 = false;
                for (int i = 0; i < deliveryMethod.size(); i++)
                {
                    if (int(deliveryMethod[i]) < -64)
                    {
                        check8 = true;
                        break;
                    }
                }
            }
            ofstream fout;
            string filename = "��������.txt";
            fout.open(filename, fstream::in | fstream::out | fstream::app);
            fout << recipientName << endl;
            fout << address << endl;
            fout << phoneNumber << endl;
            fout << deliveryMethod << endl;
            fout.close();
            std::cout << "����� �������� ������� ���������! �������." << std::endl;
            system("pause");
        }
    
};