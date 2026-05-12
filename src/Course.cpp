#include "Course.h"
#include "Quiz.h"
#include "Assessments.h"
#include "Student.h"
#include "Assignment.h"
#include "Exams.h"
#include "Quiz.h"
#include "DatabaseManager.h"
#include <fstream>

void Course::enrollStudent(Student* s,string currentTimeSlot, const vector<Section*>& allSections, const vector<Course*>& allCourses) {

    bool found = false;

    if (s == nullptr) {
        found = true;
    }else if(enrolledCount >= 50){
        cout << "Error: Course Capacity Full!\n";
        found =true;
    }
     else { //dont add if obj is null OR student already enrolled
        for (int i = 0; i < StudentsEnrolled.size(); i++) {
            if (StudentsEnrolled[i]->getID() == s->getID()) {
                cout << "Student already enrolled\n";
                found = true;
                break;
            }
        }
    }
    if (found == false) {//check if student is busy at that time in some other course
        for (int i = 0; i < allSections.size(); i++) {
            if (allSections[i]->getTimeSlot() == currentTimeSlot) {//check timeslot
                string conflictCourseID = allSections[i]->getCourseID();
                for (int j = 0; j < allCourses.size(); j++) {
                    if (allCourses[j]->getCourseID() == conflictCourseID) {
                        // Check if the student is already enrolled in that course
                        if (allCourses[j]->isStudentEnrolled(s->getID())) {
                            cout << "Conflict Error: Student already has a class at " << currentTimeSlot<< " in Course: " << conflictCourseID << endl;
                            found = true;
                            break;
                        }
                    }
                }
            }
            if (found==true) {
                 break;
                }
}
    }

if (found == false) {
    StudentsEnrolled.push_back(s);
    s->addCourse(this); 
    enrolledCount++;
 
    DatabaseManager::saveEnrollment(s->getID(), this->getCourseID());
    cout << "Registration successful for " << s->getName() << " in " << this->getTitle() << endl;
}

}

void Course::addQuiz(Quiz* q) {
    quizzes.push_back(q);
}
  
void Course::addAssignment(Assignment* q) {
    assignments.push_back(q);
}

void Course::addExam(Exam* q) {
    exams.push_back(q);
}

float Course::calculateFinalGrade(string studentID) {
    float total = 0;
    int studentExamCount = 0;
    for(int i=0; i<exams.size(); i++) {
        if(exams[i]->getStudentID() == studentID) {
            studentExamCount++;
        }
    }
    for(int i=0; i<exams.size(); i++){
        if(exams[i]->getStudentID() == studentID) {
            float weight = (studentExamCount > 0) ? (examWeightage / studentExamCount) : 0;
            total += exams[i]->getPercentage() * (weight / 100.0);
        }
    }

    int studentQuizCount = 0;
    for(int i=0; i<quizzes.size(); i++) {
        if(quizzes[i]->getStudentID() == studentID) {
            studentQuizCount++;
        }
    }
    for(int i=0; i<quizzes.size(); i++){
        if(quizzes[i]->getStudentID() == studentID) {
            float weight = (studentQuizCount > 0) ? (quizWeightage / studentQuizCount) : 0;
            total += quizzes[i]->getPercentage() * (weight / 100.0);
        }
    }

    int studentAssCount = 0;
    for(int i=0; i<assignments.size(); i++) if(assignments[i]->getStudentID() == studentID) studentAssCount++;
    for(int i=0; i<assignments.size(); i++){
        if(assignments[i]->getStudentID() == studentID) {
            float weight = (studentAssCount > 0) ? (assignmentWeightage / studentAssCount) : 0;
            total += assignments[i]->getPercentage() * (weight / 100.0);
        }
    }
    
    return total;
}

