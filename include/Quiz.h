#pragma once
#include "Assessments.h"

class Quiz : public Assessment {
public:
    Quiz(string id, float r, float m):Assessment(id, "Quiz", r, m) {}
};