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
    static void saveStudent(Student* s);
    static vector<Student*> loadStudents();
    static void saveTeacher(Teacher *t);
    static vector<Teacher*> loadTeachers();
    static void saveCourse(Course*s);
    static vector<Course*> loadCourses();
    static void saveWeightages(Course* c);
    static vector<Venue*> loadVenues();
    static void saveVenue(Venue*v);
    static void saveSection(Section* s);
    static vector<Section*> loadSections();
    static void saveAssessment(string sectionID, string type, float raw, float max);
    void DatabaseManager::loadAssessments(vector<Course*>& allCourses, const vector<Section*>& allSections);
  
   static void saveEnrollment(string studentID, string courseID);
   static void loadEnrollments(vector<Student*>& allStudents, vector<Course*>& allCourses);
};