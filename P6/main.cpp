#include <iostream>
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
        std::cout << "移除了" << val << "的家庭" << std::endl;
        std::swap(del, del->getParent()->getChildVector()[del->getParent()->getChildVector().size() - 1]);
        del->getParent()->getChildVector().pop_back();
        delete (del);
    }
    else {
        std::cout << "非法的人名" << std::endl;
    }
}

template<typename T>
void changeValue(TreeNode<T> *node, T val1, T val2) {
    auto des = findChild(node, val1);
    if (des) {
        des->setValue(val2);
        std::cout << "将" << val1 << "的名字改为" << val2 << std::endl;
    }
    else {
        std::cout << "无效的名字" << std::endl;
    }
}

template<typename T>
void completeFamily(TreeNode<T> *node, T val, int num) {
    auto des = findChild(node, val);
    if (des) {
        for (int i = 0; i < num; i++) {
            T name;
            std::cout << "请输入人名：";
            std::cin >> name;
            des->addChild(name);
            std::cout << "新增孩子" << name << std::endl;
        }
    }
    else {
        std::cout << "无效的名字" << std::endl;
    }
}

int main() {
    std::string ancestorName;
    std::cout << "先建立一个家庭吧！" << std::endl
              << "请输入祖先的名字：";
    std::cin >> ancestorName;
    TreeNode<std::string> *head = new TreeNode<std::string>(ancestorName, nullptr);

    while (1) {
        std::cout << std::endl
                  << "选A以完善家庭，B以添加家庭成员" << std::endl
                  << "选C以移除家庭，D以更改成员姓名" << std::endl
                  << "按E以退出" << std::endl
                  << "请选择你的操作：";
        char op;
        std::cin >> op;

        if (op == 'E') {
            std::cout << std::endl << "再会！";
            return 0;
        }

        std::string name;
        std::cout << std::endl
                  << "请输入你想操作的人的人名：";
        std::cin >> name;

        switch (op) {
            case 'A': {
                int num;
                std::cout << "请输入孩子的数量：";
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
                std::cout << "请输入新名字：";
                std::cin >> newName;
                changeValue(head, name, newName);
                break;
            }
            default: {
                std::cout << "无效的操作" << std::endl;
                break;
            }
        }
    }
}

