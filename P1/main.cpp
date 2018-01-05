//
// Created by 阿思亘 on 15/10/2017.
//

#include <iostream>
#include "ExamineeInfo.h"
#include "LinkList.h"
#include <string>
#include "LinkNode.h"

int getExamineeNum();

int main() {
    LinkList<ExamineeInfo> infoSystem;  // get input size
    int examineeNum = getExamineeNum();

    for (int i = 0; i < examineeNum; i++) { // input
        ExamineeInfo newInfo;
        std::cin >> newInfo;
        infoSystem.pushBack(newInfo);
    }

    Operation operation;    // get operation type
    while (std::cin >> operation) { // operate
        if (operation == CANCEL) {
            break;
        }
        else if (operation == GENERATE) {
            std::cout << "系统总共有" << infoSystem.size() << "个考生的信息\n";
        }
        else
            infoSystem.operate(operation);
    }

    std::cout << "再会!";

}

int getExamineeNum() {
    std::cout << "欢迎来到考生信息系统\n";
    std::cout << "请输入考生人数：";
    int num;
    while (std::cin >> num && num <= 0) {
        std::cout << "请输入一个大于零的整数: ";
    };
    return num;
}