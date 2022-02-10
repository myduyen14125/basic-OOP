#ifndef VECTO_H
#define VECTO_H
#include <iostream>
using namespace std;
template <typename T>
class Vecto {
    int n; 
    T *data; 
public:
    Vecto(int size = 3);
    Vecto(const Vecto &x);
    ~Vecto(); 
    const Vecto &operator = (const Vecto &x);
    Vecto operator + (const Vecto &a);
    Vecto operator - (const Vecto &a);
    T operator * (const Vecto &a);
    T &operator [] (int i) const;
    template <typename U>
    friend istream &operator >>(istream &in, Vecto<U> &x);
    template <typename U>    
    friend ostream &operator <<(ostream &out, const Vecto<U> &x);
};

#endif