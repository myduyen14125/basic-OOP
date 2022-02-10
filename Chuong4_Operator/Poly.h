#include <iostream>
using namespace std;
#ifndef MATRIX_H
#define MATRIX_H

class Poly {
private:
    int size;

public:
    int *data = NULL;
    Poly(int size = 3);
    Poly(int Init[],int n);
    Poly(const Poly &);
    ~Poly();
    
    Poly operator + (Poly a);
    Poly operator - (Poly a);
    const Poly &operator = (Poly a);

    int &operator [] (int i); //a[i]
    int operator () (int x);  //a(x)

    
    friend ostream &operator<<(ostream &out, const Poly &a);
    friend istream &operator>>(istream &in, Poly &a);
};

#endif