#include <iostream>
#include "hinh.h"
#include "hinh2d.h"
#include "hinh3d.h"
#include "tron.h"
#include "tgd.h"
#include "vuong.h"
#include "cau.h"
#include "lp.h"
#include "hinh.cpp"
#include "hinh2d.cpp"
#include "hinh3d.cpp"
#include "tron.cpp"
#include "tgd.cpp"
#include "vuong.cpp"
#include "cau.cpp"
#include "lp.cpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(void) {
	// Hinh3D x;
	// Hinh2D y;
	// Hinh z;
	Hinh *DS[100];
	int n=0,a;
	char chon;
	do {
		cout<<"Nhập độ dài a:"; cin>>a;
		cout<<"Bạn muốn nhập hình gì?(C,T,D,V,L)";cin>>chon;
		chon=toupper(chon);
		switch (chon){
			case 'C':DS[n++]= new Cau(a);break;
			case 'T':DS[n++]= new Tron(a); break;
			case 'D':DS[n++]= new TGD(a); break;
			case 'V':DS[n++]= new Vuong(a);break;
			case 'L':DS[n++]= new LP(a);
		}
		cout<<"Nhap nua ko?(C/K)"; cin>>chon;
		chon = toupper(chon);
		if (n==100||chon=='K')
			break;
	}while (1);
	cout<<"Chu vi, Dien tich, The tich cua cac hinh:"<<endl;
	for (int i=0; i<n;i++)
		DS[i]->Display();	
	return 0;
}
