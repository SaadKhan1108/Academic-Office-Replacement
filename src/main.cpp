
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
return 0;
}