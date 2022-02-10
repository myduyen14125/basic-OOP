#ifndef HINH3D_H
#define HINH3D_H

#include "hinh.h"

class Hinh3D : public Hinh //lớp trừu tượng
{
	public:
		Hinh3D(double aa=1):Hinh(aa){
		}
		virtual double Thetich() const = 0; //hàm thuần ảo
	    void Display() const; //overding
};

#endif
