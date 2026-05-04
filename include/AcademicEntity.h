#pragma once
#include <iostream>
using namespace std;

class AcademicEntity {
protected:
    string ID, name, email;

public:
    AcademicEntity(string id="", string n="", string e="") {
        ID = id;
        name = n;
        email = e;
    }

    virtual void displayProfile() = 0;
};