#pragma once
#include "Assessments.h"

class Assignment : public Assessment {
public:
    Assignment(string id,float r,float m) : Assessment(id,"Assignment",r,m) {}
};