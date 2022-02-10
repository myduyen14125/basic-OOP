#ifndef TRON_H
#define TRON_H

#include "hinh2d.h"

class Tron : public Hinh2D
{
	public:
		Tron(double aa=1):Hinh2D(aa){
		}
	   double Chuvi()const;
	   double Dientich() const;
	   void Display() const;

};

#endif
