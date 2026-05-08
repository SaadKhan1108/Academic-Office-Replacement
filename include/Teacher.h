#pragma once;
#include <AcademicEntity.h>
#include <vector>
using namespace std;

class Teacher:public AcademicEntity{
    vector<int>feedBackScores;
   vector <string> courseIDs;
    public:
    Teacher(string id,string email,string name):AcademicEntity(id,name,email){
    }
    


    double  getAvgFeedBackScore(){
        double avg=0;
                for(int i=0;i<feedBackScores.size();i++){
                   avg+=feedBackScores[i];
                }
                avg/=feedBackScores.size();
                return avg;
    }
    void addFeedback(){
        int score;
        cout<<"Enter Feedback score between 1 and 5 : \n";
        cin>>score;
while(score<1 ||score>5){
    cout<<"Score should be between 1 and 5!\n ";
    cin>>score;
}
feedBackScores.push_back(score);
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