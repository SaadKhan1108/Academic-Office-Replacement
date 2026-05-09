#pragma once
#include"Course.h"
using namespace std;


class LabCourse:public Course{
     public:
     LabCourse(string Cid,string title,string Tid):Course(Cid,title,Tid){}
     string getType()override{
        return "LabCourse";
     }
     float getExamDuration(){
        return 0;//lab has no exam
            }
    
void displayCourse() override {
    cout << "Type: " << getType() << endl;
    cout << "Course ID: " << getCourseID() << endl;
    cout << "Title: " << getTitle() << endl;
    cout << "Teacher ID: " << getTeacherID() << endl;
    cout << "Students Enrolled: "<< getStudentCount() << endl;
    

    
}
};