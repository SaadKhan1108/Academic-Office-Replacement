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
        return "Regular Student";
    }
};