#include <iostream>
#include "student.h"
#include <cstring>

using namespace std;

Student::Student(const char* first, const char* last, int fn, double grade) : firstName(NULL), lastName(NULL) {
    setFirstName(first);
    setLastName(last);
    setFN(fn);
    setGrade(grade);
}

Student::~Student() {
    delete[] firstName;
    delete[] lastName;
}
void Student::setFirstName(const char* value) {
    if(firstName != NULL) {
        delete[] firstName;
    }
    firstName = new char[sizeof(value)/sizeof(char)];
    strcpy(firstName, value);
}
void Student::setLastName(const char* value) {
    if(lastName != NULL) {
        delete[] lastName;
    }
    lastName = new char[sizeof(value)/sizeof(char)];
    strcpy(lastName, value);
}
void Student::setFN(const int value) {
    fn = value;
}
void Student::setGrade(const double value) {
    grade = value;
}
char* Student::getFirstName() const {
    return firstName;
}
char* Student::getLastName() const {
    return lastName;
}
int Student::getFN() const {
    return fn;
}
double Student::getGrade() const {
    return grade;
}

ostream& operator<<(ostream& o, const Student& s) {
    o<<s.getFN()<<":"<<s.getFirstName()<<" "<<s.getLastName()<<":"<<s.getGrade()<<endl;
    return o;
}

istream& operator>>(istream& i, Student& s) {
    int fn;
    double grade;
    char nameBuffer[100];
    i>>fn;
    s.setFN(fn);
    i.get();
    i.getline(nameBuffer, 100, ' ');
    cout<<nameBuffer<<endl;
    s.setFirstName(nameBuffer);
    i.getline(nameBuffer, 100, ':');
    cout<<nameBuffer<<endl;
    s.setLastName(nameBuffer);
    i>>grade;
    if(i.peek() == 10) {
        i.get();
    }

    cout<<grade<<endl;
    s.setGrade(grade);
    cout<<i.peek()<<endl;
}
