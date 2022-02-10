#include <iostream>
#include <string>
using namespace std;
#ifndef HEADER_H
#define HEADER_H
class people
{
public:
    string hoTen;
    string thongTin; // với sv là lớp, với gv là bộ môn
    int soLuong; // với sv sẽ là điểm, với gv là số bài báo
};
class student : protected people
{
    friend istream &operator>>(istream &in, student &x);

public:
    void setStudent();
};
class teacher : protected people
{
    friend istream &operator>>(istream &in, teacher &x);

public:
    void setTeacher();
};

#endif