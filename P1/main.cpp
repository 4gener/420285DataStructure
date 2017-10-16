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
            std::cout << "The system has " << infoSystem.size() << " examinee's information.\n";
        }
        else
            infoSystem.operate(operation);
    }

    std::cout << "See ya later!";

}

int getExamineeNum() {
    std::cout << "Welcome to the examinee info system.\n";
    std::cout << "Please input the amount of the examinees: ";
    int num;
    while (std::cin >> num && num <= 0) {
        std::cout << "Please input a valid number: ";
    };
    return num;
}