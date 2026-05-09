#include "../include/Course.h"
#include "Quiz.h"
#include "Assessments.h"
#include "Assignment.h"
#include "Exams.h"
#include <fstream>

void Course::enrollStudent(Student* s) {

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

void Course::addQuiz(Quiz* q) {
  bool exceededLimit=false;
    if(quizzes.size() >= 5) {
        cout << "Maximum 5 quizzes allowed\n";
        exceededLimit=true;
    }
    if(exceededLimit==false){
    quizzes.push_back(q);
    }
    //add code to redefine weights for each quiz
    distributeWeightage();
}
  
void Course::addAssignment(Assignment* q) {
  bool exceededLimit=false;
    if(assignments.size() >= 5) {
        cout << "Maximum 5 assignments allowed\n";
        exceededLimit=true;
    }
    if(exceededLimit==false){
    assignments.push_back(q);
    }
    //add code to redefine weights for each quiz
    distributeWeightage();
}

void Course::addExam(Exam* q) {
  bool exceededLimit=false;
    if(Fexam!=nullptr) {
        cout << "Maximum 1 Final exam is allowed\n";
        exceededLimit=true;
    }
    if(exceededLimit==false){
    Fexam=q;
    }
    //add code to redefine weights for each quiz
    distributeWeightage();
}
void Course::distributeWeightage(){

    if(quizzes.size()>0){
        float eachQuizzesWeightage=0;
        eachQuizzesWeightage=quizWeightage/quizzes.size();

        for(int i=0;i<quizzes.size();i++){
            quizzes[i]->setWeightage(eachQuizzesWeightage);
        }
    }
    if(assignments.size()>0){
        float eachAssignmentWeightage=0;
        eachAssignmentWeightage=assignmentWeightage/assignments.size();

        for(int i=0;i<assignments.size();i++){
            assignments[i]->setWeightage(eachAssignmentWeightage);
        }
    }
    if(Fexam!=nullptr){
        Fexam->setWeightage(examWeightage);
    }
}

float Course::calculateFinalGrade(){
    
    float total=0;
    if(Fexam!=nullptr){
        total += Fexam->getPercentage() *(Fexam->getWeightage() / 100);
    }
    for(int i=0;i<quizzes.size();i++){
        total+=quizzes[i]->getPercentage() *(quizzes[i]->getWeightage() / 100);
    }
     for(int i=0;i<assignments.size();i++){
        total+=assignments[i]->getPercentage() *(assignments[i]->getWeightage() / 100);
    }
    return total;
}