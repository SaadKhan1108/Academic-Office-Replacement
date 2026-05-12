#pragma once
#include "AcademicEntity.h"
#include <vector>
class Course;
class Student : public AcademicEntity {
protected:
    float GPA;
     vector<Course*>coursesEnrolledIn;
public:
    Student(string id="", string n="", string e="", float g=0): AcademicEntity(id, n, e), GPA(g) {}

    virtual float calculateGPA() = 0;
    //getters
    string getID(){
        return ID;
    }
    string getName(){
        return name;
    }
    string getEmail(){
        return email;
    }
    float getGPA(){
        return GPA;
    }
    void addCourse(Course*c){
        coursesEnrolledIn.push_back(c);
    }
    
    virtual string getType()=0;//each child class has to overide this in their own way
};