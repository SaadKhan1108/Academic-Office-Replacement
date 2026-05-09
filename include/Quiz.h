#pragma once
#include "Assessments.h"

class Quiz : public Assessment {
public:
    Quiz(string id, float r, float m):Assessment(id, "Quiz", r, m) {}
     void displayAssessment(){
         cout << "Quiz ID: " << assessmentID << endl;
        cout << "Score: " << rawScore << "/" << maxScore << endl;
        cout << "Weightage: " <<  weightage << "%" << endl;
    }
};