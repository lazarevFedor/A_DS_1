#ifndef A_DS_STACK_H
#define A_DS_STACK_H

//StackNode class
template<typename Type> class StackNode {
public:
    Type data;
    int priority;
    StackNode* next;
    StackNode(Type &inputData, int inputPriority);

};


//StackNode constructor
template<typename Type> StackNode<Type>::StackNode(Type &inputData, int inputPriority) {
    data = inputData;
    priority = inputPriority;
    next = nullptr;
}


//Stack class
template<typename Type> class Stack {
public:
    StackNode<Type>* head, * tail;

    Stack();

    void popFront();

    void pushFront(Type data, int inputPriority);
};


//Stack constructor
template<typename Type> Stack<Type>::Stack(): head(nullptr), tail(nullptr){}


//Stack methods
template<typename Type> void Stack<Type>::pushFront(Type data, int inputPriority) {
    auto* node = new StackNode<Type>(data, inputPriority);
    node->next = head;
    head = node;
    if (tail == nullptr) tail = node;
}


template<typename Type> void Stack<Type>::popFront() {
    if (head == nullptr) return;
    if (head == tail){
        delete tail;
        head = tail = nullptr;
        return;
    }
    StackNode<Type>* node = head;
    head = node->next;
    delete node;
}


#endif //A_DS_STACK_H
