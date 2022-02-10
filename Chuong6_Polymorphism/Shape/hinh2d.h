#ifndef HINH2D_H
#define HINH2D_H

#include "hinh.h"

class Hinh2D : public Hinh
{
	public:
		Hinh2D(double aa=1):Hinh(aa){
		}
		virtual double Chuvi() const =0;
	    void Display() const; //overding
};

#endif
