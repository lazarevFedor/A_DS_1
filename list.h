#ifndef A_DS_LIST_H
#define A_DS_LIST_H
#include <iostream>


//Node class
template <typename Type> class ListNode {
public:
    Type data;
    ListNode* prev, *next;
    explicit ListNode(Type inputData);
};


//List class
template <typename Type> class LinkedList {
    ListNode<Type> *head, *tail;
    short len;
public:
    LinkedList();

    short length();

    void pushFront(Type data);

    void pushBack(Type data);

    void popFront(Type data);

    void popBack(Type data);

    ListNode<Type>* getAt(short index);

    void insert(short index, Type data);

    void erase(short index);

    void swap(short index1, short index2);

    void print();

    void fill();
};


template<typename Type> ListNode<Type>::ListNode(Type inputData) {
    data = inputData;
    prev = next = nullptr;
}


template<typename Type> LinkedList<Type>::LinkedList() {
    head = tail = nullptr;
    len = 0;
}


template<typename Type> short LinkedList<Type>::length() {
    return len;
}


template<typename Type> void LinkedList<Type>::pushFront(Type data) {
    ListNode<Type>* ptr = new ListNode(data);
    ptr->next = head;
    if (head != nullptr){
        head->prev = ptr;
    }
    if (tail == nullptr){
        tail = ptr;
    }
    head = ptr;
}


template<typename Type> void LinkedList<Type>::pushBack(Type data) {
    ListNode<Type>* ptr = new ListNode(data);
    ptr->prev = tail;
    if (tail != nullptr){
        tail->next = ptr;
    }
    if (head == nullptr){
        head = ptr;
    }
    tail = ptr;
}


template<typename Type> void LinkedList<Type>::popFront(Type data) {
    if(head == nullptr) return;
    ListNode<Type>* ptr = head->next;
    if(ptr != nullptr){
        ptr->prev = nullptr;
    }
    else
        tail = nullptr;
    delete head;
    head = ptr;
}


template<typename Type> void LinkedList<Type>::popBack(Type data) {
    if(tail == nullptr) return;
    ListNode<Type>* ptr = tail->prev;
    if(ptr != nullptr){
        ptr->next = nullptr;
    }
    else
        head = nullptr;
    delete tail;
    tail = ptr;
}


template<typename Type> ListNode<Type> *LinkedList<Type>::getAt(short index) {
    ListNode<Type>* ptr = head;
    int n = 0;
    while(n != index){
        if (ptr == nullptr) return nullptr;
        ptr = ptr->next;
        n++;
    }
    return ptr;
}


template<typename Type> void LinkedList<Type>::insert(short int index, Type data) {
    ListNode<Type>* right = getAt(index);
    if (right == nullptr){
        pushBack(data);
        return;
    }
    ListNode<Type>* left = right->prev;
    if (left == nullptr) {
        pushFront(data);
        return;
    }
    ListNode<Type>* ptr = new ListNode(data);
    ptr->prev = left;
    ptr->next = right;
    left->next = ptr;
    right->prev = ptr;
}


template<typename Type> void LinkedList<Type>::erase(short index) {
    ListNode<Type>* ptr = getAt(index);
    if (ptr == nullptr){
        return;
    }
    if (ptr->prev == nullptr){
        popFront();
        return;
    }
    if (ptr->next == nullptr){
        popBack();
        return;
    }
    ListNode<Type>* left = ptr->prev;
    ListNode<Type>* right = ptr->next;
    left->next = right;
    right->prev = left;
    delete ptr;
}


template<typename Type> void LinkedList<Type>::swap(short index1, short index2) {
    ListNode<Type>* ptr1 = getAt(index1);
    ListNode<Type>* ptr2 = getAt(index2);
    ListNode<Type>* left1 = getAt(index1-1);
    ListNode<Type>* left2 = getAt(index2-1);
    ListNode<Type>* right1 = getAt(index1+1);
    ListNode<Type>* right2 = getAt(index2+1);

    if (ptr1 == nullptr) return;
    else if (ptr2 == nullptr) return;
    else if (index1 == index2) return;

    if (left1 != nullptr) {
        left1->next = ptr2;
    } else {
        head = ptr2;
    }

    if (left2 != nullptr) {
        left2->next = ptr1;
    } else {
        head = ptr1;
    }

    if (right1 != nullptr) {
        right1->prev = ptr2;
    } else{
        tail = ptr2;
    }

    if (right2 != nullptr) {
        right2->prev = ptr1;
    } else{
        tail = ptr1;
    }

    ListNode<Type>* temp = ptr1->next;
    ptr1->next = ptr2->next;
    ptr2->next = temp;
    temp = ptr1->prev;
    ptr1->prev = ptr2->prev;
    ptr2->prev = temp;
}


void clearStream() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.sync();
}


template<typename Type> void LinkedList<Type>::print() {
    std::cout << "[ ";
    for (ListNode<Type>*ptr = head; ptr != nullptr; ptr = ptr->next){
        std::cout << ptr->data << " ";
    }
    std::cout << "]";
}


template<typename Type> void LinkedList<Type>::fill() {
    Type value;
    while (std::cin >> value) {
        this->pushBack(value);
        if (std::cin.peek() == '\n') {
            break;
        }
    }
    clearStream();
}


#endif