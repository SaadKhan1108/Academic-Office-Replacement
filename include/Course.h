#pragma once
#include<Student.h>
#include<vector>
using namespace std;


class Course{
    protected:
    string CourseID;
    string TeacherID;
    string title;
    int enrolledCount;
    float examWeightage;
    float assignmentWeightage;
    float quizWeightage;
  vector<Student*> StudentsEnrolled;
  public:
  Course(string Cid,string title,string Tid){
    CourseID=Cid;
    TeacherID=Tid;
    this->title=title;
    enrolledCount=0;
    examWeightage=0;
    assignmentWeightage=0;
    quizWeightage=0;
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
  int getStudentCount() {
      return enrolledCount;
    }
    void setStudentCount(int count) {
    enrolledCount = count;
}
     void setWeightages(){}//read from file

  virtual float calculateFinalGrade()=0;
  virtual float getExamDuration()=0;
virtual string getType()=0;
void enrollStudent(Student* s) {

    bool found = false;

    if (s == nullptr) {
        found = true;
    } else { //dont add if obj is null OR student already enrolled
        for (int i = 0; i < StudentsEnrolled.size(); i++) {
            if (StudentsEnrolled[i]->getID() == s->getID()) {
                cout << "Student already enrolled\n";
                found = true;
                break;
            }
        }
    }
    if (found==false) {
        StudentsEnrolled.push_back(s);
        enrolledCount++;
    }
}

virtual void displayCourse()=0;
};