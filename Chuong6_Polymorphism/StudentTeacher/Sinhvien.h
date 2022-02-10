//STUDENT.H
//Dinh nghia lop SinhVien
#ifndef STUDENT_H
#define STUDENT_H
#include "Nguoi.h"
#include <string.h>
using namespace std;
class SinhVien : public Nguoi
{
	protected:
		float DiemTB;
	public:
		SinhVien(string HT,float DTB);
		bool DuocKhenThuong() const;
		void Xuat() const; //overiding
};

#endif
