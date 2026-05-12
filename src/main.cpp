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

bool getChoice(int& choice) {
    try {
        cin >> choice;

        if (cin.fail()) {
            throw "Invalid datatype. Enter numbers only.";
        }

        cin.ignore(1000, '\n');
    }

    catch (const char* msg) {
        cout << msg << endl;

        cin.clear();
        cin.ignore(1000, '\n');

        return false;
    }

    return true;
}

int main() {

    cout << "Booting Academic Office System...\n";

    vector<Student*> allStudents = DatabaseManager::loadStudents();
    vector<Teacher*> allTeachers = DatabaseManager::loadTeachers();
    vector<Course*> allCourses = DatabaseManager::loadCourses();
    vector<Venue*> allVenues = DatabaseManager::loadVenues();
    vector<Section*> allSections = DatabaseManager::loadSections();

    DatabaseManager::loadAssessments(allCourses, allSections);
    DatabaseManager::loadEnrollments(allStudents, allCourses);

    Scheduler scheduler(allVenues, allSections);

    int choice;

    while (true) {

        cout << "\n=== MAIN PORTAL ===\n";
        cout << "1. Student\n";
        cout << "2. Teacher\n";
        cout << "3. Admin\n";
        cout << "0. Save & Exit\n";
        cout << "Choice: ";

        if (!getChoice(choice)) {
            continue;
        }
        if (choice == 0) {
            break;
        }
        if (choice == 1) {
            string sID;
            cout << "Enter Student ID: ";
            cin >> sID;
            Student* user = nullptr;
            for (int i = 0; i < allStudents.size(); i++) {
                if (allStudents[i]->getID() == sID) {
                    user = allStudents[i];
                }
            }
            if (!user) {
                cout << "Student ID not found.\n";
                continue;
            }
            int sChoice;
            cout << "\n1. View Profile & GPA\n";
            cout << "2. Register Course\n";
            cout << "0. Logout\n";
            cout << "Choice: ";

            if (getChoice(sChoice)) {

                if (sChoice == 1) {

                    user->calculateGPA();
                    user->displayProfile();
                }

                else if (sChoice == 2) {
                    string cID;
                    cout << "Enter Course ID: ";
                    cin >> cID;

                    for (int i = 0; i < allCourses.size(); i++) {

                        if (allCourses[i]->getCourseID() == cID) {

                            allCourses[i]->enrollStudent(user,"8AM",allSections,allCourses);
                        }
                    }
                }
            }
        }
        else if (choice == 2) {
            string tID;
            cout << "Enter Teacher ID: ";
            cin >> tID;
            Teacher* prof = nullptr;

            for (int i = 0; i < allTeachers.size(); i++) {
                if (allTeachers[i]->getID() == tID) {
                    prof = allTeachers[i];
                }
            }

            if (!prof) {
                cout << "Teacher ID not found.\n";
                continue;
            }

            int tChoice;
            cout << "\n1. View Profile\n";
            cout << "2. Grade Student\n";
            cout << "0. Logout\n";
            cout << "Choice: ";
            if (getChoice(tChoice)) {
                if (tChoice == 1) {
                    prof->displayProfile();
                }
                else if (tChoice == 2) {
                    string cID, stuID, type;
                    float raw, max;
                    cout << "Course ID: ";
                    cin >> cID;
                    cout << "Student ID: ";
                    cin >> stuID;
                    cout << "Type (Quiz/Assignment/Exam): ";
                    cin >> type;
                    try {
                        cout << "Max Marks: ";
                        cin >> max;
                        if (cin.fail()) {
                            throw "Invalid datatype.";
                        }
                        cout << "Obtained: ";
                        cin >> raw;
                        if (cin.fail()) {
                            throw "Invalid datatype.";
                        }
                    }
                    catch (const char* msg) {
                        cout << msg << endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        continue;
                    }
                    for (int i = 0; i < allCourses.size(); i++) {
                        if (allCourses[i]->getCourseID() == cID &&
                            allCourses[i]->getTeacherID() == tID) {
                            allCourses[i]->inputAssessmentMarks(stuID,"A_ID",type,raw,max);
                        }
                    }
                }
            }
        }
        else if (choice == 3) {
            int aChoice;
            cout << "\n1. View all Students\n";
            cout << "2. Schedule Exam\n";
            cout << "3. View Master Schedule\n";
            cout << "0. Logout\n";
            cout << "Choice: ";
            if (getChoice(aChoice)) {
                if (aChoice == 1) {
                    for (int i = 0; i < allStudents.size(); i++) {
                        allStudents[i]->calculateGPA();
                        allStudents[i]->displayProfile();
                    }
                }
                else if (aChoice == 2) {
                    string secID, vID;
                    cout << "Section ID: ";
                    cin >> secID;
                    cout << "Venue ID: ";
                    cin >> vID;
                    Section* sObj = nullptr;
                    Venue* vObj = nullptr;
                    for (int i = 0; i < allSections.size(); i++) {
                        if (allSections[i]->getSectionID() == secID) {
                            sObj = allSections[i];
                        }
                    }
                    for (int i = 0; i < allVenues.size(); i++) {
                        if (allVenues[i]->getID() == vID) {
                            vObj = allVenues[i];
                        }
                    }

                    if (sObj && vObj) {

                        scheduler.sectionAssignment(sObj,vObj,30,allCourses);
                    }
                    else {
                       cout << "Error: Invalid IDs.\n";
                    }
                }
                else if (aChoice == 3) {
                    scheduler.displaySchedule();
                }
            }
        }
    }
    for (int i = 0; i < allStudents.size(); i++) {

        allStudents[i]->calculateGPA();
    }

    DatabaseManager::saveAllStudents(allStudents);
    DatabaseManager::saveAllTeachers(allTeachers);
    DatabaseManager::saveAllCourses(allCourses);
    DatabaseManager::saveAllSections(allSections);
    DatabaseManager::saveAllVenues(allVenues);

    for (int i = 0; i < allStudents.size(); i++) {
        delete allStudents[i];
    }

    for (int i = 0; i < allTeachers.size(); i++) {
        delete allTeachers[i];
    }

    for (int i = 0; i < allCourses.size(); i++) {
        delete allCourses[i];
    }

    for (int i = 0; i < allVenues.size(); i++) {
        delete allVenues[i];
    }

    for (int i = 0; i < allSections.size(); i++) {
        delete allSections[i];
    }

    cout << "\nDatabases updated. Goodbye!\n";

    return 0;
}