#include <iostream>
#include "RegularStudent.h"
#include "ScholarshipStudent.h"
#include "ExchangeStudent.h"
#include "DatabaseManager.h"
#include "Course.h"
#include "CoreCourse.h"
#include "LabCourse.h"
#include "ElectiveCourse.h"
#include <vector>

using namespace std;

int main() {
  vector<Student*> students=DatabaseManager::loadStudents();//make vector to store diff obj of students' child classes
//   students.push_back(new RegularStudent("S1","Saad","email",3.5)); //pushback adds obj to end of vector
//   students.push_back(new ScholarshipStudent("S2","Ali","email",2.0,3.0));
//   students.push_back(new ExchangeStudent("S3","John","email"));

  // for(int i=0;i<students.size();i++){
  //  // DatabaseManager::saveStudent(students[i]);
  //     cout<<students[i]->getGPA()<<endl;
  // }
//     Teacher* t1 = new Teacher("T1", "Ahmed", "ahmed@gmail.com");

// t1->setAvgFeedBackScore(4.5);

// DatabaseManager::saveTeacher(t1);

// vector<Teacher*> teachers = DatabaseManager::loadTeachers();

// for(int i = 0; i < teachers.size(); i++) {
//     teachers[i]->displayProfile();
// }
    // Student* s1 = new RegularStudent("S1","Saad","email",3.5);
    // Student* s2 = new ScholarshipStudent("S2","Ali","email",2.0,3.0);
    // Student* s3 = new ExchangeStudent("S3","John","email");

    // s1->displayProfile();
    // s2->displayProfile();
    // s3->displayProfile();
    CoreCourse* c1 = new CoreCourse("C1", "OOP", "T1");
ElectiveCourse* c2 = new ElectiveCourse("C2", "AI", "T2");
LabCourse* c3 = new LabCourse("C3", "PF Lab", "T3");
c3->enrollStudent(new RegularStudent("S1","SAAD","saad@gmail",3.65));
DatabaseManager::saveCourse(c1);
DatabaseManager::saveCourse(c2);
DatabaseManager::saveCourse(c3);

vector<Course*> courses = DatabaseManager::loadCourses();

for(int i = 0; i < courses.size(); i++) {
    courses[i]->displayCourse();
}

    return 0;
}