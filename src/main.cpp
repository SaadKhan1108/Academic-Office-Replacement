
// // #include "../include/Venue.h"
// // #include "../include/Section.h"
// // #include "../include/Scheduler.h"
// // #include "../include/DatabaseManager.h"

// // #include <iostream>
// // #include <vector>
// // using namespace std;

// // int main() {

// //     // ===== CREATE & SAVE VENUES =====

// //     Venue* v1 = new Venue("A1", 60, true);
// //     Venue* v2 = new Venue("Lab2", 30, true);

// //     DatabaseManager::saveVenue(v1);
// //     DatabaseManager::saveVenue(v2);

// //     // ===== LOAD VENUES =====

// //     vector<Venue*> venues =
// //     DatabaseManager::loadVenues();

// //     cout << "\n===== LOADED VENUES =====\n";

// //     for(int i=0;i<venues.size();i++) {
// //         venues[i]->displayVenue();
// //         cout << "-------------------\n";
// //     }

// //     // ===== LOAD EXISTING SECTIONS =====

// //     vector<Section*> sections =
// //     DatabaseManager::loadSections();

// //     // ===== CREATE SCHEDULER =====

// //     Scheduler scheduler(venues, sections);

// //     // ===== CREATE SECTION =====

// //     Section* s1 =
// //     new Section("S1", "C1", "T1");

// //     // ===== ASSIGN SECTION =====

// //     //scheduler.sectionAssignment(s1, venues[0], 50);

// //     // ===== CREATE SECOND SECTION =====
// //     // same room + same default slot
// //     // should trigger conflict solver

// //     Section* s2 =
// //     new Section("S2", "C2", "T2");

// //    // scheduler.sectionAssignment(s2, venues[0], 40);

// //     // ===== DISPLAY FINAL SCHEDULE =====

// //     scheduler.displaySchedule();

// //     return 0;
// // }
// #include <iostream>
// #include <vector>
// #include <string>
// #include "../include/DatabaseManager.h"
// #include "../include/Scheduler.h"
// #include "../include/Student.h"
// #include "../include/Teacher.h"
// #include "../include/Course.h"
// #include "../include/Venue.h"
// #include "../include/Section.h"

// using namespace std;

// // Helper to find a Student by ID
// Student* findStudent(const vector<Student*>& students, string id) {
//     for (int i = 0; i < students.size(); i++) {
//         if (students[i]->getID() == id) return students[i];
//     }
//     return nullptr;
// }

// // Helper to find a Teacher by ID
// Teacher* findTeacher(const vector<Teacher*>& teachers, string id) {
//     for (int i = 0; i < teachers.size(); i++) {
//         if (teachers[i]->getID() == id) return teachers[i];
//     }
//     return nullptr;
// }

// // Helper to find a Course by ID
// Course* findCourse(const vector<Course*>& courses, string id) {
//     for (int i = 0; i < courses.size(); i++) {
//         if (courses[i]->getCourseID() == id) return courses[i];
//     }
//     return nullptr;
// }

int main() {
//     // 1. Initial Data Loading (Persistence Requirement)
//     vector<Student*> allStudents = DatabaseManager::loadStudents();
//     vector<Teacher*> allTeachers = DatabaseManager::loadTeachers();
//     vector<Course*> allCourses = DatabaseManager::loadCourses();
//     vector<Venue*> allVenues = DatabaseManager::loadVenues();
//     vector<Section*> allSections = DatabaseManager::loadSections();

//     Scheduler scheduler(allVenues, allSections);
//     int choice = -1;

//     cout << "--- FAST Academic Office Automation System ---\n";

//     while (choice != 0) {
//         cout << "\nMAIN MENU\n";
//         cout << "1. Student Portal\n";
//         cout << "2. Teacher Portal\n";
//         cout << "3. Admin (Academic Office) Portal\n";
//         cout << "0. Exit & Save\n";
//         cout << "Enter choice: ";
//         cin >> choice;

//         if (choice == 1) { // STUDENT PORTAL
//             string id;
//             cout << "Enter Student ID: ";
//             cin >> id;
//             Student* currentStu = findStudent(allStudents, id);
            
//             if (currentStu) {
//                 int sChoice;
//                 cout << "\nWelcome, " << currentStu->getName() << endl;
//                 cout << "1. Register for Course (Smart Registration)\n";
//                 cout << "2. View Profile/GPA\n";
//                 cout << "3. Give Feedback to Teacher\n";
//                 cin >> sChoice;

//                 if (sChoice == 1) {
//                     string cID;
//                     cout << "Enter Course ID: ";
//                     cin >> cID;
//                     Course* c = findCourse(allCourses, cID);
//                     if (c) {
//                         // Finding the time slot from the sections list
//                         string slot = "TBD";
//                         for(int i=0; i<allSections.size(); i++) 
//                             if(allSections[i]->getCourseID() == cID) slot = allSections[i]->getTimeSlot();
                        
//                         c->enrollStudent(currentStu, slot, allSections, allCourses);
//                     }
//                 } else if (sChoice == 2) {
//                     currentStu->displayProfile();
//                 } else if (sChoice == 3) {
//                     string tID;
//                     cout << "Enter Teacher ID: ";
//                     cin >> tID;
//                     Teacher* t = findTeacher(allTeachers, tID);
//                     if(t) t->addFeedback();
//                 }
//             } else cout << "Student ID not found.\n";

//         } else if (choice == 2) { // TEACHER PORTAL
//             string id;
//             cout << "Enter Teacher ID: ";
//             cin >> id;
//             Teacher* currentT = findTeacher(allTeachers, id);

//             if (currentT) {
//                 int tChoice;
//                 cout << "\nWelcome, " << currentT->getName() << endl;
//                 cout << "1. Input Assessment Marks (The Big Red Button)\n";
//                 cout << "2. View My Feedback Score\n";
//                 cin >> tChoice;

//                 if (tChoice == 1) {
//                     string cID, aID;
//                     float marks;
//                     cout << "Enter Course ID: "; cin >> cID;
//                     cout << "Enter Assessment ID: "; cin >> aID;
//                     cout << "Enter Raw Score: "; cin >> marks;
                    
//                     Course* c = findCourse(allCourses, cID);
//                     if(c) c->inputAssessmentMarks(aID, marks);
//                 } else if (tChoice == 2) {
//                     currentT->displayProfile();
//                 }
//             } else cout << "Teacher ID not found.\n";

//         } else if (choice == 3) { // ADMIN PORTAL
//             int aChoice;
//             cout << "\n1. Run Scheduler (Assign Venue to Section)\n";
//             cout << "2. View Full Exam Schedule\n";
//             cin >> aChoice;

//             if (aChoice == 1) {
//                 string sID, vID;
//                 int strength;
//                 cout << "Section ID: "; cin >> sID;
//                 cout << "Venue ID: "; cin >> vID;
//                 cout << "Student Strength: "; cin >> strength;

//                 Section* s = new Section(sID, "CourseID", "TeacherID"); // Simplified for demo
//                 Venue* v = nullptr;
//                 for(int i=0; i<allVenues.size(); i++) if(allVenues[i]->getID()==vID) v=allVenues[i];
                
//                 scheduler.sectionAssignment(s, v, strength, allCourses);
//             } else if (aChoice == 2) {
//                 scheduler.displaySchedule();
//             }
//         }
//     }

//     // 2. Final Data Saving (Persistence Requirement)
//     // Note: You would loop through your vectors and call DatabaseManager::saveX
//     cout << "Saving database... Goodbye!\n";
//     return 0;
}