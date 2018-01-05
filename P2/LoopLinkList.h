//
// Created by 阿思亘 on 23/10/2017.
//

#ifndef P2_LOOPLINKLIST_H
#define P2_LOOPLINKLIST_H

#include "LinkNode.h"
#include <iostream>

template<typename T>
class LoopLinkList {
private:
    int _size = 0;
    int _numSkipped = 0;
    int _startPos = 0;
    int _numLeft = 0;
public:
    LinkNode<T> *head = nullptr;
    LinkNode<T> *start = nullptr;
    void eliminateByGap();

    LoopLinkList<T>(int size, int startPos, int gap, int numLeft);
    ~LoopLinkList();
};

template<typename T>
void LoopLinkList<T>::eliminateByGap() {
    LinkNode<T> *current = start;
    LinkNode<T> *last = nullptr;
    for (int i = 1; i <= _size - _numLeft; i++) {
        for (int j = 1; j <= _numSkipped; j++) {
            if (j == _numSkipped)
                last = current;
            current = current->next;
        }
        std::cout << "第" << i << "个死者的位置是" << *(current->getValue())
                  << std::endl;
        auto temp = current;
        current = current->next;
        last->next = current;
        if (temp == head)
            head = temp->next;
        delete temp;
    }
}

template<typename T>
LoopLinkList<T>::LoopLinkList(int size, int startPos, int gap, int numLeft):
        _size(size), _numSkipped(gap - 1), _numLeft(numLeft), _startPos(startPos) {

    LinkNode<T> *current, *last = nullptr;
    for (int i = 1; i <= _size; i++) {
        current = new LinkNode<T>(i);
        if (head == nullptr)
            head = current;
        if (i == startPos)
            start = current;
        if (last != nullptr)
            last->next = current;
        last = current;
    }

    current->next = head;
}

template<typename T>
LoopLinkList<T>::~LoopLinkList() {
    std::cout << "幸存者分别是：";
    for (int i = 1; i <= _numLeft; i++) {
        auto temp = head;
        head = head->next;
        std::cout << *(temp->getValue()) << " ";
        delete (temp);
    }
}

#endif //P2_LOOPLINKLIST_H
