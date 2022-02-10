#include<iostream>
#include<math.h>
using namespace std;

#include "Point.h"

int Point::count = 0; //Cap phat vung nho cho bien count 
Point::Point(int xx, int yy) {
    x = xx;
    y = yy;
    count++;
};
Point::Point(double len, double angle) {
    x = int(len*cos(angle));
    y = int(len*sin(angle));
};
Point::Point(const Point &p) { //khai báo tham chiếu  hằng để giá trị ban đầu của tham chiếu k thể thay đổi đc 
    x = p.x;    
    y = 0;
}
void Point::SetPt(int xx, int yy) {
    this->x = xx;
    this->y = yy;
}
void Point::OfsetPt(int dx, int dy) {
    this->x += dx; 
    this->y += dy;
}
void Point::Display() {
    cout << "(" << x << "," << y << ")" << endl;
}
void Point::PrintCount() {
    cout << "Count = " << count;
}
//Note: this->x = xx  ~ ~ Point::x = xx 