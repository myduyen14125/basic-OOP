#include "hinh.h"
#include <iostream>
#include <iomanip>
using namespace std;
Hinh::Hinh(double aa):a(aa){}
void Hinh::Display() const{
	cout<<"a :"<<setw(5)<<a;
}

