#include <iostream>
#include <algorithm>
#include "TreeNode.h"

template<typename T>
TreeNode<T> *findChild(TreeNode<T> *node, T val) {
    if (node->getValue() == val) {
        return node;
    }
    else if (!node->getChildVector().empty()) {
        for (auto &child:node->getChildVector()) {
            auto ans = findChild(child, val);
            if (ans) return ans;
        }
    }
    return nullptr;
}

template<typename T>
void removeFamily(TreeNode<T> *node, T val) {
    auto del = findChild(node, val);
    if (del) {
        std::cout << "Removed family of " << val << std::endl;
        std::swap(del, del->getParent()->getChildVector()[del->getParent()->getChildVector().size() - 1]);
        del->getParent()->getChildVector().pop_back();
        delete (del);
    }
    else {
        std::cout << "Invalid name" << std::endl;
    }
}

template<typename T>
void changeValue(TreeNode<T> *node, T val1, T val2) {
    auto des = findChild(node, val1);
    if (des) {
        des->setValue(val2);
        std::cout << "Changed name of " << val1 << " to " << val2 << std::endl;
    }
    else {
        std::cout << "Invalid name" << std::endl;
    }
}

template<typename T>
void completeFamily(TreeNode<T> *node, T val, int num) {
    auto des = findChild(node, val);
    if (des) {
        for (int i = 0; i < num; i++) {
            T name;
            std::cout << "Please input the child's name: ";
            std::cin >> name;
            des->addChild(name);
            std::cout << "Added child " << name << std::endl;
        }
    }
    else {
        std::cout << "invalid name" << std::endl;
    }
}

int main() {
    std::string ancestorName;
    std::cout << "Build a family first!" << std::endl
              << "Please input the name of the ancestor: ";
    std::cin >> ancestorName;
    TreeNode<std::string> *head = new TreeNode<std::string>(ancestorName, nullptr);

    while (1) {
        std::cout << std::endl
                  << "A to build a family, B to add a member" << std::endl
                  << "C to remove a family, D to change a member's name" << std::endl
                  << "E to quit" << std::endl
                  << "Please choose your operation: ";
        char op;
        std::cin >> op;

        if (op == 'E') {
            std::cout << std::endl << "See ya!";
            return 0;
        }

        std::string name;
        std::cout << std::endl
                  << "Please input the person's name that you want to operate on: ";
        std::cin >> name;

        switch (op) {
            case 'A': {
                int num;
                std::cout << "Please input the children's amount: ";
                std::cin >> num;
                completeFamily(head, name, num);
                break;
            }
            case 'B': {
                completeFamily(head, name, 1);
                break;
            }
            case 'C': {
                removeFamily(head, name);
                break;
            }
            case 'D': {
                std::string newName;
                std::cout << "Please input the new name: ";
                std::cin >> newName;
                changeValue(head, name, newName);
                break;
            }
            default: {
                std::cout << "Invalid operation" << std::endl;
                break;
            }
        }
    }
}

