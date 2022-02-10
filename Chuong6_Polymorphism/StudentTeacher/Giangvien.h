//TEACHER.H
//Dinh nghia lop GiangVien
#ifndef TEACHER_H
#define TEACHER_H

#include "Nguoi.h"
#include <string.h>
using namespace std;
class GiangVien : public Nguoi
{
	protected:
		int SoBaiBao;
	public:
		GiangVien(string HT,int SBB);
		 bool DuocKhenThuong() const;
		 void Xuat() const;
};
#endif
