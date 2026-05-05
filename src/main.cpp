#include <iostream>
#include "RegularStudent.h"
#include "ScholarshipStudent.h"
#include "ExchangeStudent.h"
#include "DatabaseManager.h"
#include <vector>

using namespace std;

int main() {
  vector<Student*> students=DatabaseManager::loadStudents();//make vector to store diff obj of students' child classes
//   students.push_back(new RegularStudent("S1","Saad","email",3.5)); //pushback adds obj to end of vector
//   students.push_back(new ScholarshipStudent("S2","Ali","email",2.0,3.0));
//   students.push_back(new ExchangeStudent("S3","John","email"));

  for(int i=0;i<students.size();i++){
   // DatabaseManager::saveStudent(students[i]);
      cout<<students[i]->getGPA()<<endl;
  }
     
    // Student* s1 = new RegularStudent("S1","Saad","email",3.5);
    // Student* s2 = new ScholarshipStudent("S2","Ali","email",2.0,3.0);
    // Student* s3 = new ExchangeStudent("S3","John","email");

    // s1->displayProfile();
    // s2->displayProfile();
    // s3->displayProfile();

    return 0;
}