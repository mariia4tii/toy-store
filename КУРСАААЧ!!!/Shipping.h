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
           
            cout << "Продолжая использовать настоящий сайт MariaShop.by, вы подтверждаете свое согласие на обработку компанией ООО Надежная доставка персональных данных, а именно :" << endl;
            cout << "сбор, систематизацию, накопление, хранение, уточнение(обновление, изменение), использование, передачу – исключительно в целях : идентификации вас как Пользователя" << endl;
            cout << "и / или Клиента, установления с вами обратной связи, определения вашего местонахождения(в случае необходимости), подтверждения достоверности и полноты персональных" << endl;
            cout << "данных, предоставленных вами(в случае необходимости), а также для иных целей, необходимых для исполнения компанией ООО Надежная доставка обязательств перед вами" << endl;
            cout << "как Пользователем и / или Клиентом и в соответствии с требованиями закона." << endl;
            std::cout << "Форма оформления доставки" << std::endl;
           
        
            bool checkt = true;
            while (checkt)
            {
                cout << "Введите имя получателя: ";
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
                cout << "Введите адрес доставки: " << endl;
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
                cout << "Введите номер телефона получателя: ";
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
                cout << "Выберите метод доставки (курьерская доставка, почта и т.д.): ";
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
            string filename = "Доставка.txt";
            fout.open(filename, fstream::in | fstream::out | fstream::app);
            fout << recipientName << endl;
            fout << address << endl;
            fout << phoneNumber << endl;
            fout << deliveryMethod << endl;
            fout.close();
            std::cout << "Форма доставки успешно заполнена! Спасибо." << std::endl;
            system("pause");
        }
    
};