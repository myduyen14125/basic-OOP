#include "Hocsinh.h"
#include <iostream>
#include <iomanip>
using namespace std;
int Hocsinh::count = 0;//định nghĩa thành viên tĩnh 
Hocsinh::Hocsinh(string ten, double t, double v):
    ht(ten), toan(t),van(v){ 
        count++;
    }
Hocsinh::Hocsinh(const Hocsinh &x){
    ht = x.ht;
    toan = x.toan;
    van = x.van;
    dtb = x.dtb;
    xl = x.xl;
    count++;
}
void Hocsinh::Nhap(){
    cout<<"Nhap ho ten hoc sinh:";
    cin>>ht;
    cout<<"Nhap diem mon toan:"; 
    cin>>toan;
    cout<<"Nhap diem mon van:"; 
    cin>>van;
    dtb = (toan + van)/2;
    xl = (dtb<5)?"Yeu":(dtb<6.5)?"Trung binh":(dtb<8)?"Kha":"Gioi";
}
istream &operator>>(istream &in, Hocsinh &hs){
    cout<<"Nhap ho ten hoc sinh:";
    in>>hs.ht;
    cout<<"Nhap diem mon toan:"; 
    in>>hs.toan;
    cout<<"Nhap diem mon van:"; 
    in>>hs.van;
    hs.dtb = (hs.toan + hs.van)/2;
    hs.xl = (hs.dtb<5)?"Yeu":(hs.dtb<6.5)?"Trung binh":(hs.dtb<8)?"Kha":"Gioi";
    return in;
}
void Hocsinh::Xuat() const{
    cout<<setw(20)<<ht<<setw(8)<<toan<<setw(8)<<van<<setw(8)<<dtb<<setw(15)<<xl<<endl;
}
ostream &operator<<(ostream &out, Hocsinh &hs){
    out<<setw(20)<<hs.ht<<setw(8)<<hs.toan<<setw(8)<<hs.van<<setw(8)<<hs.dtb<<setw(15)<<hs.xl<<endl;
    return out;
}
bool operator>(Hocsinh &hs1, Hocsinh &hs2){
    if(hs1.dtb>hs2.dtb) return true;
    return false;
}