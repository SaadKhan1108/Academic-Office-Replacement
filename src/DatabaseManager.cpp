#include "../include/DatabaseManager.h"
#include <fstream>
void DatabaseManager::saveStudent(Student* s) {
    ofstream file("data/students.txt",ios_base::app);//append mode to save prev data
    file << s->getID()<<" | "<<s->getName()<<" | "<<s->getType()<<" | "<<s->getGPA()<<endl;
}