#ifndef TGD_H
#define TGD_H

#include "hinh2d.h"

class TGD : public Hinh2D
{
	public:
		TGD(double aa=1):Hinh2D(aa){
		}
		double Chuvi()const;
	    double Dientich() const;
   	    void Display() const;

};

#endif
