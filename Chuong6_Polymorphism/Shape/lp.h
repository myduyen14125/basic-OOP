#ifndef LP_H
#define LP_H

#include "hinh3d.h"

class LP : public Hinh3D
{
	public:
		LP(double aa=1):Hinh3D(aa){
		}
		double Thetich()const;
	    double Dientich() const;
	    void Display() const;	
};

#endif
