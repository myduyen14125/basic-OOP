#include <iostream>
#include <string>
#include "Inherit.h"
#include "Inherit.cpp"
using namespace std;

int main()
{
    int numberOfStudent, numberOfTeacher;
    cout << "Nhap vao so luong sinh vien: ";
    cin >> numberOfStudent;
    student *sv;
    sv = new student[numberOfStudent];
    if (numberOfStudent != 0)
    {
        cout << "Nhap vao thong tin sinh vien:" << endl;
        cout << "--------------" << endl;
        for (int i = 0; i < numberOfStudent; i++)
            cin >> sv[i];
    }
    //-------
    cout << "Nhap vao so luong giang vien: ";
    cin >> numberOfTeacher;
    teacher *gv;
    gv = new teacher[numberOfStudent];
    if (numberOfTeacher != 0)
    {
        cout << "Nhap vao thong tin giang vien:" << endl;
        cout << "--------------" << endl;
        for (int i = 0; i < numberOfTeacher; i++)
            cin >> gv[i];
    }
    //-----------
    cout << "Danh sach nhung nguoi duoc khen thuong:" << endl;
    for (int i = 0; i < numberOfStudent; i++)
        sv[i].setStudent();
    for (int i = 0; i < numberOfTeacher; i++)
        gv[i].setTeacher();

    return 0;
}