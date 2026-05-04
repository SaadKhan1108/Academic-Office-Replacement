#pragma once
#include "AcademicEntity.h"

class Student : public AcademicEntity {
protected:
    float GPA;

public:
    Student(string id="", string n="", string e="", float g=0)
        : AcademicEntity(id, n, e), GPA(g) {}

    virtual float calculateGPA() = 0;
};