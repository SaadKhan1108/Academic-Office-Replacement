#pragma once
#include "Assessments.h"

class Quiz : public Assessment {
public:
    Quiz(string id, string sID, float r, float m):Assessment(id,sID, "Quiz", r, m) {}
     void displayAssessment(){
         cout << "Quiz ID: " << assessmentID << endl;
        cout << "Score: " << rawScore << "/" << maxScore << endl;
        cout << "Weightage: " <<  weightage << "%" << endl;
    }
};