#include <iostream>
#include <vector>

#include "DatabaseManager.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"

#include "CoreCourse.h"
#include "ElectiveCourse.h"
#include "LabCourse.h"

using namespace std;

int main() {

   DatabaseManager::saveStudent(new RegularStudent("S1","Saad","saad@gmail.com",3.5));
DatabaseManager::saveStudent(new ScholarshipStudent("S2","Ali","ali@gmail.com",2.8));
DatabaseManager::saveStudent(new ExchangeStudent("S3","John","john@gmail.com"));
DatabaseManager::saveTeacher(new Teacher("T1","Ahmed","ahmed@gmail.com"));
DatabaseManager::saveTeacher(new Teacher("T2","Usman","usman@gmail.com"));
DatabaseManager::saveCourse(new CoreCourse("C1","OOP","T1"));
DatabaseManager::saveCourse(new ElectiveCourse("C2","AI","T2"));
DatabaseManager::saveCourse(new LabCourse("C3","PF Lab","T1"));
cout << "===== LOADING STUDENTS =====\n";
    vector<Student*> students = DatabaseManager::loadStudents();

    for(int i = 0; i < students.size(); i++) {
        students[i]->displayProfile();
        cout << endl;
    }

    cout << "===== LOADING TEACHERS =====\n";
    vector<Teacher*> teachers = DatabaseManager::loadTeachers();

    for(int i = 0; i < teachers.size(); i++) {
        teachers[i]->displayProfile();
        cout << endl;
    }

    cout << "===== LOADING COURSES =====\n";
    vector<Course*> courses = DatabaseManager::loadCourses();

    for(int i = 0; i < courses.size(); i++) {
        courses[i]->displayCourse();

        cout << "Type: " << courses[i]->getType() << endl;
        cout << "Students Enrolled: " << courses[i]->getStudentCount() << endl;

        cout << endl;
    }

    cout << "===== TEST ENROLLMENT =====\n";
    if(!students.empty() && !courses.empty()) {
        courses[0]->enrollStudent(students[0]);
        courses[0]->enrollStudent(students[0]); // duplicate test

        cout << "After enrolling:\n";
        courses[0]->displayCourse();
        cout << "Students Enrolled: "
             << courses[0]->getStudentCount() << endl;
    }

    cout << "===== TEST COMPLETE =====\n";


    return 0;
}