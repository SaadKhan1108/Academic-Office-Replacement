#pragma once
#include"Course.h"
using namespace std;


class ElectiveCourse:public Course{
     public:
     ElectiveCourse(string Cid,string title,string Tid):Course(Cid,title,Tid){}
     string getType()override{
        return "ElectiveCourse";
     }
     float getExamDuration(){
        return 1;//core course exam is 3hrs long
     }
void displayCourse() override {
    cout << "Type: " << getType() << endl;
    cout << "Course ID: " << getCourseID() << endl;
    cout << "Title: " << getTitle() << endl;
    cout << "Teacher ID: " << getTeacherID() << endl;
    cout << "Students Enrolled: "<< getStudentCount() << endl;
    cout << "Exam Duration: "<< getExamDuration()<< " hours\n";

    
}
};