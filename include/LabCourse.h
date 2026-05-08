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
        return 4;//core course exam is 3hrs long
     }
     float calculateFinalGrade(){
        
     }

};