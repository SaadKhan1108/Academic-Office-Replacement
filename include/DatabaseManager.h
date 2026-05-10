#pragma once
#include <fstream>
#include "Student.h"
#include "RegularStudent.h"
#include "ExchangeStudent.h"
#include "ScholarshipStudent.h"
#include "Teacher.h"
#include "Course.h"
#include "Venue.h"
#include <vector>

class DatabaseManager {
public:
    static void saveStudent(Student* s);
    static vector<Student*> loadStudents();
    static void saveTeacher(Teacher *t);
    static vector<Teacher*> loadTeachers();
    static void saveCourse(Course*s);
    static vector<Course*> loadCourses();
    static void saveWeightages(Course* c);
    static vector<Venue*> loadVenues();
    static void saveVenue(Venue*v);
};