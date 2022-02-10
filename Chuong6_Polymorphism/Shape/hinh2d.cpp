#include "hinh2d.h"
#include <iostream>
#include <iomanip>
using namespace std;
void Hinh2D::Display() const{
	Hinh::Display();
	cout<<setw(10)<<" Chu vi: "<<setw(7)<<Chuvi()
		<<setw(10)<<" Dien tich: "<<setw(7)<<Dientich()<<endl;
}
