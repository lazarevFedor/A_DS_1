#include "station.h"

using namespace std;


std::string SortStation::getStr() {
    string input;
    getline(cin, input);
    return input;
}


int SortStation::priority(char c) {
    switch (c){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
        case ')':
            return 0;
        case ' ':
            return 10;
        default:
            if (isdigit(c)) return -1;
            else if (c >= 'a' && c < 'z' || c >= 'A' && c <= 'Z') return -1;
            else return -2;
    }
}


std::string SortStation::toRPN(std::string &inputStr) {
    auto* pStack = new Stack<string>();
    string output;
    string  current;
    int strlen = inputStr.length();
    for(int i = 0; i < strlen; i++){
        if(current == "sin" || current == "cos"){
            pStack->pushFront(current, 2);
            current.clear();
        }
        switch (priority(inputStr[i])) {
            case -1:
                current.push_back(inputStr[i]);
                break;
            case 0:
                if(!current.empty()) {
                    output += current + " ";
                    current.clear();
                }
                if(inputStr[i] == '('){
                    pStack->pushFront("(", 0);
                }
                else{
                    while(pStack->head->data != "("){
                        output += pStack->head->data;
                        output.push_back(' ');
                        pStack->popFront();
                    }
                    pStack->popFront();
                }
                break;
            case 1:
            case 2:
                if(!current.empty()) {
                    output += current + " ";
                    current.clear();
                }
                if (pStack->head == nullptr || pStack->head->priority < priority(inputStr[i])){
                    pStack->pushFront(inputStr.substr(i,1), priority(inputStr[i]));
                }
                else{
                    while(pStack->head != nullptr && pStack->head->priority >= priority(inputStr[i])){
                        output += pStack->head->data;
                        output.push_back(' ');
                        pStack->popFront();
                    }
                    pStack->pushFront(inputStr.substr(i,1), priority(inputStr[i]));
                }
                break;
            case 10:
                if(!current.empty()) {
                    output += current + " ";
                    current.clear();
                }
                break;
        }
    }
    if(!current.empty()) {
        output += current + " ";
        current.clear();
    }
    while(pStack->head != nullptr){
        output += pStack->head->data;
        output.push_back(' ');
        pStack->popFront();
    }
    return output;
}