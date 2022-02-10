#include<iostream>
#include<math.h>
#include "Complex.h"
using namespace std;

Complex::Complex(int num) {
    this->r = num;
    this->i = 0;
}
Complex::Complex(int x, int y) {
    r = x;
    i = y;
}
Complex::Complex(const Complex& c) {
    r = c.r;
    i = c.i;
}

//Xu li voi tu so && mau so
void Complex::setReal(int x) {
    r = x;
}
void Complex::setImaginary(int x) {
    i = x;
}
int Complex::getReal() {
    return r;
}
int Complex::getImaginary() {
    return i;
}

//Ham nhap xuat
void Complex::setComplex() {
    int option;
    cout << " 1. Khong nhap (Mac dinh)" << endl;
    cout << " 2. So nguyen (Chi phan thuc)" << endl;
    cout << " 3. Phan thuc, phan ao" << endl;
    cout << "Nhap lua chon: ";
    cin >> option;
    
    if (option == 1);
    else if (option == 2) {
        cout << "  Nhap so nguyen: ";
        cin >> this->r;
    }
    else if (option == 3) {
        cout << "  Nhap phan thuc: "; 
        cin >> this->r;
        cout << "  Nhap phan ao: "; 
        cin >> this->i;
    }
    else cout << "Lua chon khong hop le!";
}
void Complex::display() {
    cout << r << "." << i << "i";
}

//Ham tinh toan So phuc  
double Complex::module() {
    double module = 0;
    module = sqrt(pow(r, 2) + pow(i, 2));
    return module;
}
void Complex::add(Complex a) {
    r = r + a.r;
    i = i + a.i;
}
void Complex::sub(Complex a) {
    r = r - a.r;
    i = i - a.i;
}
void Complex::mul(Complex a) {
    r = r * a.r - i * a.i;
    i = r * a.i + i * a.r;
}
void Complex::div(Complex a) {
    r = (r * a.r + i * a.i) / (pow(a.r, 2) + pow(a.i, 2));
    i = (a.r * i - a.i * r) / (pow(a.r, 2) + pow(a.i, 2));
}
void Complex::compare(Complex a) {
    if(r == a.r && i == a.i) cout << "Hai so phuc bang nhau";
    else cout << "Hai so phuc khac nhau";
}

int main() {
    Complex c1, c2, temp;
    cout << "Nhap vao So phuc A: " << endl;    
    c1.setComplex();
    cout << "So phuc A: "; c1.display();
    cout << "\n---------" << endl;
    cout << "Nhap vao So phuc B: " << endl;    
    c2.setComplex();
    cout << "So phuc B: "; c2.display();
    cout << "\n---------";
    cout << "\n1. Module : ";
        cout << "A: " << c1.module() << "\tB: " << c2.module();
    cout << "\n2. A + B = "; 
        temp = c1;
        temp.add(c2); 
        temp.display();
    cout << "\n3. A - B = "; 
        temp = c1;
        temp.sub(c2); 
        temp.display();
    cout << "\n4. A * B = "; 
        temp = c1;
        temp.mul(c2); 
        temp.display();
    cout << "\n5. A / B = "; 
        temp = c1;
        temp.div(c2); 
        temp.display();
    cout << "\n6. So sanh A & B: "; 
        c1.compare(c2);
}