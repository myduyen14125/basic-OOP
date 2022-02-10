#include<iostream>
#include<math.h>
#include "Fraction.h"
using namespace std;


Fraction::Fraction(int num) { //Truyen so nguyen
    this->tuso = num;
    this->mauso = 1;
}
Fraction::Fraction(int x, int y) {
    tuso = x;
    mauso = y;
}
Fraction::Fraction(const Fraction& fr) {
    tuso = fr.tuso;
    mauso = fr.mauso;
}

//Xu li voi tu so && mau so
void Fraction::setNumerator(int x) {
    tuso = x;
}
void Fraction::setDenumerator(int x) {
    mauso = x;
}
int Fraction::getNumerator() {
    return tuso;
}
int Fraction::getDenumerator() {
    return mauso;
}

//Ham nhap xuat
void Fraction::setFraction() {
    int option;
    cout << " 1. Khong nhap (Mac dinh)" << endl;
    cout << " 2. So nguyen" << endl;
    cout << " 3. Tu so, mau so" << endl;
    cout << "Nhap lua chon: ";
    cin >> option;
    
    if (option == 1);
    else if (option == 2) {
        cout << "  Nhap so nguyen: ";
        cin >> this->tuso;
    }
    else if (option == 3) {
        cout << "  Nhap tu so: "; 
        cin >> this->tuso;
        cout << "  Nhap mau so: "; 
        cin >> this->mauso;
    }
    else cout << "Lua chon khong hop le!";
}
void Fraction::display() {
    cout << tuso << "/" << mauso;
}

//Ham tinh toan phan so  
void Fraction::inverse() {
    int temp = tuso;
    tuso = mauso;
    mauso = temp;
}
void Fraction::reduceFrac() {
    int x = tuso;
    int y = mauso;
    //Tim GCD - UCLN
    while (x != y) {
        if (x > y) x -= y; 
        else y -= x;
    }
    tuso /= x;
    mauso /= x;
}
void Fraction::addFrac(Fraction a) {
    tuso = tuso * a.mauso + mauso * a.tuso;
    mauso = mauso * a.mauso;
}
void Fraction::subFrac(Fraction a) {
    tuso = tuso * a.mauso - mauso * a.tuso;
    mauso = mauso * a.mauso;
}
void Fraction::mulFrac(Fraction a) {
    tuso = tuso * a.tuso;
    mauso = mauso * a.mauso;
}
void Fraction::divFrac(Fraction a) {
    tuso = tuso * a.mauso;
    mauso = mauso * a.tuso;
}
void Fraction::compareFrac(Fraction a) {
    double temp1 = tuso / mauso;  
    double temp2 = a.tuso / a.mauso;
    if (temp1 < temp2) cout << "A < B";
    if (temp1 > temp2) cout << "A > B";
    else cout << "A == B";
}

int main() {
    Fraction fr1, fr2, temp;
    cout << "Nhap vao phan so A: " << endl;    
    fr1.setFraction();
    cout << "Phan so A: "; fr1.display();
    cout << "\n---------" << endl;
    cout << "Nhap vao phan so B: " << endl;    
    fr2.setFraction();
    cout << "Phan so B: "; fr2.display();
    cout << "\n---------";
    cout << "\n1. Nghich dao phan so: " << endl; 
        Fraction temp1 = fr1, temp2 = fr2;
        temp1.inverse(); temp2.inverse();
        cout << "\tPhan so A: "; 
        temp1.display();
        cout << "\tPhan so B: ";
        temp2.display();
    cout << "\n2. Rut gon phan so: " << endl; 
        if (fr1.getNumerator() != 0) {
            fr1.reduceFrac();
        }
        if (fr2.getNumerator() != 0) {
            fr2.reduceFrac();
        }
        cout << "\tPhan so A: "; 
        fr1.display();
        cout << "\tPhan so B: ";
        fr2.display();
    cout << "\n3. A + B: "; 
        temp = fr1;
        temp.addFrac(fr2); temp.reduceFrac();
        temp.display();
    cout << "\n4. A - B: "; 
        temp = fr1;
        temp.subFrac(fr2); temp.reduceFrac();
        temp.display();
    cout << "\n5. A * B: "; 
        temp = fr1;
        temp.mulFrac(fr2); temp.reduceFrac();
        temp.display();
    cout << "\n6. A / B: "; 
        temp = fr1;
        temp.divFrac(fr2); temp.reduceFrac();
        temp.display();
    cout << "\n7. So sanh A & B: "; 
        fr1.compareFrac(fr2);
}