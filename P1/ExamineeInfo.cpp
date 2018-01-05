//
// Created by 阿思亘 on 15/10/2017.
//

#include <iostream>
#include "ExamineeInfo.h"

std::istream &operator>>(std::istream &is, ExamineeInfo &info) {
    std::cout << "请依次输入考生的考号，姓名，性别（1为男，0为女），年龄以及报考类别：\n";
    is >> info._id >> info._name >> info._gender >> info._age >> info._examType;
    return is;
}

std::ostream &operator<<(std::ostream &os, ExamineeInfo &info) {
    os << "学号：" << info._id << std::endl
       << "姓名：" << info._name << std::endl
       << "性别：" << (info._gender ? "男" : "女") << std::endl
       << "年龄：" << info._age << std::endl
       << "考试类型：" << info._examType << std::endl;
    return os;
}