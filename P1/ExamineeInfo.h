//
// Created by 阿思亘 on 15/10/2017.
//

#include <string>
#include <iostream>

#ifndef P1_EXAMINEEINFO_H
#define P1_EXAMINEEINFO_H

class ExamineeInfo {
private:
    int _id;
    std::string _name;
    bool _gender;
    int _age;
    std::string _examType;
public:
    friend std::istream &operator>>(std::istream &is, ExamineeInfo &info);
    friend std::ostream &operator<<(std::ostream &os, ExamineeInfo &info);
};


#endif //P1_EXAMINEEINFO_H
