#pragma once
#include<Course.h>
using namespace std;


class ElectiveCourse:public Course{
     public:
     ElectiveCourse(string Cid,string Tid,string title):Course(Cid,Tid,title){}
     string getType()override{
        return "ElectiveCourse";
     }
     float getExamDuration(){
        return 1;//core course exam is 3hrs long
     }
     float calculateFinalGrade(){
        
     }

};