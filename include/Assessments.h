#pragma once
#include <iostream>
using namespace std;

class Assessment {

protected:
    string assessmentID;
    string type;
    float rawScore;
    float maxScore;
    float weightage;//calculate from num of this type of assesmmnets

public:
    Assessment(string id, string t, float r, float m):assessmentID(id),type(t),rawScore(r),maxScore(m){
        weightage=0;
    }
    float getPercentage() {
        if (maxScore == 0) return 0;
        return (rawScore / maxScore) * 100;
    }
    string getType() {
        return type;
    }
    string getID() {
        return assessmentID;
    }
    float getWeightage() {
        return weightage;
    }
    void setWeightage(float w) {
       weightage=w;
    }
     float getRawScore() {
        return rawScore;
    }
      void setRawScore(float obtainedMarks){
        rawScore=obtainedMarks;
      }
    float getMaxScore() {
        return maxScore;
    }
   
    virtual void displayAssessment() = 0;
};