#pragma once
#include "Student.h"

class ExchangeStudent : public Student {
public:
    ExchangeStudent(string id, string n, string e)
        : Student(id, n, e, 0) {}

    void displayProfile() override {
        cout << "Exchange Student: " << name << " (Pass/Fail)" << endl;
    }

    float calculateGPA() override {
        return 0; // no GPA
    }
};