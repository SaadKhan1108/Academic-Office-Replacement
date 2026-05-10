#pragma once
#include "iostream"
#include "Venue.h"
using namespace std;
#include <vector>
class Section {
    string sectionID;
    string courseID;
    string teacherID;
    string venueID;
    string timeSlot;

public:
Section(string sid, string cid, string tid){
    sectionID=sid;
    courseID=cid;
    teacherID=tid;
     venueID = "";
    timeSlot = "";
}
   void setVenue(string v) {
    venueID = v;
}
void setTime(string t){
timeSlot=t;
}
string getSectionID(){
    return sectionID;
}
string getCourseID(){
    return courseID;
}
string getTeacherID(){
    return teacherID;
}
string getVenue(){
    return venueID;
}
string getTimeSlot(){
    return timeSlot;
}
void displaySection() {
    cout << "Section ID: " << sectionID << endl;
    cout << "Course ID: " << courseID << endl;
    cout << "Teacher ID: " << teacherID << endl;
    cout << "Venue ID: " << venueID << endl;
    cout << "Time Slot: " << timeSlot << endl;
}
};