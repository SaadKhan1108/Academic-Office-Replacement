#pragma once
#include <fstream>
#include "Student.h"

class DatabaseManager {
public:
    static void saveStudent(Student* s);
};