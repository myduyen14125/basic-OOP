//PERSON.CPP
//Dinh nghia ham thanh vien cho lop Nguoi
#include <iostream>
#include <iomanip>
#include "Nguoi.h"
using namespace std;
Nguoi::Nguoi(string HT)
{
     HoTen = HT;
}
void Nguoi::Xuat() const{
     cout<<setw(15)<<"Ho va ten: "<<setw(15)<<HoTen;
}
bool Nguoi::DuocKhenThuong() const {
     return false;
}



