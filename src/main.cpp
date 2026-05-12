#include <iostream>
#include <vector>
#include <string>
#include "DatabaseManager.h"
#include "Scheduler.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "Venue.h"
#include "Section.h"

using namespace std;

// Robust choice validator to prevent infinite loops from string inputs
bool getChoice(int& choice) {
    string input;
    cin >> input;
    for (int i = 0; i < (int)input.length(); i++) {
        if (!isdigit(input[i])) return false;
    }
    choice = stoi(input);
    return true;
}

int main() {
    cout << "Booting Academic Office System...\n";

    // 1. DATA LOADING: Populates all memory vectors
    vector<Student*> allStudents = DatabaseManager::loadStudents();
    vector<Teacher*> allTeachers = DatabaseManager::loadTeachers();
    vector<Course*> allCourses = DatabaseManager::loadCourses();
    vector<Venue*> allVenues = DatabaseManager::loadVenues();
    vector<Section*> allSections = DatabaseManager::loadSections();

    // Link grades and enrollments to existing objects
    DatabaseManager::loadAssessments(allCourses, allSections);
    DatabaseManager::loadEnrollments(allStudents, allCourses);

    Scheduler scheduler(allVenues, allSections);
    int choice;

    while (true) {
        cout << "\n=== MAIN PORTAL ===\n1. Student\n2. Teacher\n3. Admin\n0. Save & Exit\nChoice: ";
        if (!getChoice(choice)) {
            cout << "Invalid input. Numbers only.\n";
            continue;
        }

        if (choice == 0) break;

        // --- STUDENT PORTAL ---
        if (choice == 1) {
            string sID;
            cout << "Enter Student ID: "; cin >> sID;
            Student* user = nullptr;
            for (int i = 0; i < (int)allStudents.size(); i++) {
                if (allStudents[i]->getID() == sID) user = allStudents[i];
            }

            if (!user) { cout << "Student ID not found.\n"; continue; }

            int sChoice;
            cout << "\n1. View Profile & GPA\n2. Register Course\n0. Logout\nChoice: ";
            if (getChoice(sChoice)) {
                if (sChoice == 1) {
                    user->calculateGPA(); // Updates math before display
                    user->displayProfile();
                } else if (sChoice == 2) {
                    string cID; cout << "Enter Course ID: "; cin >> cID;
                    for (int i = 0; i < (int)allCourses.size(); i++) {
                        if (allCourses[i]->getCourseID() == cID) {
                            allCourses[i]->enrollStudent(user, "8AM", allSections, allCourses);
                        }
                    }
                }
            }
        }

        // --- TEACHER PORTAL ---
        else if (choice == 2) {
            string tID;
            cout << "Enter Teacher ID: "; cin >> tID;
            Teacher* prof = nullptr;
            for (int i = 0; i < (int)allTeachers.size(); i++) {
                if (allTeachers[i]->getID() == tID) prof = allTeachers[i];
            }

            if (!prof) { cout << "Teacher ID not found.\n"; continue; }

            int tChoice;
            cout << "\n1. View Profile\n2. Grade Student\n0. Logout\nChoice: ";
            if (getChoice(tChoice)) {
                if (tChoice == 1) prof->displayProfile();
                else if (tChoice == 2) {
                    string cID, stuID, type; float raw, max;
                    cout << "Course ID: "; cin >> cID;
                    cout << "Student ID: "; cin >> stuID;
                    cout << "Type (Quiz/Assignment/Exam): "; cin >> type;
                    cout << "Max Marks: "; cin >> max;
                    cout << "Obtained: "; cin >> raw;

                    for (int i = 0; i < (int)allCourses.size(); i++) {
                        // Security check: Only assigned teacher can grade
                        if (allCourses[i]->getCourseID() == cID && allCourses[i]->getTeacherID() == tID) {
                            allCourses[i]->inputAssessmentMarks(stuID, "A_ID", type, raw, max);
                        }
                    }
                }
            }
        }

        // --- ADMIN PORTAL ---
        else if (choice == 3) {
            int aChoice;
            cout << "\n1. View Roster\n2. Schedule Exam\n3. View Master Schedule\n0. Logout\nChoice: ";
            if (getChoice(aChoice)) {
                if (aChoice == 1) {
                    for (int i = 0; i < (int)allStudents.size(); i++) {
                        allStudents[i]->calculateGPA();
                        allStudents[i]->displayProfile();
                    }
                } else if (aChoice == 2) {
                    string secID, vID;
                    cout << "Section ID: "; cin >> secID;
                    cout << "Venue ID: "; cin >> vID;
                    Section* sObj = nullptr; Venue* vObj = nullptr;
                    for (int i = 0; i < (int)allSections.size(); i++) if (allSections[i]->getSectionID() == secID) sObj = allSections[i];
                    for (int i = 0; i < (int)allVenues.size(); i++) if (allVenues[i]->getID() == vID) vObj = allVenues[i];
                    
                    if (sObj && vObj) {
                        scheduler.sectionAssignment(sObj, vObj, 30, allCourses);
                    } else cout << "Error: Invalid Section or Venue ID.\n";
                } else if (aChoice == 3) {
                    scheduler.displaySchedule();
                }
            }
        }
    }

    // 2. SAVE & EXIT: Writes everything back to file
    DatabaseManager::saveAllStudents(allStudents);
    DatabaseManager::saveAllTeachers(allTeachers);
    DatabaseManager::saveAllCourses(allCourses);
    DatabaseManager::saveAllSections(allSections);
    DatabaseManager::saveAllVenues(allVenues);

    // Freeing memory
    for (int i = 0; i < (int)allStudents.size(); i++) delete allStudents[i];
    for (int i = 0; i < (int)allTeachers.size(); i++) delete allTeachers[i];
    for (int i = 0; i < (int)allCourses.size(); i++) delete allCourses[i];
    for (int i = 0; i < (int)allVenues.size(); i++) delete allVenues[i];
    for (int i = 0; i < (int)allSections.size(); i++) delete allSections[i];

    cout << "\nDatabases updated. Goodbye!\n";
    return 0;
}