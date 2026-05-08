#pragma once
#include <AcademicEntity.h>
#include <vector>
using namespace std;

class Teacher:public AcademicEntity{
    vector<int>feedBackScores;
    vector<string>feedBackComments;
   vector <string> courseIDs;
    float avgFeedbackScore;
    public:
    Teacher(string id,string email,string name):AcademicEntity(id,name,email){
        avgFeedbackScore=-1;//if no feedback
    }
    
string getID(){
    return ID;
}
string getEmail(){
    return email;
}
string getName(){
    return name;
}
    double getAvgFeedBackScore() {
   return avgFeedbackScore;
}

    void setAvgFeedBackScore(float score){
        avgFeedbackScore = score;
    }
    void addFeedback(){
        int score;
        cout<<"Enter Feedback score between 1 and 5 : \n";
        cin>>score;
while(score<1 ||score>5){
    cout<<"Score should be between 1 and 5!\n ";
    cin>>score;
}
string comment;
cout<<"Enter a comment : ";
cin>>comment;
double total = 0;

for(int i = 0; i < feedBackScores.size(); i++) {
    total += feedBackScores[i];
}

avgFeedbackScore = total / feedBackScores.size();
feedBackScores.push_back(score);
feedBackComments.push_back(comment);
    }
    void displayProfile()override{
         cout<<"Teacher: \n";
         cout<<"ID: "<<ID<<endl;
         cout<<"Name: " <<name<<endl;
         cout<<"Email: "<<email<<endl;
         cout<<"Average Feedback Score: "<<getAvgFeedBackScore()<<endl;
  }
    void assignCourse(string courseid){
    bool assigned=false;
for(int i=0;i<courseIDs.size();i++){
   
    if(courseIDs[i]==courseid){
        cout<<"Course is already assigned to this teacher\n";
        assigned=true;
        break;
    }
}
if(assigned==false)
    courseIDs.push_back(courseid);
}

};