// lab OOP magaz_v_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// блок где описывается про банкомат/деньги
#ifndef DATA_CARD_H
#define DATA_CARD_H

#include <iostream>
#include <string>
using namespace std;

class Card {
private:
    int ID;
    int cash;
    
    bool ADD(int a) {
        cash = cash + a;
        return true;
    }

    bool SUB(int a) {
        if (cash - a > 0) {
            cash = cash - a;
            return true;
        }
        else {
            return false;
        }
    }

public:
    Card() {
        ID = 0;
        cash = 0;
    };

    Card(int a, int b) {
        ID = a;
        cash = b;
    }

    void Write() {
        cout << "ID_Card: " << ID << endl << "Cash_Card: " << cash << endl << endl;
    };

    void Bay(int cash_1) {
        cout << "К оплате " << cash_1 << " рублей." << endl << "У вас " << cash << " рублей на карте. " << endl;

        if (SUB(cash_1)) {
            cout << "Оплата прошла успешно." << endl << "Ваш баланс: " << cash << endl << "Спасибо за покупку!" << endl << endl;
        }
        else cout << "У Вас недостаточно денег на карте." << endl << endl;
    };

    void Refund(int cash_2) {
        cout << "К возврату " << cash_2 << " рублей." << endl << "У вас " << cash << " рублей на карте. " << endl;

        if (ADD(cash_2)) {
            cout << "Операция выполнена успешно!" << endl << "Ваш баланс: " << cash << endl << endl;
        }
    };
};

class Cashless {
    int cash;
    
    bool ADD(int a) {
        cash = cash + a;
        return true;
    }

    bool SUB(int a) {
        if (cash - a > 0) {
            cash = cash - a;
            return true;
        }
        else {
            return false;
        }
    }

public: 
    Cashless() {

    }

    Cashless(int a) {
        cash = a;
    }

    void Bay(int cash_1) {
        cout << "К оплате " << cash_1 << " рублей." << endl << "У вас " << cash << " рублей наличными. " << endl;
        bool prov; // проверка статуса денег: достаточно/недостаточно 
        prov = false;
        int nal;
        int s;
        if (SUB(cash_1)) {
            cout << "Введите количество денег для оплаты. " << endl;
            while (!prov) {
                cin >> nal;
                if (!nal) {
                    cout << "Некорректное значение." << endl;
                    prov = false;
                    break;
                } else
                if ((nal <= cash + cash_1) && (nal >= cash_1)) {
                    prov = true;
                    s = nal - cash_1; // вывод сдачи, после оплаты
                    cout << "Ваша сдача " << s << " рублей." <<  endl;
                }
                else 
                    if (nal > cash + cash_1) {
                        cout << "Вы ввели не ту сумму. У вас таких денег нет." << endl;
                        prov = false;
                    }
                    else if ((nal >= 0) && (nal < cash_1)) {
                        cout << "Вы ввели не ту сумму. Введите большое количество денег." << endl;
                        prov = false;
                    }
            }
            if (!prov) {
                ADD(cash_1);
                cout << "Вам отказано в покупке." << endl << endl;
            }
            else
            cout << "Оплата прошла успешно." << endl <<"Спасибо за покупку!" << endl << endl;
        }
        else cout << "У Вас недостаточно денег наличными." << endl << endl;
    }

    void Refund(int cash_2) {
        cout << "К возврату " << cash_2 << " рублей." << endl << "У вас " << cash << " рублей наличными. " << endl;

        if (ADD(cash_2)) {
            cout << "Операция выполнена успешно!" << endl << "Ваш баланс: " << cash << endl << endl;
        }
    };

    void Write() {
        cout << "У Вас " << cash << " рублей наличными." << endl << endl;
    }

};

#endif