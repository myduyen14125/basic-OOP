#include <string>
using namespace std;
#ifndef STUDENT_H
#define STUDENT_H

class Student {
    private:
        string name;
        float math;
        float literature;
        static int count; // Đếm coi có mấy đối tượng học sinh đc tạo ra á 
    public: 
        Student() { 
            name = "Nguyen Tran My Duyen";
            math = 0.0;
            literature = 0.0;
        } //Constructor default 
        Student(string); //Constructor 1 tham so name
        Student(string, float, float); //constructor full info
        Student(const Student &); //Tham chieu, sao chep tu so phuc khac

        void setStudent(); //Nhap HS
        void display(); //Xuat
        
        void setName(string); 
        void setMath(float); 
        void setLiterature(float);
        string getName(); 
        float getMath(); 
        float getLiterature();

        float avg();
        void type(Student);
        ~Student();
};

#endif