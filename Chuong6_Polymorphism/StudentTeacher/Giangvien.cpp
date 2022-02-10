//TEACHER.CPP
//Dinh nghia ham thanh vien cho lop GiangVien
#include "Giangvien.h"
#include <iomanip>
using namespace std;
GiangVien::GiangVien(string HT,int SBB):Nguoi(HT)
{
	SoBaiBao=SBB;
}

bool GiangVien::DuocKhenThuong() const
{
	return SoBaiBao>=3;
}
void GiangVien::Xuat() const
{
	cout<<setw(15)<<"Giang vien: ";
	Nguoi::Xuat();
	cout<<setw(15)<<"So bai bao:"<<setw(5)<<SoBaiBao<<endl;
}
