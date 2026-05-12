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
void DatabaseManager::saveAllStudents(const vector<Student*>& allStudents) {
    ofstream file("data/students.txt");

    for(int i = 0; i < allStudents.size(); i++) {
            file << allStudents[i]->getID() << "|"<< allStudents[i]->getName() << "|"<< allStudents[i]->getEmail() << "|"<< allStudents[i]->getType() << "|"<< allStudents[i]->getGPA() << endl;
        }
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
        if(id.empty() || id == "\n" || id == "\r") continue;
     try{
     
     getline(file,name,'|');;//reads till |
     getline(file,email,'|');
     getline(file,type,'|');
     getline(file,strGPA);//reads gpa s string like this
     if(strGPA.empty()){
        throw string("Missing GPA data");
     }
       
     gpa=stof(strGPA);//convert in float this avoids buffer error
     if(type=="Exchange Student"){ //checking type and creating obj of that type to add to vector
        loadedStudents.push_back(new ExchangeStudent (id,name,email));
     } else if(type=="Regular Student"){
        loadedStudents.push_back(new RegularStudent (id,name,email,gpa));
     }else if(type=="Scholarship Student"){
        loadedStudents.push_back(new ScholarshipStudent (id,name,email,gpa));
     }
    }
catch(string error){
    cout<<"Skipping Student "<<id<<" : "<<error<<endl;
}catch(...) {
    continue;
}
    }
    if(loadedStudents.empty()){
        cout<<"No Students\n";
    }
    
return loadedStudents;
}
//TEACHERS
void DatabaseManager::saveAllTeachers(const vector<Teacher*>& allTeachers){
    ofstream file("data/Teachers.txt");
    for(int i = 0; i < allTeachers.size(); i++) {
            file << allTeachers[i]->getID() << "|" << allTeachers[i]->getName() << "|" << allTeachers[i]->getEmail() << "|"<< allTeachers[i]->getAvgFeedBackScore() << endl;
        }
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
     if(id.empty() || id == "\n" || id == "\r") continue;
     try {
     getline(file,name,'|');;//reads till |
     getline(file,email,'|');
    
     getline(file,StrScore);//reads feedback score as string like this
         avgScore=stof(StrScore);//convert in float this avoids buffer error
      Teacher* t = new Teacher(id, email, name);
      t->setAvgFeedBackScore(avgScore);
      loadedTeachers.push_back(t);
    }catch(...){
     continue;
    }
}
    if(loadedTeachers.empty()){
        cout<<"No Teachers\n";
    }
    
return loadedTeachers;
}
//Courses
 void DatabaseManager::saveAllCourses(const vector<Course*>& allCourses){
  ofstream file("data/Courses.txt");
    for(int i = 0; i < allCourses.size(); i++) {
            file << allCourses[i]->getType() << "|" << allCourses[i]->getCourseID() << "|"<< allCourses[i]->getTitle() << "|"<< allCourses[i]->getTeacherID() << endl;
        }
 }
