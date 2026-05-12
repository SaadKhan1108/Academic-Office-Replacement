#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include "DatabaseManager.h"
#include "Scheduler.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "Venue.h"
#include "Section.h"



bool isNumericChoice(string input, int& choice) {
    if(input.empty()) {
        return false;
    }
    for(int i = 0; i < input.length(); i++) {
        if(!isdigit(input[i])) {
            return false;
        }
    }
    choice = stoi(input);
    return true;
}

int main() {
    cout << "Booting up Academic Office System...\n";

    vector<Student*> allStudents = DatabaseManager::loadStudents();
    vector<Teacher*> allTeachers = DatabaseManager::loadTeachers();
    vector<Course*> allCourses = DatabaseManager::loadCourses();
    vector<Venue*> allVenues = DatabaseManager::loadVenues();
    vector<Section*> allSections = DatabaseManager::loadSections();

    DatabaseManager::loadAssessments(allCourses, allSections);
    DatabaseManager::loadEnrollments(allStudents, allCourses);

    Scheduler scheduler(allVenues, allSections);

    bool running = true;
    string choiceStr;
    int choice;

    while (running==true) {
       
        cout << "      ACADEMIC OFFICE PORTAL\n";
        cout << "1. Student Portal\n";
        cout << "2. Teacher Portal\n";
        cout << "3. Admin Portal\n";
        cout << "0. Save & Exit System\n";
        cout << "Enter choice: ";
        cin >> choiceStr;

        if (!isNumericChoice(choiceStr, choice)) {
            cout << "Invalid input. Please enter a number from the menu.\n";
            continue;
        }
            if (choice == 1) {
            cout << "\n Entering Student Portal \n";
        }else if (choice == 2) {
            cout << "\n Entering Teacher Portal \n";
        }else if (choice == 3) {
            cout << "\n Entering Admin Portal \n";
        } else if (choice == 0) {
            cout << "\nSaving databases to prevent data loss. Please wait...\n";
            cout << "System safely shut down. Goodbye!\n";
            running = false;
        } else {
            cout << "Invalid choice. Please select 0,1,2,or3.\n";
        }
    }

    DatabaseManager::saveAllStudents(allStudents);
    DatabaseManager::saveAllTeachers(allTeachers);
    DatabaseManager::saveAllCourses(allCourses);
    DatabaseManager::saveAllVenues(allVenues);
    DatabaseManager::saveAllSections(allSections);

    for(int i = 0; i < allStudents.size(); i++) {
        delete allStudents[i];
    }
    for(int i = 0; i < allTeachers.size(); i++) {
        delete allTeachers[i];
    }
    for(int i = 0; i < allCourses.size(); i++) {
        delete allCourses[i];
    }
    for(int i = 0; i < allVenues.size(); i++) {
        delete allVenues[i];
    }
    for(int i = 0; i < allSections.size(); i++) {
        delete allSections[i];
    }

    
    return 0;
}