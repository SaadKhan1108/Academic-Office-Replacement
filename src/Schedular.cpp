#include "Scheduler.h"
#include "DatabaseManager.h"
#include <iostream>
using namespace std;

bool Scheduler::isConflict(string venueID,string timeSlot){
    for(int i=0;i<sections.size();i++){
                 if(sections[i]->getVenue()==venueID ||sections[i]->getTimeSlot()==timeSlot){
                    return true;
                 }
    }
    return false;
}

bool Scheduler::checkCapacity(Venue*v,int numStudents){
 if(v==nullptr){
    return false;
 }else{
    if(v->getCapacity()>=numStudents){
        return true;
    }else{
        return false;
    }
 }
}

void Scheduler::displaySchedule() {
    cout<<"EXAM SCHEDULE\n";
    for (int i = 0; i < sections.size(); i++) {

        cout << "Section: " << sections[i]->getSectionID() << endl;
        cout << "Course: "<< sections[i]->getCourseID()<< endl;
        cout << "Venue: "<< sections[i]->getVenue()<< endl;
        cout << "Time: "<< sections[i]->getTimeSlot()<< endl;
    }

}

string Scheduler::suggestNextSlot(string currentSlot){
     string slots[] = {"8AM","11AM","2PM","5PM"};//times at wich exam can take place,3 hr gap
    int size = 4;
    for (int i = 0; i < size; i++) {
     if (slots[i] == currentSlot) {
            for (int j = i + 1; j < size; j++) {
                bool conflict = false;
                for (int k = 0; k < sections.size(); k++) {

                    if (sections[k]->getTimeSlot()==slots[j]) {
                        conflict = true;
                        break;
                    }
                }
                if (conflict==false){
                    return slots[j];
                }
            }
        }
    }
    return "NO TIME SLOT AVAILABLE";
}

 bool Scheduler::sectionAssignment(Section*s,Venue* v,int numStudents){
    if(s==nullptr || v==nullptr){
        return false;
    }
    if(checkCapacity(v,numStudents)==false){
        cout<<"Not enough capacity in Room\n";
        return false;
    }
    string currentTime="8PM";
    if (isConflict(v->getID(), currentTime)==true){
         currentTime=suggestNextSlot(currentTime);
         if(currentTime=="NO TIME SLOT AVAILABLE"){
            cout<<"NO TIME SLOT AVAILABLE\n";
            return false;
         }
    }
        s->setVenue(v->getID());
        s->setTime(currentTime);
        sections.push_back(s);
         DatabaseManager::saveSection(s); //store section save it in file so slot is filled and cant be used by other section
         cout << "Section assigned successfully\n";
         return true;
}