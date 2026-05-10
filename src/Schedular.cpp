#include "Scheduler.h"
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