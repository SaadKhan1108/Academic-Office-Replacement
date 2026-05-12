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

void DatabaseManager::saveAssessment(string sectionID, string type, float raw, float max) {
    ofstream file("data/assessments.txt", ios_base::app);
    if (file.is_open()) {
        file << sectionID << "|" << type << "|" << raw << "|" << max << endl;
        file.close();
    }
}

void DatabaseManager::loadAssessments(vector<Course*>& allCourses, const vector<Section*>& allSections) {
    ifstream file("data/assessments.txt");
    if (!file.is_open()) {
        cout<<"Error! file could not open\n";
        return;
    }
    string sectionID, type, strRaw, strMax;
    while (getline(file, sectionID, '|')) {
       try{
        if (sectionID.empty()){ 
            continue;
        }
        getline(file, type, '|');
        getline(file, strRaw, '|');
        getline(file, strMax);

        float raw = stof(strRaw);
        float max = stof(strMax);

        // find which courseID belongs to this sectionID
        string targetCourseID = "";
        for (int i = 0; i < allSections.size(); i++) {
            if (allSections[i]->getSectionID() == sectionID) {//search sections to find this section ang get courseID
                targetCourseID = allSections[i]->getCourseID();
                break;
            }
        }
 //Find that Course object and add the assessment
        if (targetCourseID != "") {
            for (int i = 0; i < allCourses.size(); i++) {
                if (allCourses[i]->getCourseID() == targetCourseID) {
                    if (type == "Quiz") {
                        allCourses[i]->addQuiz(new Quiz("Q_" + sectionID, raw, max));
                    } else if (type == "Assignment") {
                        allCourses[i]->addAssignment(new Assignment("A_" + sectionID, raw, max));
                    } else if (type == "Exam") {
                        allCourses[i]->addExam(new Exam("E_" + sectionID, raw, max));
                    }
                    break; 
                }
            }
        }
    }catch(string error){
cout << "Skipping Assessment for " << sectionID << ": " << error << endl;
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
        }
    }
}