#pragma once
#include "Assessments.h"

class Exam : public Assessment {
public:
    Exam(string id,float r,float m):Assessment(id,"Exam",r,m) {}
};