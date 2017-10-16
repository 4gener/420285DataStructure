//
// Created by 阿思亘 on 15/10/2017.
//

#include <iostream>
#include "ExamineeInfo.h"

std::istream &operator>>(std::istream &is, ExamineeInfo &info) {
    std::cout << "Please input the examinee's id, name, gender (1 for male, 0 for female), age, exam type in order.\n";
    is >> info._id >> info._name >> info._gender >> info._age >> info._examType;
    return is;
}

std::ostream &operator<<(std::ostream &os, ExamineeInfo &info) {
    os << "id: " << info._id << std::endl
       << "name: " << info._name << std::endl
       << "gender: " << (info._gender ? "male" : "female") << std::endl
       << "age: " << info._age << std::endl
       << "exam type: " << info._examType << std::endl;
    return os;
}