//
// Created by 76920 on 2020/9/18.
//

#ifndef SELECTIONSORT_STUDENT_H
#define SELECTIONSORT_STUDENT_H

#include "stdafx.h"

class Student {
public:
    Student() = delete;
    Student(string name, int score);
    bool operator<(const Student &otherStudent) const;
    friend ostream& operator<<(ostream &os, const Student &student);

private:
    string m_name;
    int m_score;
};

#endif //SELECTIONSORT_STUDENT_H
