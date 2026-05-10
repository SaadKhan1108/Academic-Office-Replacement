#include "DatabaseManager.h"
#include "Student.h"
#include "RegularStudent.h"
#include "ExchangeStudent.h"
#include "ScholarshipStudent.h"
#include "CoreCourse.h"
#include "LabCourse.h"
#include "ElectiveCourse.h"
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
//Courses
 void DatabaseManager::saveCourse(Course*s){
  ofstream file("data/Courses.txt",ios_base::app);//append mode to save prev data
    file << s->getCourseID()<<"|"<<s->getTitle()<<"|"<<s->getTeacherID()<<"|"<<s->getType()<<"|"<<s->getStudentCount()<<endl;
 }
vector<Course*> DatabaseManager::loadCourses(){
 vector<Course*>loadedCourses;
    ifstream file("data/Courses.txt");
    
     if(!file.is_open()) {
        cout << "File not Opening! ERROR!\n";
        return loadedCourses;
    }
    string Cid,title,type,Tid,StrStuCount;
    int StuCount=0;
    while(getline(file,Cid,'|')){//while can read data
     getline(file,title,'|');;//reads till |
     getline(file,Tid,'|'); 
     getline(file,type,'|');//reads feedback score as string like this
     getline(file,StrStuCount);
        StuCount=stoi(StrStuCount);
      if(type=="CoreCourse"){ //checking type and creating obj of that type to add to vector
       CoreCourse* obj = new CoreCourse(Cid, Tid, title);
        obj->setStudentCount(StuCount);
        loadedCourses.push_back(obj);
     } else if(type=="ElectiveCourse"){
        ElectiveCourse* obj = new ElectiveCourse(Cid, Tid, title);
        obj->setStudentCount(StuCount);
        loadedCourses.push_back(obj);
     }else if(type=="LabCourse"){
       LabCourse* obj = new LabCourse(Cid, Tid, title);
        obj->setStudentCount(StuCount);
        loadedCourses.push_back(obj);
     }
    }
    if(loadedCourses.empty()){
        cout<<"No Courses\n";
    }
    
return loadedCourses;
    }


    //Weightage. load is in course
    void DatabaseManager:: saveWeightages(Course* c){
         ofstream file("data/weightages.txt", ios::app);
         file << c->getType() << "|"<< c->getExamWeightage() << "|"<< c->getAssignmentWeightage() << "|" << c->getQuizWeightage()<< endl;
           cout<<"Weightages saved!\n";
        }

        //Venue
        vector<Venue*> DatabaseManager::loadVenues(){
            vector<Venue*>loadedVenues;
    ifstream file("data/Venues.txt");
    
     if(!file.is_open()) {
        cout << "File not Opening! ERROR!\n";
        return loadedVenues;
    }
    string id,cap,comp;
    int intCap;
    bool bComp;
    while(getline(file,id,'|')){//while not end of file
     
     
     getline(file,cap,'|');;//reads till |
     getline(file,comp);
    
         intCap=stoi(cap);//convert in int this avoids buffer error
      bComp=stoi(comp);
     
      loadedVenues.push_back(new Venue(id,intCap,bComp));
    }
    if(loadedVenues.empty()){
        cout<<"No Teachers\n";
    }
    
return loadedVenues;
        }
        void DatabaseManager::saveVenue(Venue*v){
             ofstream file("data/Venues.txt",ios_base::app);//append mode to save prev data
                file << v->getID()<<"|"<<v->getCapacity()<<"|"<<v->getComputers()<<endl;
        }
