#pragma once
#include <fstream>
#include "Student.h"
#include "RegularStudent.h"
#include "ExchangeStudent.h"
#include "ScholarshipStudent.h"
#include "Teacher.h"
#include <vector>

class DatabaseManager {
public:
    static void saveStudent(Student* s);
    static vector<Student*> loadStudents();
    static void saveTeacher(Teacher *t);
    static vector<Teacher*> loadTeachers();
};