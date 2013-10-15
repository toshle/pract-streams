#include <iostream>

#include "student.h"

#include <fstream>

using namespace std;


int main() {
    Student rosko("Rosen", "Rachev", 80851, 6);
    Student pesho("Peter", "Denev", 70751, 3);
    Student random;

    ifstream ifile("istudents.txt");
    ofstream ofile("ostudents.txt");
    while(!ifile.eof()) {
            if(ifile.good() && ofile.good()) {
                ifile>>random;
                ofile<<random;
            }
    }
    ifile.close();
    ofile.close();
    return 0;
}

int main2() {

    ifstream img("image.jpg", ios::binary | ios::ate);
    ofstream copy("image-copy.jpg", ios::binary);
    int length = img.tellg();
    char* data = new char[length];
    img.seekg(0, ios::beg);
    img.read(data, length);
    copy.write(data, length);
    img.close();
    copy.close();

    return 0;
}
