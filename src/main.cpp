// 
#include "LabCourse.h"
#include "DatabaseManager.h"

using namespace std;

int main() {

    LabCourse c1("C1", "OOP", "T1");

    c1.setOverallWeightage();
    DatabaseManager::saveWeightages(&c1);

    cout << "\n===== SAVED WEIGHTAGES =====\n";

    cout << "Exam: "
         << c1.getExamWeightage()
         << endl;

    cout << "Assignments: "
         << c1.getAssignmentWeightage()
         << endl;

    cout << "Quizzes: "
         << c1.getQuizWeightage()
         << endl;

    return 0;
}