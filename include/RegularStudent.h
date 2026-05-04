#pragma once
#include "Student.h"

class RegularStudent : public Student {
public:
    RegularStudent(string id, string n, string e, float g)
        : Student(id, n, e, g) {}

    void displayProfile() override {
        cout << "Regular Student: " << name << " GPA: " << GPA << endl;
    }

    float calculateGPA() override {
        return GPA;
    }
};