#pragma once
#include "Student.h"

class ScholarshipStudent : public Student {
    float minGPA;

public:
    ScholarshipStudent(string id, string n, string e, float g, float min)
        : Student(id, n, e, g), minGPA(min) {}

    void displayProfile() override {
        cout << "Scholarship Student: " << name;
        if(GPA < minGPA)
            cout << " (On Probation)";
        cout << endl;
    }

    float calculateGPA() override {
        return GPA;
    }
};