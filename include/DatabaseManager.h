#pragma once
#include <fstream>
#include "Student.h"
#include "RegularStudent.h"
#include "ExchangeStudent.h"
#include "ScholarshipStudent.h"
#include "Teacher.h"
#include "Course.h"
#include "Venue.h"
#include "Section.h"
#include <vector>

class DatabaseManager {
public:
    static void saveAllStudents(const vector<Student*>& allStudents);
    static vector<Student*> loadStudents();
   static void saveAllTeachers(const vector<Teacher*>& allTeachers);
    static vector<Teacher*> loadTeachers();
  static void saveAllCourses(const vector<Course*>& allCourses);
    static vector<Course*> loadCourses();
    static void saveWeightages(Course* c);
    static vector<Venue*> loadVenues();
static void saveAllVenues(const vector<Venue*>& allVenues);
    static void saveAllSections(const vector<Section*>& allSections);
    static vector<Section*> loadSections();
    static void saveAssessment(string courseID, string studentID, string type, float raw, float max);
     static void loadAssessments(vector<Course*>& allCourses, const vector<Section*>& allSections);
  
   static void saveEnrollment(string studentID, string courseID);
   static void loadEnrollments(vector<Student*>& allStudents, vector<Course*>& allCourses);
};