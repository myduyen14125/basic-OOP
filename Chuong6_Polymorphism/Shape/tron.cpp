#include "tron.h"
#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;
double Tron::Chuvi()const{
	return 2*M_PI*a;
}
double Tron::Dientich() const{
	return M_PI*a*a;
}
void Tron::Display() const{
	cout<<setw(25)<<"Hinh tron bk ";
	Hinh2D::Display();
}

