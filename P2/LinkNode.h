//
// Created by 阿思亘 on 15/10/2017.
//

#ifndef P1_LINKNODE_H
#define P1_LINKNODE_H

template<typename T>
class LinkNode {
private:
    T _data;
public:
    LinkNode<T> *next = nullptr;
    LinkNode(T data);

    T *getValue() { return &_data; };
};

template<typename T>
LinkNode<T>::LinkNode(T data) {
    _data = data;
}

#endif //P1_LINKNODE_H
