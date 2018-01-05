//
// Created by 阿思亘 on 15/10/2017.
//

#include "LinkNode.h"
#include <iostream>

#ifndef P1_LINKLIST_H
#define P1_LINKLIST_H

enum Operation {
    CANCEL, INSERT, DELETE, FIND, MODIFY, GENERATE
};

std::istream &operator>>(std::istream &is, Operation &operation) {
    std::string operationStr;
    while (1) {
        std::cout << "\n请在下列操作中选择你想要的：\nCANCEL, INSERT, DELETE, FIND, MODIFY, or GENERATE\n";
        is >> operationStr;
        if (operationStr == "CANCEL") {
            operation = CANCEL;
            break;
        }
        else if (operationStr == "INSERT") {
            operation = INSERT;
            break;
        }
        else if (operationStr == "DELETE") {
            operation = DELETE;
            break;
        }
        else if (operationStr == "FIND") {
            operation = FIND;
            break;
        }
        else if (operationStr == "MODIFY") {
            operation = MODIFY;
            break;
        }
        else if (operationStr == "GENERATE") {
            operation = GENERATE;
            break;
        }
        else {
            std::cout << "非法输入\n";
        }
    }
    return is;
}

template<typename T>
class LinkList {
private:
    int _size;
public:
    LinkNode<T> *head;
    LinkNode<T> *last;
    void pushBack(T val);
    void insert(int pos);
    void del(int pos);

    void find(int pos);

    void modify(int pos);
    void operate(Operation &operation);

    int size() { return _size; }

    ~LinkList();
};

template<typename T>
void LinkList<T>::pushBack(T val) {
    auto node = new LinkNode<T>(val);
    if (last)
        last->next = node;
    else
        head = node;
    last = node;
    _size++;
}

template<typename T>
void LinkList<T>::operate(Operation &operation) {
    std::cout << "请输入你想操作的位置：";
    int pos;
    std::cin >> pos;
    switch (operation) {
        case INSERT:
            this->insert(pos);
            break;
        case FIND:
            this->find(pos);
            break;
        case MODIFY:
            this->modify(pos);
            break;
        case DELETE:
            this->del(pos);
            break;
        default:
            break;
    }
}

template<typename T>
void LinkList<T>::insert(int pos) {
    if (pos > _size + 1 || pos <= 0)
        std::cout << "操作位置非法\n";
    else {
        T val;
        std::cin >> val;
        auto node = new LinkNode<T>(val);
        if (node) {
            if (pos == 1) {
                if (_size == 0)
                    last = node;
                node->next = head;
                head = node;
            }
            else if (pos == _size + 1) {
                last->next = node;
                last = node;
            }
            else {
                auto destPrev = head;
                for (int i = 1; i < pos - 1; i++) {
                    destPrev = destPrev->next;
                }
                node->next = destPrev->next;
                destPrev->next = node;
            }
            _size++;
        }
        else {
            std::cout << "Memory full.";
        }
    }
}

template<typename T>
void LinkList<T>::del(int pos) {
    if (pos > _size || pos <= 0)
        std::cout << "操作位置非法\n";
    else {
        if (pos == 1) {
            if (_size == 1)
                last = nullptr;
            auto temp = head;
            head = head->next;
            delete (temp);
        }
        else {
            auto destPrev = head;
            for (int i = 1; i < pos - 1; i++) {
                destPrev = destPrev->next;
            }
            if (last == destPrev->next)
                last = destPrev;
            auto temp = destPrev->next;
            destPrev->next = destPrev->next->next;
            delete (temp);
        }
        _size--;
    }
}

template<typename T>
void LinkList<T>::find(int pos) {
    if (pos > _size || pos <= 0)
        std::cout << "操作位置非法\n";
    else {
        auto dest = head;
        for (int i = 1; i < pos; i++) {
            dest = dest->next;
        }
        std::cout << *(dest->getValue());
    }
}

template<typename T>
void LinkList<T>::modify(int pos) {
    if (pos > _size || pos <= 0)
        std::cout << "操作位置非法\n";
    else {
        auto destPrev = head;
        for (int i = 1; i < pos - 1; i++) {
            destPrev = destPrev->next;
        }
        T val;
        std::cin >> val;
        auto node = new LinkNode<T>(val);
        node->next = destPrev->next->next;
        delete (destPrev->next);
        destPrev->next = node;
    }
}

template<typename T>
LinkList<T>::~LinkList() {
    while (head) {
        auto temp = head;
        head = head->next;
        delete (temp);
    }
}

#endif //P1_LINKLIST_H
