#pragma once
#include "Assessments.h"

class Assignment : public Assessment {
public:
    Assignment(string id,float r,float m) : Assessment(id,"Assignment",r,m) {}
     void displayWeightage(){
         cout << "Assignment ID: " << assessmentID << endl;
        cout << "Score: " << rawScore << "/" << maxScore << endl;
        cout << "Weightage: " <<  induvidualWeightage << "%" << endl;
    }
};