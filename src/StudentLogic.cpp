#include "RegularStudent.h"
#include "ScholarshipStudent.h"
#include "Course.h"

float RegularStudent::calculateGPA() {
    if(coursesEnrolledIn.empty()) return 0.0;
    
    float totalPoints = 0;
    for(int i = 0; i < coursesEnrolledIn.size(); i++) {
        // This line only works because Course.h is included above
        totalPoints += coursesEnrolledIn[i]->calculateFinalGrade();
    }
    float avgP = totalPoints / coursesEnrolledIn.size();  
    float gpa = (avgP / 100.0) * 4.0;
    GPA = gpa;
    return gpa;
}

float ScholarshipStudent::calculateGPA() {
    if(coursesEnrolledIn.empty()) return 0.0;
    
    float totalPoints = 0;
    for(int i = 0; i < coursesEnrolledIn.size(); i++) {
        totalPoints += coursesEnrolledIn[i]->calculateFinalGrade();
    }
    float avgP = totalPoints / coursesEnrolledIn.size();  
    float gpa = (avgP / 100.0) * 4.0;
    GPA = gpa;
    return gpa;
}