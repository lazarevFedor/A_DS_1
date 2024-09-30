#include "application.h"
using namespace std;


inline void clearStream() {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.sync();
}


inline void clear() {
    cout << "\x1B[2J\x1B[H";
}


inline void application::showMenu() {
    cout << "1) Двусвязный список\n" <<
            "2) Динамический массив\n" <<
            "3) Сортировочная станция\n" <<
            "4) Выход\n--> ";
}


void application::interactionMenu() {
    char choise;
    while(true){
        showMenu();
        cin >> choise;
        switch(choise) {
            case '1':
                clear();
                listApplication();
                clear();
                break;
            case '2':
                clear();
                arrayApplication();
                clear();
                break;
            case '3':
                clear();
                stationApplication();
                clear();
                break;
            case '4':
                exit(0);
            default:
                clear();
                break;
        }
    }
}


inline void application::editMenu() {
    cout << "1) Заполнить данными\n" <<
            "2) Вставить элемент\n" <<
            "3) Удалить элемент по индексу\n" <<
            "4) Обмен элементов\n" <<
            "5) Получить элемент по индексу\n" <<
            "6) Назад\n--> ";
}


inline void application::fillMenu() {
    cout << "\nЗаполнение:\n" <<
    "1) С клавиатуры\n" <<
    "2) С файла\n" <<
    "3) N случайных элементов\n--> ";
}


int randint(){
    return rand() % 100;
}


void fill(Array<int>* &pArray, char &choise, ifstream &fin){
    int number;
    switch (choise) {
        case '1':
            cout << "Введите элементы через пробел: ";
            while (cin >> number) {
                pArray->pushBack(number);
                if (cin.peek() == '\n') {
                    break;
                }
            }
            clearStream();
            break;
        case '2':
            fin.open("C:\\Users\\fedos\\CLionProjects\\A&DS\\dataStruct.txt");
            if (!fin.is_open()) {
                cout << "\nОшибка открытия файла!!!\n";
                return;
            }
            while (!fin.eof()) {
                fin >> number;
                pArray->pushBack(number);
                fin.get();
            }
            fin.close();
            break;
        case '3':
            int len;
            cout << "\nВведите длину: ";
            cin >> len;
            for (int i = 0; i < len; i++){
                pArray->pushBack(randint());
            }
            break;
        default:
            cout << "Неверный ввод\n";
            break;
    }
}


void fill(LinkedList<int>* &pList, char &choise, ifstream &fin){
    int number;
    switch (choise) {
        case '1':
            cout << "Введите элементы через пробел: ";
            while (cin >> number) {
                pList->pushBack(number);
                if (cin.peek() == '\n') {
                    break;
                }
            }
            clearStream();
            break;
        case '2':
            fin.open("C:\\Users\\fedos\\CLionProjects\\A&DS\\dataStruct.txt");
            if (!fin.is_open()) {
                cout << "\nОшибка открытия файла!!!\n";
                return;
            }
            while (!fin.eof()) {
                fin >> number;
                pList->pushBack(number);
                fin.get();
            }
            fin.close();
            cout << "\nДанные из файла считаны.\n";
            break;
        case '3':
            int len;
            cout << "\nВведите длину: ";
            cin >> len;
            for (int i = 0; i < len; i++){
                pList->pushBack(randint());
            }
            break;
        default:
            cout << "Неверный ввод\n";
            break;
    }
}


void application::arrayApplication() {
    ifstream fin;
    char choise;
    auto* pArray = new Array<int>();
    int value = 0;
    short index1 = 0;
    short index2 = 0;

    while(true){
        editMenu();
        cin >> choise;
        switch (choise) {
            case '1':
                fillMenu();
                cin >> choise;
                if(!pArray->empty()){
                    delete pArray;
                    pArray = new Array<int>();
                }
                fill(pArray, choise, fin);
                clear();
                pArray->print();
                break;
            case '2':
                cout << "\n\nВведите индекс: ";
                cin >> index1;
                cout << "Введите значение: ";
                cin >> value;
                pArray->insert(index1, value);
                pArray->print();
                break;
            case '3':
                cout << "\n\nВведите индекс: ";
                cin >> index1;
                pArray->erase(index1);
                pArray->print();
                break;
            case '4':
                cout << "\n\nВведите первый индекс: ";
                cin >> index1;
                cout << "\n\nВведите второй индекс: ";
                cin >> index2;
                pArray->swap(index1, index2);
                pArray->print();
                break;
            case '5':
                cout << "\n\nВведите индекс: ";
                cin >> index1;
                cout << "\nЭлемент: " << *(pArray->getAt(index1));
                break;
            case '6':
                delete pArray;
                return;
            default:
                cout << "Неверный ввод";
                break;
        }
        cout << "\n";
    }
}


void application::listApplication() {
    ifstream fin;
    char choise;
    auto* pList = new LinkedList<int>();
    int value = 0;
    short index1 = 0;
    short index2 = 0;

    while(true){
        editMenu();
        cin >> choise;
        switch (choise) {
            case '1':
                fillMenu();
                cin >> choise;
                if(pList->getAt(0) == nullptr){
                    delete pList;
                    pList = new LinkedList<int>();
                }
                fill(pList, choise, fin);
                clear();
                pList->print();
                break;
            case '2':
                cout << "\n\nВведите индекс: ";
                cin >> index1;
                cout << "Введите значение: ";
                cin >> value;
                pList->insert(index1, value);
                pList->print();
                break;
            case '3':
                cout << "\n\nВведите индекс: ";
                cin >> index1;
                pList->erase(index1);
                pList->print();
                break;
            case '4':
                cout << "\n\nВведите первый индекс: ";
                cin >> index1;
                cout << "\n\nВведите второй индекс: ";
                cin >> index2;
                pList->swap(index1, index2);
                pList->print();
                break;
            case '5':
                cout << "\n\nВведите индекс: ";
                cin >> index1;
                cout << "\nЭлемент: " << pList->getAt(index1)->data;
                break;
            case '6':
                delete pList;
                return;
            default:
                cout << "Неверный ввод";
                break;
        }
        cout << "\n";
    }
}


void application::stationApplication() {
    SortStation station;
    string input;
    char choise;

    while(true){
        cout << "1) Преобразовать выражение\n" <<
                "2) Назад\n--> ";
        cin >> choise;
        switch (choise) {
            case '1':
                cout << "\nВведите выражение: ";
                clearStream();
                input = station.getStr();
                cout << "Выражение в обратной польской нотации: " << station.toRPN(input);
                break;
            case '2':
                return;
            default:
                cout << "Неверный ввод";
                break;
        }
        cout << "\n";
    }
}