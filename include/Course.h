#pragma once
#include "Assessments.h"
#include "Quiz.h"
#include "Assignment.h"
#include "Section.h"
#include "Exams.h"
#include<vector>
using namespace std;

class Student;
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
  vector<Quiz*> quizzes;  //upto 5 quizzes
 vector<Assignment*> assignments;
 vector<Exam*> exams;  
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
  virtual ~Course() {
    for (int i = 0; i < quizzes.size(); i++) {
        delete quizzes[i];
    }
    for (int i = 0; i < assignments.size(); i++) {
        delete assignments[i];
    }
    for (int i = 0; i < exams.size(); i++) {
        delete exams[i];
    }
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
 float getExamWeightage(){
  return examWeightage;
 }
 float getQuizWeightage(){
  return quizWeightage;
 }
 float getAssignmentWeightage(){
  return assignmentWeightage;
 }
  void addQuiz(Quiz* q) ;
  void addAssignment(Assignment* q) ;
  void addExam(Exam* q) ; 
void loadWeightages();
 float calculateFinalGrade(string studentID);
 void setOverallWeightage();
 void inputAssessmentMarks(string studentID, string assessmentID, string typeName, float obtainedScore, float maxScore);
  virtual float getExamDuration()=0;
virtual string getType()=0;
void enrollStudent(Student* s, string currentTimeSlot, const vector<Section*>& allSections, const vector<Course*>& allCourses);
virtual void displayCourse()=0;
bool isStudentEnrolled(string studentID);
void restoreStudent(Student* s);
};