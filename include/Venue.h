#pragma once
#include "iostream"
using namespace std;
class Venue {
protected:
    string roomID;
    int capacity;
    bool hasComputers;

public:
    Venue(string id, int cap, bool comp);

    string getID();
    int getCapacity();
    bool getComputers();
};