#include "tree.h"
#include <utility>


//Node constructors
Node::Node(std::string &inputString) {
    data = inputString;
    left = right = nullptr;
}


//Operation constructor
Operation::Operation(char op, std::string left, std::string right) {
    operation = op;
    leftOperand = std::move(left);
    rightOperand = std::move(right);
}


//Tree constructors
Tree::Tree() {
    root = nullptr;
}


Tree::Tree(std::string keyString) {

}


//Tree methods
Node *Tree::insert(Node *node, std::string keyString) {
    if(!node) return new Node(keyString);
    return node;
}