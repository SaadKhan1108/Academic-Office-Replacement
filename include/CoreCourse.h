#pragma once
#include<Course.h>
using namespace std;


class CoreCourse:public Course{
     public:
     CoreCourse(string Cid,string Tid,string title):Course(Cid,Tid,title){}
     string getType()override{
        return "CoreCourse";
     }
     float getExamDuration(){
        return 3.0;//core course exam is 3hrs long
     }
     float calculateFinalGrade(){
        
     }

};