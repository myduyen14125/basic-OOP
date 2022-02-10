#include <string>
using namespace std;
#ifndef STUDENT_H
#define STUDENT_H

class Student {
    private:
        string name;
        float math;
        float literature;
        float avg;
        string type;
    public: 
        Student() { 
            name = "Nguyen Tran My Duyen";
            math = 0.0;
            literature = 0.0;
        } //Constructor default 
        Student(string); //Constructor 1 tham so name
        Student(string, float, float); //constructor full info
        Student(const Student &); //Tham chieu, sao chep tu so phuc khac
        ~Student();

        friend ostream &operator << (ostream &out, const Student &s);
        friend istream &operator >> (istream &in, Student &s);
        
        void setName(string); 
        void setMath(float); 
        void setLiterature(float);
        string getName(); 
        float getMath(); 
        float getLiterature();
        bool checkScore(const Student &s);

        bool operator > (Student &s); 
        bool operator < (Student &s); 
        bool operator == (Student &s); 
        bool operator >= (Student &s); 
        bool operator <= (Student &s); 
        bool operator != (Student &s); 
        const Student operator = (Student &s); //Phep gan ne 
};

#endif