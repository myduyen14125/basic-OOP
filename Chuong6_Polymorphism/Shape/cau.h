#ifndef CAU_H
#define CAU_H

#include "hinh3d.h"

class Cau : public Hinh3D
{
	public:
		Cau(double aa=1):Hinh3D(aa){
		}
		double Thetich()const;
	    double Dientich() const;
	    void Display() const;	    
};

#endif
