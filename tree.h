#ifndef A_DS_TREE_H
#define A_DS_TREE_H

#include <string>


class Node {
    std::string data;
    Node* left;
    Node* right;
public:
    Node(std::string &inputString);


    friend class Tree;
};


class Tree {
    Node* root;
public:
    Tree();

    Tree(std::string keyString);


    Node* insert(Node* node,  std::string keyString);
};


struct Operation {
    char operation;
    std::string leftOperand;
    std::string rightOperand;

    Operation(char op, std::string left, std::string right);
};


#endif