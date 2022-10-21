// товары.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include "Vector.h"
#include "mag_1.h"
#include <iterator>

using namespace std;

struct Product {
    string name;
    int id;
    int price;
};

ostream& operator << (ostream &os, const Product &p)// выводит на экран структуру 
{
    return os << p.id << " " << p.name << " " << p.price;
}

Vector<Product> Vec; // данные с файла хранятся в векторе 

class Check {
public:
    Vector<Product> check_;
    int itog;//общая сумма покупки

    Check() {
        itog = 0;
    }

    void Mag() {//типа покупаешь подукты, которые заносятся в вектор чек.
        int k,i;
        int id;
        cout << "Выберите, то, что хотите купить.(надо ввести цифру, который рядом с продуктом)" << endl;
        cout << "Для выхода нажмите на 0. (при нажатии некорректных кнопок программа работает не правильно.)" << endl;
        bool prov = false;
        while (prov == false) {
            cin >> id;
                switch (id)
                {
                case 1:
                    cout << "Количество: ";
                    cin >> k;
                    for (i = 0; i < k; i++) {
                        check_.pushBack(Vec[0]);
                        itog = itog + Vec[0].price;
                    }
                    break;
                case 2:
                    cout << "Количество: ";
                    cin >> k;
                    for (i = 0; i < k; i++) {
                        check_.pushBack(Vec[1]);
                        itog = itog + Vec[1].price;
                    }
                    break;
                case 3:
                    cout << "Количество: ";
                    cin >> k;
                    for (i = 0; i < k; i++) {
                        check_.pushBack(Vec[2]);
                        itog = itog + Vec[2].price;
                    }
                    break;
                case 4:
                    cout << "Количество: ";
                    cin >> k;
                    for (i = 0; i < k; i++) {
                        check_.pushBack(Vec[3]);
                        itog = itog + Vec[3].price;
                    }
                    break;
                case 5:
                    cout << "Количество: ";
                    cin >> k;
                    for (i = 0; i < k; i++) {
                        check_.pushBack(Vec[4]);
                        itog = itog + Vec[4].price;
                    }
                    break;
                case 6:
                    cout << "Количество: ";
                    cin >> k;
                    for (i = 0; i < k; i++) {
                        check_.pushBack(Vec[5]);
                        itog = itog + Vec[5].price;
                    }
                    break;
                case 7:
                    cout << "Количество: ";
                    cin >> k;
                    for (i = 0; i < k; i++) {
                        check_.pushBack(Vec[6]);
                        itog = itog + Vec[6].price;
                    }
                    break;
                case 8:
                    cout << "Количество: ";
                    cin >> k;
                    for (i = 0; i < k; i++) {
                        check_.pushBack(Vec[7]);
                        itog = itog + Vec[7].price;
                    }
                    break;
                case 9:
                    cout << "Количество: ";
                    cin >> k;
                    for (i = 0; i < k; i++) {
                        check_.pushBack(Vec[8]);
                        itog = itog + Vec[8].price;
                    }
                    break;
                case 10:
                    cout << "Количество: ";
                    cin >> k;
                    for (i = 0; i < k; i++) {
                        check_.pushBack(Vec[9]);
                        itog = itog + Vec[9].price;
                    }
                    break;
                case 0:
                    prov = true;
                    break;
                default:
                    break;
                }
        }

        //cout << itog << endl;
    }

    void Cout_check() {//использование итератора
        for (auto iter = check_.begin(); iter != check_.end(); ++iter)
        {
            cout << *iter << endl;
        }
    }

    void BBB(Card my_card, Cashless my_cashless) {
        int read;
        cout << "К оплате " << itog << " рублей. " << endl;
        cout << "Чем будете оплачивать? Картой(1) или Наличкой(2)?" << endl;
        cin >> read;
        if (read == 1) {
            my_card.Bay(itog);
        }
        if (read == 2) { my_cashless.Bay(itog); }
        
    }
};

int n;// количество продуктов в общем


void Read_to_file() { // в файле содержится данные о товарах, которые доступны для покупки. в первой строке написано количество товаров в магазине. Далее: персональный номер товара, название, цена. 
   
    ifstream in("begin.txt");
    if (!in) {
        cout << "can not open the file!\n";
    }
    if (in.is_open()) {
        in >> n;
        Product P;
        int i;
        for (i = 0; i < n; i++) {
            in >> P.id  >> P.name >> P.price;
            Vec.pushBack(P);
        }
    }
    in.close();
}

void print() { //просто выводит на экран содержание вектора которая есть 
   cout << Vec << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");

    Cashless my_cashless(10000);
    Card my_card(123456,10000);
    Check ch;
    int read;
    Read_to_file();
    print();
    
    ch.Mag();
    
    ch.Cout_check();
    ch.BBB(my_card, my_cashless);
}