//
// Created by mars on 2021/6/17.
//

#ifndef INC_1_SORT__STUDENT_H_
#define INC_1_SORT__STUDENT_H_
#include <iostream>

using namespace std;

struct Student {
  string name;
  int score;

  bool operator<(const Student &otherStudent) const {
	return score != otherStudent.score ? score > otherStudent.score : name < otherStudent.name;
  }

  friend ostream &operator<<(ostream &os, Student &student) {
	os << "Student: " << student.name << " " << student.score;
	return os;
  }
};

#endif //INC_1_SORT__STUDENT_H_
