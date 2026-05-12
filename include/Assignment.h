#pragma once
#include "Assessments.h"

class Assignment : public Assessment {
public:
    Assignment(string id, string sID,float r,float m) : Assessment(id,sID,"Assignment",r,m) {}
     void displayAssessment(){
         cout << "Assignment ID: " << assessmentID << endl;
        cout << "Score: " << rawScore << "/" << maxScore << endl;
        cout << "Weightage: " <<  weightage << "%" << endl;
    }
};