vector<Course*> DatabaseManager::loadCourses(){
 vector<Course*>loadedCourses;
    ifstream file("data/Courses.txt");
    
     if(!file.is_open()) {
        cout << "File not Opening! ERROR!\n";
        return loadedCourses;
    }
    string Cid,title,type,Tid;
   
    while(getline(file, type, '|')){ 
        if(type.empty() || type == "\n" || type == "\r") continue;   
        try {
     getline(file, Cid, '|'); 
     getline(file, title, '|');
    getline(file, Tid);
     
       
      if(type=="CoreCourse"){ //checking type and creating obj of that type to add to vector
      CoreCourse* obj = new CoreCourse(Cid, Tid, title);
      loadedCourses.push_back(obj);
            } else if(type=="ElectiveCourse"){
      ElectiveCourse* obj = new ElectiveCourse(Cid, Tid, title);
      loadedCourses.push_back(obj);
            } else if(type=="LabCourse"){
     LabCourse* obj = new LabCourse(Cid, Tid, title);
     loadedCourses.push_back(obj);
            }
    }catch(...){
        continue;
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
     if(id.empty() || id == "\n" || id == "\r") continue; 
        try {
     
     getline(file,cap,'|');;//reads till |
     getline(file,comp);
    
         intCap=stoi(cap);//convert in int this avoids buffer error
      bComp=stoi(comp);
     
      loadedVenues.push_back(new Venue(id,intCap,bComp));
    }catch(...){
continue;
    }
}
    if(loadedVenues.empty()){
        cout<<"No Teachers\n";
    }
    
return loadedVenues;
        }
      void DatabaseManager::saveAllVenues(const vector<Venue*>& allVenues){
             ofstream file("data/Venues.txt");
             for(int i = 0; i < allVenues.size(); i++){
            file << allVenues[i]->getID() << "|" << allVenues[i]->getCapacity() << "|"<< allVenues[i]->getComputers() << endl;
        }
    }
        

        //Section
        void DatabaseManager::saveAllSections(const vector<Section*>& allSections) {

    ofstream file("data/sections.txt");
    for(int i = 0; i < allSections.size(); i++) {
            file << allSections[i]->getSectionID() << "|" << allSections[i]->getCourseID()<< "|"<<allSections[i]->getTeacherID()<< "|"<<allSections[i]->getVenue()<< "|"<< allSections[i]->getTimeSlot() << endl;
        }
        }

        vector<Section*> DatabaseManager::loadSections() {

    vector<Section*> loadedsections;
    ifstream file("data/sections.txt");

    if (!file.is_open()) {
        cout << "Sections file not found\n";
        return loadedsections;
    }

    string sid, cid, tid, vid, time;

    while (getline(file, sid, '|')) {

        getline(file, cid, '|');
        getline(file, tid, '|');
        getline(file, vid, '|');
        getline(file, time);

        Section* s = new Section(sid, cid, tid);
        s->setVenue(vid);
        s->setTime(time);

        loadedsections.push_back(s);
    }

    return loadedsections;
}
//Assesments

void DatabaseManager::saveAssessment(string courseID, string studentID, string type, float raw, float max) {
    ofstream file("data/assessments.txt", ios_base::app);
    if (file.is_open()) {
        file << courseID << "|" << studentID << "|" << type << "|" << raw << "|" << max << endl;
        file.close();
    }
}

void DatabaseManager::loadAssessments(vector<Course*>& allCourses, const vector<Section*>& allSections) {
    ifstream file("data/assessments.txt");
    if (!file.is_open()) {
        cout << "Error! file could not open\n";
        return;
    }
    string courseID, studentID, type, strRaw, strMax;
    
    while (getline(file, courseID, '|')) {
        if (courseID.empty() || courseID == "\n" || courseID == "\r") continue;
        try {
            getline(file, studentID, '|');
            getline(file, type, '|');
            getline(file, strRaw, '|');
            getline(file, strMax);

            float raw = stof(strRaw);
            float max = stof(strMax);

            string assessName = "";
            if (type == "Quiz") assessName = "Q_" + studentID;
            else if (type == "Assignment") assessName = "A_" + studentID;
            else if (type == "Exam") assessName = "E_" + studentID;

            for (int i = 0; i < allCourses.size(); i++) {
                if (allCourses[i]->getCourseID() == courseID) {
                    if (type == "Quiz") {
                        allCourses[i]->addQuiz(new Quiz(assessName, studentID, raw, max));
                    } else if (type == "Assignment") {
                        allCourses[i]->addAssignment(new Assignment(assessName, studentID, raw, max));
                    } else if (type == "Exam") {
                        allCourses[i]->addExam(new Exam(assessName, studentID, raw, max));
                    }
                    break; 
                }
            }
        } catch(string error) {
            cout << "Skipping Assessment for " << courseID << ": " << error << endl;
            continue;
        } catch(...) {
            continue;
        }
    }
}

//enrolled students
void DatabaseManager::saveEnrollment(string studentID, string courseID) {
    ofstream file("data/enrollments.txt", ios::app);
    if (file.is_open()) {
        file << studentID << "|" << courseID << endl;
        file.close();
    }
}

void DatabaseManager::loadEnrollments(vector<Student*>& allStudents, vector<Course*>& allCourses) {
    ifstream file("data/enrollments.txt");
    if (!file.is_open()) {
        cout<<"Error! File could not open\n";
        return;
    }

    string sID, cID;
    while (getline(file, sID, '|')) {
        if (sID.empty() || sID == "\n" || sID == "\r") continue;
        getline(file, cID); 
        Student* foundStudent = nullptr;
        Course* foundCourse = nullptr;

        for (int i = 0; i < allStudents.size(); i++) {
            if (allStudents[i]->getID() == sID) {
                foundStudent = allStudents[i];
                break;
            }
        }
        for (int i = 0; i < allCourses.size(); i++) {
            if (allCourses[i]->getCourseID() == cID) {
                foundCourse = allCourses[i];
                break;
            }
        }
        if (foundStudent != nullptr && foundCourse != nullptr) {
            foundCourse->restoreStudent(foundStudent);
            foundStudent->addCourse(foundCourse);
        }
    }
}