
//PERSON.H
//Dinh nghia lop Nguoi
#ifndef Nguoi_h
#define Nguoi_h
#include <iostream>
#include <string.h>
using namespace std;
class Nguoi
{
	protected:
		string HoTen;
	public:
 		Nguoi(string HT);
		virtual bool DuocKhenThuong() const;//phuong thuc thuan ao
		virtual void Xuat() const;
};
#endif
