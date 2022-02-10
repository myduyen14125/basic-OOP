#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H
#include "Student.h" 

class List {
    private: 
        const int size; //So hoc sinh trong danh sach - thanh vien du lieu tinh de dem 
        Student *data; //Mang dong voi kieu du lieu Student. 
    public: 
        List(int n = 5); //default constructor 
        List(const List &l); //copy constructor 
        ~List() {delete[] data;};
        void Input();
        void Output() const; //Ham truy xuat, gia tri khong thay doi
};

#endif