#include "lp.h"
#include <iostream>
#include <iomanip>
using namespace std;
double LP::Thetich()const{
	return a*a*a;
}
double LP::Dientich() const{
	return 6*a*a;
}
void LP::Display() const{
	cout<<setw(25)<<"Hinh lap phuong canh ";
	Hinh3D::Display();
}
