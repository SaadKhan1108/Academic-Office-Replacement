#pragma once
#include "Assessments.h"

class Exam : public Assessment {
public:
    Exam(string id, string sID,float r,float m):Assessment(id,sID,"Exam",r,m) {}
    void displayAssessment(){
         cout << "Exam ID: " << assessmentID << endl;
        cout << "Score: " << rawScore << "/" << maxScore << endl;
        cout << "Weightage: " <<  weightage << "%" << endl;
    }
    

};