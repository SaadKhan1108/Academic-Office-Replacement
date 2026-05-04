#include <iostream>
#include "RegularStudent.h"
#include "ScholarshipStudent.h"
#include "ExchangeStudent.h"

using namespace std;

int main() {

    Student* s1 = new RegularStudent("S1","Saad","email",3.5);
    Student* s2 = new ScholarshipStudent("S2","Ali","email",2.0,3.0);
    Student* s3 = new ExchangeStudent("S3","John","email");

    s1->displayProfile();
    s2->displayProfile();
    s3->displayProfile();

    return 0;
}