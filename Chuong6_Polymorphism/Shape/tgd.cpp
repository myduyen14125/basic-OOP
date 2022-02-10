#include "tgd.h"
#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;
double TGD::Chuvi()const{
	return 3*a;
}
double TGD::Dientich() const{
	return sqrt(3)*a*a/4;
}
void TGD::Display() const{
	cout<<setw(25)<<"Hinh TGD canh ";
	Hinh2D::Display();
}
