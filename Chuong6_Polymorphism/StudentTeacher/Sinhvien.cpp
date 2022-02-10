//STUDENT.CPP
//Dinh nghia ham thanh vien cho lop SinhVien
#include "Sinhvien.h"
#include <iomanip>
using namespace std;
SinhVien::SinhVien(string HT,float DTB):Nguoi(HT)
{
	DiemTB=DTB;
}
bool SinhVien::DuocKhenThuong() const
{
	return DiemTB>=8.0;
}

void SinhVien::Xuat() const
{
	cout<<setw(15)<<"Sinh vien: ";
	Nguoi::Xuat(); 
	cout<<setw(15)<<"Diem TB:"<<setw(5)<<DiemTB<<endl;
}
