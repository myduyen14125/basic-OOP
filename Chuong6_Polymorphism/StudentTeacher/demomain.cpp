#include <iostream>
#include <string.h>
#include <iomanip>
#include "Nguoi.h" 
#include "Sinhvien.h"
#include "Giangvien.h"
using namespace std;
int main()
{
	Nguoi *Ng[100];
	int N=0;
	char Chon,Loai;
	string HoTen;
	do
	{
		cout<<"Ho va ten:";
		cin>>HoTen;
		cout<<"Sinh vien hay Giang vien(S/G)? ";
		cin>>Loai;
		Loai=toupper(Loai);
		if (Loai=='S')
		{
			float DTB;
			cout<<"Diem trung binh:";
			cin>>DTB;
			Ng[N++]=new SinhVien(HoTen,DTB);
		}
		else
		{
			int SoBaiBao;
			cout<<"So bai bao:";
			cin>>SoBaiBao;
			Ng[N++]=new GiangVien(HoTen,SoBaiBao);
		}
		cout<<"Tiep tuc (C/K)? ";
		cin>>Chon;
		Chon=toupper(Chon);
		if ((N==100)||(Chon=='K'))
			break;
	}
	while (1);
	cout<<"Danh sach duoc khen thuong:"<<endl;
	for(int I=0;I<N;++I)
	if (Ng[I]->DuocKhenThuong())
			Ng[I]->Xuat();
	cout<<endl;
	return 1;
}
