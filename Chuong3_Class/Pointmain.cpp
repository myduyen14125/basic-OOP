#include "Point.h" 
#include "Point.cpp"

int main() {
    Point p1, p2(10,20), p3(10.0, 3.14/4), p4(p3); 
    // p1.SetPt(10, 20);
    p1.Display();
    Point::PrintCount(); //ya it runs 
    p1.PrintCount();
    // p2.SetPt(5, 15);
    p2.Display(); //this, hàm này k có đối số, thì sẽ tự mặc định đối số this trỏ đến p2
    p3.Display();
    p4.Display();
    p2.OfsetPt(10, 10); 
    p2.Display();
    return 0;
}