void Course::inputAssessmentMarks(string studentID, string assessmentID, string typeName, float obtainedScore, float maxScore) {
    bool found = false;

    if (typeName == "Exam") {
        for (int i = 0; i < exams.size(); i++) {
            if (exams[i]->getID() == assessmentID && exams[i]->getStudentID() == studentID) {
                exams[i]->setRawScore(obtainedScore);
                found = true; 
                break;
            }
        }
        if (!found) { 
            exams.push_back(new Exam(assessmentID, studentID, obtainedScore, maxScore));
             found = true;
             }
    }
    else if (typeName == "Quiz") {
        for (int i = 0; i < quizzes.size(); i++) {
            if (quizzes[i]->getID() == assessmentID && quizzes[i]->getStudentID() == studentID) {
                quizzes[i]->setRawScore(obtainedScore);
                found = true;
                 break;
            }
        }
        if (!found) {
             quizzes.push_back(new Quiz(assessmentID, studentID, obtainedScore, maxScore));
              found = true;
             }
    }
    else if (typeName == "Assignment") {
        for (int i = 0; i < assignments.size(); i++) {
            if (assignments[i]->getID() == assessmentID && assignments[i]->getStudentID() == studentID) {
                assignments[i]->setRawScore(obtainedScore);
                found = true; 
                break;
            }
        }
        if (!found) { 
            assignments.push_back(new Assignment(assessmentID, studentID, obtainedScore, maxScore));
             found = true; 
            }
    }

    if (found==true) {
        DatabaseManager::saveAssessment(this->CourseID, studentID, typeName, obtainedScore, maxScore);    
        cout << "Marks recorded successfully for Student " << studentID << "!" << endl;
    }
}


void Course::loadWeightages(){
    ifstream file("data/weightages.txt");

    if (!file.is_open()) {
        cout << "Weightages file could not open\n";
        return;
    }
    string courseType,strExam,strAssignment,strQuiz;
    while (getline(file, courseType, '|')){
        getline(file,strExam,'|');;//reads till |
     getline(file,strAssignment,'|'); 
     getline(file,strQuiz);
     if (courseType == getType()){
         examWeightage=stof(strExam);
      assignmentWeightage=stof(strAssignment);
      quizWeightage=stof(strQuiz);
      break;
    }
    }
     


    
}

bool Course::isStudentEnrolled(string studentID){
    for (int i = 0; i < StudentsEnrolled.size(); i++) {
        if (StudentsEnrolled[i]->getID() == studentID) {
            return true;
        }
    }
    return false;

}

void Course::setOverallWeightage(){
           bool validInput=false,isLab=false;
           if(getType()=="LabCourse"){
            isLab=true;
            examWeightage=0;
           }
           while (validInput==false)
           {
           float inputExam = 0, inputAssignment = 0, inputQuiz = 0;
           string strInput;
           if(!isLab){
            cout << "\nEnter Final Exam Weightage (min: 40, max: 50): ";
            cin >> strInput;

            bool isValidNum=true;
            for(int i=0;i<strInput.length();i++){
                char c=strInput[i];
                if (c < '0' || c > '9') {
                    if (c != '.'){
                          isValidNum = false;
                        break;
                    }
            }
           }

           if(!isValidNum){
            cout<< "Error: Invalid data type. Please enter a number.\n";
            cin.clear();
            cin.ignore(1000,'\n');
            continue;
           }
           inputExam=stof(strInput);

           if (inputExam < 40 || inputExam > 50) {
                cout << "Error: Final exam weightage must be between 40 and 50.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }
            examWeightage = inputExam;
        }
            cout << "Enter Assignments Weightage (min: 25): ";
        cin >> strInput;
        bool isValidNum=true;
            for(int i=0;i<strInput.length();i++){
                char c=strInput[i];
                if (c < '0' || c > '9') {
                    if (c != '.'){
                          isValidNum = false;
                        break;
                    }
            }
           }

           if(!isValidNum){
            cout<< "Error: Invalid data type. Please enter a number.\n";
            cin.clear();
            cin.ignore(1000,'\n');
            continue;
           }
           inputAssignment=stof(strInput);

           if (inputAssignment<25) {
                cout << "Error: Assignment weightage must be at least 25 .\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }
            assignmentWeightage = inputAssignment;
    
              cout << "Enter Quizzes Weightage (min: 25): ";
        cin >> strInput;
          
        isValidNum=true;
            for(int i=0;i<strInput.length();i++){
                char c=strInput[i];
                if (c < '0' || c > '9') {
                    if (c != '.'){
                          isValidNum = false;
                        break;
                    }
            }
           }

           if(!isValidNum){
            cout<< "Error: Invalid data type. Please enter a number.\n";
            cin.clear();
            cin.ignore(1000,'\n');
            continue;
           }
           inputQuiz=stof(strInput);

           if (inputQuiz<25) {
                cout << "Error: Quizzes weightage must be at least 25 .\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }
            quizWeightage = inputQuiz;
            float total = examWeightage + assignmentWeightage + quizWeightage;
            if(total!=100.00){
                cout<<"Total weightages must add upto 100\n";
                continue;
            }
            validInput = true;
            cout << "Weightages set successfully!\n";
        }

           
    }

void Course::restoreStudent(Student* s){
    StudentsEnrolled.push_back(s);
    s->addCourse(this);
}
