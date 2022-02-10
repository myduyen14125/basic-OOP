//Cai đặt 1 vecto trong không gian n chiều 
//Yêu cầu cấp phát động 
//Cài đặt các phép toán: [], =, +, -, *, >>, << 
#include<iostream>
using namespace std;
#ifndef VECTOR_H 
#define VECTOR_H

class vector {
    private: 
        int n; 
        float *v;
    public: 
        vector(int size);
        vector(const vector &a);
        ~vector();

        void init(); //Nhap cac phan tu cua vecto
        void display(); //Xuat phan tu du lieu cua vecto 
        int check(vector &a); 

        void operator =(vector &a); //Gan 1 vecto cho 1 vecto
        friend vector operator +(vector &a, vector &b);
        friend vector operator -(vector &a,vector &b);
        friend vector operator *(vector &a,vector &b);

};

#endif

vector::vector(int size) {
    n = size;
    v = new float [n];
}
vector::vector(const vector &a) {
    int i;
    n = a.n;
    v = new float [n];
    for (i = 0; i < n; i++)
        v[i] = a.v[i];
}
vector::~vector() {
    delete v;
}

void vector::init() {
    int i;
    for (i = 0; i < n; i++) {
        cout << "v[" << i << "]:" ;
        cin >> v[i];
    }
}
void vector::display() {
    int i;
    cout << "(";
    for (i = 0; i<n; i++)
        cout << v[i] << " ";
    cout << ")";
}

int vector::check(vector &a)
{
    if (n == a.n) return 1;
    return 0;
}
void vector:: operator =(vector &a) {
    int i;
    n = a.n;
    v = new float [n];
    for (i = 0; i<n; i++)
        v[i]=a.v[i];
}
vector operator +(vector &a,vector &b) {
    int i;
    vector c = a;
    for (i = 0; i < a.n; i++)
        c.v[i] = a.v[i] + b.v[i];
    return c;
}
vector operator -(vector &a,vector &b) {
    int i;
    vector c = a;
    for (i = 0; i < a.n; i++)
        c.v[i] = a.v[i] - b.v[i];
    return c;
}
int main() {
    int n;
    cout << "Nhap so phan tu cua vector a: ";
        cin >> n;
        vector a(n);
    cout <<"Nhap vector a: \n"; 
        a.init();
    cout <<"\nNhap so phan tu cua vector b: ";
        cin >> n;
        vector b(n);
    cout <<"Nhap vector b: \n";
        b.init();
    cout <<"vector a: ";
        a.display();
    cout <<"\nvector b: ";
        b.display();
    if(a.check(b)==1) {cout <<"\nvector tong la: ";
        (a+b).display();
    }
    else cout <<"\nK cong duoc 2 vector nay: ";
    
}