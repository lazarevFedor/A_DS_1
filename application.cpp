#include "application.h"
using namespace std;


void clearStream() {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.sync();
}


void application::showMenu() {
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
                system("cls");
                listApplication();
                system("cls");
                break;
            case '2':
                system("cls");
                arrayApplication();
                system("cls");
                break;
            case '3':
                system("cls");
                stationApplication();
                system("cls");
                break;
            case '4':
                exit(0);
            default:
                system("cls");
                break;
        }
    }
}

void application::editMenu() {
    cout << "1) Вставить элемент\n" <<
         "2) Удалить элемент по индексу\n" <<
         "3) Обмен элементов\n" <<
         "4) Получить элемент по индексу\n" <<
         "5) Назад\n--> ";
}

void application::arrayApplication() {
    char choise;
    auto* pArray = new Array<int>();
    size_t value = 0;
    short index1 = 0;
    short index2 = 0;

    while(true){
        editMenu();
        cin >> choise;
        if(cin.bad()) clearStream();
        switch (choise) {
            case '1':
                cout << "\n\nВведите индекс: ";
                cin >> index1;
                cout << "Введите значение: ";
                cin >> value;
                pArray->insert(index1, value);
                pArray->print();
                break;
            case '2':
                cout << "\n\nВведите индекс: ";
                cin >> index1;
                pArray->erase(index1);
                pArray->print();
                break;
            case '3':
                cout << "\n\nВведите первый индекс: ";
                cin >> index1;
                cout << "\n\nВведите второй индекс: ";
                cin >> index2;
                pArray->swap(index1, index2);
                pArray->print();
                break;
            case '4':
                cout << "\n\nВведите индекс: ";
                cin >> index1;
                cout << "\nЭлемент: " << *(pArray->getAt(index1));
                break;
            case '5':
                return;
            default:
                cout << "Неверный ввод";
                break;
        }
        cout << "\n";
    }
}

void application::listApplication() {
    char choise;
    auto* pList = new LinkedList<int>();
    size_t value = 0;
    short index1 = 0;
    short index2 = 0;

    while(true){
        editMenu();
        cin >> choise;
        switch (choise) {
            case '1':
                cout << "\n\nВведите индекс: ";
                cin >> index1;
                cout << "Введите значение: ";
                cin >> value;
                pList->insert(index1, value);
                pList->print();
                break;
            case '2':
                cout << "\n\nВведите индекс: ";
                cin >> index1;
                pList->erase(index1);
                pList->print();
                break;
            case '3':
                cout << "\n\nВведите первый индекс: ";
                cin >> index1;
                cout << "\n\nВведите второй индекс: ";
                cin >> index2;
                pList->swap(index1, index2);
                pList->print();
                break;
            case '4':
                cout << "\n\nВведите индекс: ";
                cin >> index1;
                cout << "\nЭлемент: " << pList->getAt(index1)->data;
                break;
            case '5':
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
    clearStream();
}
