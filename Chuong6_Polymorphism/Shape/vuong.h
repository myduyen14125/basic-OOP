#ifndef VUONG_H
#define VUONG_H

#include "hinh2d.h"

class Vuong : public Hinh2D
{
	public:
		Vuong(double aa=1):Hinh2D(aa){
		}
		double Chuvi()const;
	    double Dientich() const;
	    void Display() const;	    
};

#endif
