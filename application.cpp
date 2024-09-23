#include "application.h"
using namespace std;


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
        clearStream();
        switch(choise) {
            case '1':
                listApplication();
                break;
            case '2':
                arrayApplication();
                break;
            case '3':
                stationApplication();
                break;
            case '4':
                exit(0);
            default:
                cout << "Неверный ввод\n";
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
    while(true){
        editMenu();
        cin >> choise;
        clearStream();
        switch (choise) {
            case '1':

                break;
            case '2':

                break;
            case '3':

                break;
            case '4':

                break;
            case '5':
                return;
            default:
                cout << "Неверный ввод\n";
                break;
        }
    }
}

void application::listApplication() {
    char choise;
    while(true){
        editMenu();
        cin >> choise;
        clearStream();
        switch (choise) {
            case '1':

                break;
            case '2':

                break;
            case '3':

                break;
            case '4':

                break;
            case '5':
                return;
            default:
                cout << "Неверный ввод\n";
                break;
        }
    }
}

void application::stationApplication() {

}
