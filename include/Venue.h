#pragma once
#include "iostream"
using namespace std;
class Venue {
protected:
    string roomID;
    int capacity;
    bool hasComputers;

public:
    Venue(string id, int cap, bool comp){
        roomID = id;
    capacity = cap;
    hasComputers = comp;
    }

    string getID(){
        return roomID;
    }
    int getCapacity(){
        return capacity;
    }
    bool getComputers(){
        return hasComputers;
    }
    void displayVenue(){
        cout << "Room: " << roomID << endl;
    cout << "Capacity: " << capacity << endl;
    cout<<"Computers: ";
    if(hasComputers==1){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
    }
};