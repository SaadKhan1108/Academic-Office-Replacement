#include <iostream>
#include "Course.h"
using namespace std;
#include "Section.h"
#include "Venue.h"


class Scheduler{
    vector<Venue*> venues;
    vector <Section*> sections;
    public:
    Scheduler(vector<Venue*> v,vector <Section*> s){
        venues=v;
        sections=s;
    }
    bool isConflict(string venueID,string timeSlot);
    void displaySchedule();
    bool checkCapacity(Venue*v,int numstudents);
    bool sectionAssignment(Section*s,Venue* v,int numStudents,const vector<Course*>& allCourses);
    string suggestNextSlot(string currentSlot,string venueID);
};