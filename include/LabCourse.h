#pragma once
#include<Course.h>
using namespace std;


class LabCourse:public Course{
     public:
     LabCourse(string Cid,string Tid,string title):Course(Cid,Tid,title){}
     string getType()override{
        return "LabCourse";
     }
     float getExamDuration(){
        return 0;//lab has no exam
            }
     float calculateFinalGrade(){
        
     }

};