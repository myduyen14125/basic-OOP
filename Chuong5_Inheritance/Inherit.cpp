#include <iostream>
#include <string>
#include "Inherit.h"
using namespace std;

istream &operator>>(istream &in, student &x)
{   
    cout << "\tNhap ho va ten: ";
    cin.ignore();
    getline(cin, x.hoTen);
    cout << "\tNhap vao ten lop: ";
    getline(cin, x.thongTin);
    cout << "\tNhap vao diem trung binh: ";
    in >> x.soLuong;
    cout << "--------------" << endl;
    return in;
}
void student::setStudent()
{
    if (soLuong >= 8)
        cout << hoTen << endl;
}
istream &operator>>(istream &in, teacher &x)
{
    cout << "\tNhap ho va ten: ";
    cin.ignore();
    getline(cin, x.hoTen);
    cout << "\tNhap vao ten bo mon: ";
    getline(cin, x.thongTin);
    cout << "\tNhap vao so luong bai bao: ";
    in >> x.soLuong;
    cout << "--------------" << endl;
    return in;
}
void teacher::setTeacher()
{
    if (soLuong >= 3)
        cout << hoTen << endl;
}