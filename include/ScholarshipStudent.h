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

    float calculateGPA() override {
       if(coursesEnrolledIn.empty()){
        return 0.0;
       }
       float totalPoints=0;
       for(int i=0;i<coursesEnrolledIn.size();i++){
        totalPoints+=coursesEnrolledIn[i]->calculateFinalGrade();
       }
       float avgP=totalPoints/coursesEnrolledIn.size();  
       float gpa=(avgP/100.0)*4.0;
       GPA=gpa;
       return gpa;

    }
    string getType() override{
        return "Scholarship Student";
    }
};