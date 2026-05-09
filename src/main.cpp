// #include <iostream>
// #include <vector>

// #include "DatabaseManager.h"
// #include "Student.h"
// #include "Teacher.h"
// #include "Course.h"

// #include "CoreCourse.h"
// #include "ElectiveCourse.h"
// #include "LabCourse.h"

// using namespace std;

// int main() {

//    DatabaseManager::saveStudent(new RegularStudent("S1","Saad","saad@gmail.com",3.5));
// DatabaseManager::saveStudent(new ScholarshipStudent("S2","Ali","ali@gmail.com",2.8));
// DatabaseManager::saveStudent(new ExchangeStudent("S3","John","john@gmail.com"));
// DatabaseManager::saveTeacher(new Teacher("T1","Ahmed","ahmed@gmail.com"));
// DatabaseManager::saveTeacher(new Teacher("T2","Usman","usman@gmail.com"));
// DatabaseManager::saveCourse(new CoreCourse("C1","OOP","T1"));
// DatabaseManager::saveCourse(new ElectiveCourse("C2","AI","T2"));
// DatabaseManager::saveCourse(new LabCourse("C3","PF Lab","T1"));
// cout << "===== LOADING STUDENTS =====\n";
//     vector<Student*> students = DatabaseManager::loadStudents();

//     for(int i = 0; i < students.size(); i++) {
//         students[i]->displayProfile();
//         cout << endl;
//     }

//     cout << "===== LOADING TEACHERS =====\n";
//     vector<Teacher*> teachers = DatabaseManager::loadTeachers();

//     for(int i = 0; i < teachers.size(); i++) {
//         teachers[i]->displayProfile();
//         cout << endl;
//     }

//     cout << "===== LOADING COURSES =====\n";
//     vector<Course*> courses = DatabaseManager::loadCourses();

//     for(int i = 0; i < courses.size(); i++) {
//         courses[i]->displayCourse();

//         cout << "Type: " << courses[i]->getType() << endl;
//         cout << "Students Enrolled: " << courses[i]->getStudentCount() << endl;

//         cout << endl;
//     }

//     cout << "===== TEST ENROLLMENT =====\n";
//     if(!students.empty() && !courses.empty()) {
//         courses[0]->enrollStudent(students[0]);
//         courses[0]->enrollStudent(students[0]); // duplicate test

//         cout << "After enrolling:\n";
//         courses[0]->displayCourse();
//         cout << "Students Enrolled: "
//              << courses[0]->getStudentCount() << endl;
//     }

//     cout << "===== TEST COMPLETE =====\n";


//     return 0;
// }

#include "../include/DatabaseManager.h"

#include "../include/CoreCourse.h"
#include "../include/ElectiveCourse.h"
#include "../include/LabCourse.h"

#include "../include/Quiz.h"
#include "../include/Assignment.h"
#include "../include/Exams.h"

#include <iostream>
using namespace std;

int main() {

    // =====================================
    // CREATE COURSES
    // =====================================

    CoreCourse c1("C1", "OOP", "T1");

    ElectiveCourse c2("C2", "AI", "T2");

    LabCourse c3("C3", "PF Lab", "T3");



    // =====================================
    // SAVE WEIGHTAGES
    // =====================================



    cout << "\n===== WEIGHTAGES SAVED =====\n";



    // =====================================
    // LOAD WEIGHTAGES
    // =====================================

    c1.loadWeightages();

    c2.loadWeightages();

    c3.loadWeightages();



    // =====================================
    // DISPLAY LOADED WEIGHTAGES
    // =====================================

    cout << "\n===== LOADED WEIGHTAGES =====\n";



    cout << "\nCore Course:\n";

    cout << "Exam: "
         << c1.getExamWeightage()
         << endl;

    cout << "Assignments: "
         << c1.getAssignmentWeightage()
         << endl;

    cout << "Quizzes: "
         << c1.getQuizWeightage()
         << endl;



    cout << "\nElective Course:\n";

    cout << "Exam: "
         << c2.getExamWeightage()
         << endl;

    cout << "Assignments: "
         << c2.getAssignmentWeightage()
         << endl;

    cout << "Quizzes: "
         << c2.getQuizWeightage()
         << endl;



    cout << "\nLab Course:\n";

    cout << "Exam: "
         << c3.getExamWeightage()
         << endl;

    cout << "Assignments: "
         << c3.getAssignmentWeightage()
         << endl;

    cout << "Quizzes: "
         << c3.getQuizWeightage()
         << endl;



    // =====================================
    // CREATE ASSESSMENTS
    // =====================================

    Quiz* q1 = new Quiz("Q1", 8, 10);

    Quiz* q2 = new Quiz("Q2", 7, 10);

    Quiz* q3 = new Quiz("Q3", 9, 10);



    Assignment* a1 =
        new Assignment("A1", 18, 20);

    Assignment* a2 =
        new Assignment("A2", 16, 20);



    Exam* e1 =
        new Exam("E1", 85, 100);



    // =====================================
    // ADD TO COURSE
    // =====================================

    c1.addQuiz(q1);

    c1.addQuiz(q2);

    c1.addQuiz(q3);

    c1.addAssignment(a1);

    c1.addAssignment(a2);

    c1.addExam(e1);



    // =====================================
    // DISPLAY REDISTRIBUTED WEIGHTS
    // =====================================

    cout << "\n===== REDISTRIBUTED WEIGHTS =====\n";



    cout << "\nQuiz Weights:\n";

    cout << q1->getWeightage() << endl;

    cout << q2->getWeightage() << endl;

    cout << q3->getWeightage() << endl;



    cout << "\nAssignment Weights:\n";

    cout << a1->getWeightage() << endl;

    cout << a2->getWeightage() << endl;



    cout << "\nFinal Exam Weight:\n";

    cout << e1->getWeightage() << endl;



    // =====================================
    // FINAL GRADE
    // =====================================

    cout << "\n===== FINAL GRADE =====\n";

    cout << c1.calculateFinalGrade()
         << endl;



    return 0;
}