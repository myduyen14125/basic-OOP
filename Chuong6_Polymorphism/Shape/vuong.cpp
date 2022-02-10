#include "vuong.h"
#include <iostream>
#include <iomanip>
using namespace std;

double Vuong::Chuvi()const{
	return 4*a;
}
double Vuong::Dientich() const{
	return a*a;
}
void Vuong::Display() const{
	cout<<setw(25)<<"Hinh vuong canh ";
	Hinh2D::Display();
}
