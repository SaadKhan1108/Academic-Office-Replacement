#pragma once
#include "iostream"
#include "Venue.h"
using namespace std;
#include <vector>
class Section {
    string sectionID;
    string courseID;
    string teacherID;
    vector<string> venueIDs;
    string timeSlot;

public:
    void assignVenue(string v);
};