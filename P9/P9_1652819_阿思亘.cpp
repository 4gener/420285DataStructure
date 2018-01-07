#include <iostream>

struct TreeNode {
    int value;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int val) : value(val) {};

    ~TreeNode() {
        if (left) {
            delete (left);
        }
        if (right) {
            delete (right);
        }
    }
};

class BSTree {
private:
    TreeNode *_head = nullptr;
public:
    void insert(int val);
    void search(int val);
    void display();
    void display(TreeNode *treeNode);

    ~BSTree() {
        delete (_head);
    }
};

void BSTree::insert(int val) {
    TreeNode *current = _head;
    TreeNode *parent = nullptr;
    while (1) {
        if (current) {
            parent = current;
            if (current->value > val) {
                current = current->left;
            }
            else if (current->value < val) {
                current = current->right;
            }
            else if (current->value == val) {
                std::cout << "数字" << val << "已经存在" << std::endl;
                return;
            }
        }
        else {
            TreeNode *node = new TreeNode(val);
            if (parent) {
                if (parent->value > val) {
                    parent->left = node;
                }
                else {
                    parent->right = node;
                }
                parent->value > val ? parent->left : parent->right = node;
            }
            else {
                _head = node;
            }
            return;
        }
    }
}

void BSTree::search(int val) {
    TreeNode *current = _head;
    while (1) {
        if (current) {
            if (current->value > val) {
                current = current->left;
            }
            else if (current->value < val) {
                current = current->right;
            }
            else if (current->value == val) {
                std::cout << "数字" << val << "已经存在" << std::endl;
                return;
            }
        }
        else {
            std::cout << "数字" << val << "不存在" << std::endl;
            return;
        }
    }
}

void BSTree::display() {
    display(_head);
}

void BSTree::display(TreeNode *treeNode) {
    if (treeNode->left)
        display(treeNode->left);
    std::cout << treeNode->value << " -> ";
    if (treeNode->right)
        display(treeNode->right);
}

int main() {
    BSTree bsTree;
    std::cout << "二叉排序树来啦～" << std::endl
              << "1 --- 创建" << std::endl
              << "2 --- 插入" << std::endl
              << "3 --- 搜索" << std::endl
              << "4 --- 退出" << std::endl;

    while (1) {
        int operation;
        std::cout << std::endl << "请选择：";
        std::cin >> operation;

        switch (operation) {
            case 1:
                std::cout << "请输入所有的数字，0代表停止：" << std::endl;
                while (1) {
                    int num;
                    std::cin >> num;
                    if (num == 0)
                        break;
                    else
                        bsTree.insert(num);
                }
                bsTree.display();
                break;

            case 2:
                int insert;
                std::cout << "请输入要插入的数字：";
                std::cin >> insert;
                bsTree.insert(insert);
                break;

            case 3:
                std::cout << "请输入要查找的数字：";
                int search;
                std::cin >> search;
                bsTree.search(search);
                break;

            case 4:
                std::cout << "再会！" << std::endl;
                return 0;
            default:
                std::cout << "请输入一个正确的选择！";
        }
    }
}