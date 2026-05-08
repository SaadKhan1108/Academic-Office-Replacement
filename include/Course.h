#pragma once
#include<Student.h>
#include<vector>
using namespace std;


class Course{
    protected:
    string CourseID;
    string TeacherID;
    string title;
  vector<Student*> StudentsEnrolled;
  public:
  Course(string Cid,string Tid,string title){
    CourseID=Cid;
    TeacherID=Tid;
    this->title=title;
  }
  string getCourseID(){
    return CourseID;
  }
  string getTeacherID(){
    return TeacherID;
  }
  string getTitle(){
    return title;
  }
  virtual float calculateFinalGrade()=0;
  virtual float getExamDuration()=0;
virtual string getType()=0;
void enrollStudents(Student *obj){
          StudentsEnrolled.push_back(obj);
}
};