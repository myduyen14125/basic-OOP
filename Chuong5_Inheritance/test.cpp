#include <iostream>
#include <string>
using namespace std;
#ifndef STUDENT_H
#define STUDENT_H

class A {
    private: 
        int x,y;
    public: 
        void setX(); 
        void setY();
};
class B:A {
    private: int z;
    public: 
        void setZ();
};

#endif

int main() {

}