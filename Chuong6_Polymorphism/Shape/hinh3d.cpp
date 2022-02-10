#include "hinh3d.h"
#include <iostream>
#include <iomanip>
using namespace std;
void Hinh3D::Display() const{
	Hinh::Display();
	cout<<setw(10)<<" Dien tich: "<<setw(7)<<Dientich()
		<<setw(10)<<" The tich: "<<setw(7)<<Thetich()<<endl;
}
