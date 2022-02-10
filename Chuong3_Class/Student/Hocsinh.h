#ifndef HOCSINH_H
#define HOCSINH_H
#include <string>
#include <iostream>
using namespace std;
class Hocsinh{
        string ht;
        double toan, van, dtb;
        string xl;
        static int count;
    public:
        Hocsinh(string ten="", double t=0, double v=0);
        Hocsinh(const Hocsinh &x);
        void Nhap();
        void Xuat() const;
        friend ostream &operator<<(ostream &in, Hocsinh &hs);
        friend istream &operator>>(istream &in, Hocsinh &hs);
        friend bool operator>(Hocsinh &hs1, Hocsinh &hs2);

};
#endif