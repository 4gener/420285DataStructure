//
// Created by 阿思亘 on 22/11/2017.
//

#ifndef P6_TREENODE_H
#define P6_TREENODE_H

#include <vector>

template<typename T>
class TreeNode {
private:
    T _value;
    TreeNode<T> *_parent = nullptr;
    std::vector<TreeNode<T> *> _childVector;

public:
    TreeNode(T _value, TreeNode<T> *_parent) : _value(_value), _parent(_parent) {}

    T getValue() const {
        return _value;
    }

    void setValue(T value) {
        TreeNode::_value = value;
    }

    TreeNode<T> *getParent() {
        return _parent;
    }

    void setParent(TreeNode<T> *parent) {
        TreeNode::_parent = parent;
    }

    std::vector<TreeNode<T> *> &getChildVector() {
        return _childVector;
    }

    ~TreeNode<T>() {
        for (auto &child:_childVector) {
            delete (child);
        }
    }

    void addChild(T childValue) {
        TreeNode<T> *node = new TreeNode(childValue, this);
        _childVector.push_back(node);
    }

};

#endif //P6_TREENODE_H
