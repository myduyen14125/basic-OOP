#include "cau.h"
#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;
double Cau::Thetich()const{
	return 4*M_PI*a*a*a/3;
}
double Cau::Dientich() const{
	return 4*M_PI*a*a;
}
void Cau::Display() const{
	cout<<setw(25)<<"Hinh cau bk ";
	Hinh3D::Display();
}
