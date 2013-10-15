#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <iostream>
#include <cstring>

using namespace std;

class Student {
    private:
        char* firstName;
        char* lastName;
        int fn;
        double grade;
    public:
        Student(const char* = "", const char* = "", int = 0, double = 2);
        ~Student();
        void setFirstName(const char* value);
        void setLastName(const char* value);
        void setFN(const int value);
        void setGrade(const double value);
        char* getFirstName() const;
        char* getLastName() const;
        int getFN() const;
        double getGrade() const;

        friend ostream& operator<<(ostream&, const Student&);
        friend istream& operator>>(istream&, Student&);
};

#endif // STUDENT_H_INCLUDED
