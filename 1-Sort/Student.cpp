//
// Created by 76920 on 2020/9/18.
//

#include "Student.h"

Student::Student(string name, int score) {
    this->m_name = name;
    this->m_score = score;
}

bool Student::operator<(const Student &otherStudent) const {
    //return this->m_score < otherStudent.m_score;
    //在分数相同的情况下再比较名字字典序
    return this->m_score != otherStudent.m_score ?
            this->m_score < otherStudent.m_score : this->m_name < otherStudent.m_name;
}

ostream &operator<<(ostream &os, const Student &student) {
    return os << "Student: " << student.m_name << ", score: " << student.m_score << endl;
}
