#pragma once
#include "Student.h"

class ScholarshipStudent : public Student {
    float minGPA;

public:
    ScholarshipStudent(string id, string n, string e, float g, float min=2.0)//min gpa for probation is 2.0
        : Student(id, n, e, g), minGPA(min) {}

    void displayProfile() override {
    cout << "Scholatship Student" << endl;
    cout << "ID: " << ID << endl;
    cout<<" Name: " << name << endl;
    cout << "GPA: " << GPA << "    Min Required: " << minGPA << endl;
    if(GPA < minGPA) {
        cout << " ON PROBATION" << endl;
    } else {
        cout << " NOT ON PROBATION" << endl;
    }
}

    float calculateGPA() override;
    string getType() override{
        return "Scholarship Student";
    }
};