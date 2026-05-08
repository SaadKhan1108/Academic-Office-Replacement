#include "../include/DatabaseManager.h"
#include "RegularStudent.h"
#include "ExchangeStudent.h"
#include "ScholarshipStudent.h"
#include "Teacher.h"
#include <fstream>
//STUDENT FILES
void DatabaseManager::saveStudent(Student* s) {
    ofstream file("data/students.txt",ios_base::app);//append mode to save prev data
    file << s->getID()<<"|"<<s->getName()<<"|"<<s->getEmail()<<"|"<<s->getType()<<"|"<<s->getGPA()<<endl;
}
vector<Student*> DatabaseManager::loadStudents(){
    vector<Student*>loadedStudents;
    ifstream file("data/students.txt");
    // string line;
    // getline(file,line);
     if(!file.is_open()) {
        cout << "File not Opening! ERROR!\n";
        return loadedStudents;
    }
    string id,name,type,email,strGPA;
     float gpa;
    while(getline(file,id,'|')){//while not end of file
     
     
     getline(file,name,'|');;//reads till |
     getline(file,email,'|');
     getline(file,type,'|');
     getline(file,strGPA);//reads gpa s string like this
         gpa=stof(strGPA);//convert in float this avoids buffer error
     if(type=="Exchange Student"){ //checking type and creating obj of that type to add to vector
        loadedStudents.push_back(new ExchangeStudent (id,name,email));
     } else if(type=="Regular Student"){
        loadedStudents.push_back(new RegularStudent (id,name,email,gpa));
     }else if(type=="Scholarship Student"){
        loadedStudents.push_back(new ScholarshipStudent (id,name,email,gpa));
     }

    }
    if(loadedStudents.empty()){
        cout<<"No Students\n";
    }
    
return loadedStudents;
}
//TEACHERS
void DatabaseManager::saveTeacher(Teacher *t){
    ofstream file("data/Teachers.txt",ios_base::app);//append mode to save prev data
    file<<t->getID()<<"|"<<t->getName()<<"|"<<t->getEmail()<<"|"<<t->getAvgFeedBackScore()<<endl;
}

vector<Teacher*> DatabaseManager::loadTeachers(){
    vector<Teacher*>loadedTeachers;
    ifstream file("data/Teachers.txt");
    
     if(!file.is_open()) {
        cout << "File not Opening! ERROR!\n";
        return loadedTeachers;
    }
    string id,name,email,StrScore;
    float avgScore;
    while(getline(file,id,'|')){//while not end of file
     
     
     getline(file,name,'|');;//reads till |
     getline(file,email,'|');
    
     getline(file,StrScore);//reads feedback score as string like this
         avgScore=stof(StrScore);//convert in float this avoids buffer error
      Teacher* t = new Teacher(id, email, name);
      t->setAvgFeedBackScore(avgScore);
      loadedTeachers.push_back(t);
    }
    if(loadedTeachers.empty()){
        cout<<"No Teachers\n";
    }
    
return loadedTeachers;
}
