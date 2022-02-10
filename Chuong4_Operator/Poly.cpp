#include <iostream>
#include <math.h>
#include "Poly.h"
using namespace std;

Poly::Poly(int size)
{
    this->size = size;
    this->data = new int[size + 1];
    int i;
    for (i = 0; i <= size; i++)
    {
        this->data[i] = 0;
    }
}
Poly::Poly(int Init[], int n)
{
    this->size = n;
    data = new int[n + 1];
    for (int i = 0; i <= n; i++)
        this->data[i] = Init[i];
}
Poly::Poly(const Poly &a)
{
    this->size = a.size;
    data = new int[this->size + 1];
    for (int i = 0; i <= this->size; i++)
        this->data[i] = a.data[i];
}
Poly::~Poly()
{
    delete[] data;
}

//---------
Poly Poly::operator+(Poly a)
{
    Poly result;
    if (this->size >= a.size)
    {
        Poly result(*this);
    }
    else
    {
        Poly result(a);
    }
    int n = (this->size >= a.size) ? this->size : a.size;
    for (int i = 0; i <= n; i++)
    {
        result[i] = this->data[i] + a.data[i];
    }
    return result;
}
Poly Poly::operator-(Poly a)
{
    Poly result;
    if (this->size >= a.size)
    {
        Poly result(*this);
    }
    else
    {
        Poly result(a);
    }
    int n = (this->size >= a.size) ? this->size : a.size;
    for (int i = 0; i <= n; i++)
    {
        result[i] = this->data[i] - a.data[i];
    }
    return result;
}
const Poly &Poly::operator=(Poly a)
{
    this->size = a.size;
    for (int i = 0; i <= size; i++)
        this->data[i] = a.data[i];
    return *this;
}

int &Poly::operator[](int i)
{
    return this->data[i];
}
int Poly::operator()(int x)
{
    int result = 0;
    for (int i = 0; i <= this->size; i++)
    {
        result = result + this->data[i] * pow(x, i);
    }
    return result;
}

ostream &operator<<(ostream &out, const Poly &a)
{
    cout << "\nf(x) = ";
    for (int i = a.size; i >= 0; i--)
    {
        cout << a.data[i] << "*x^" << i;
        if (i != 0)
            cout << " + ";
    }
    return out;
}
istream &operator>>(istream &in, Poly &a)
{
    cout << "\nNhap bac cua da thuc n = ";
    cin >> a.size;
    for (int i = a.size; i >= 0; i--)
    {
        cout << "\na[" << i << "] = ";
        cin >> a.data[i];
        /* code */
    }

    return in;
}

int Init[5] = {1, 2, 3, 4, 5};
int main()
{
    int x, i;
    Poly f1;
    Poly f2(5);
    Poly f3(Init, 5);
    Poly f4(f2);
    cin >> f1;
    cout << f1 << endl;
    cout << f2 << endl;
    cout << f3 << endl;
    cout << f4 << endl;
    cout << "\nNhap vi tri i = ";
    cin >> i;
    cout << "f1[" << i << "] = " << f1[i] << endl;
    cout << "\nNhap gia tri x can tinh x = ";
    cin >> x;
    cout << "\nf1(" << x << ") = " << f1(x) << endl;
    cout << "\nf1 + f2 = " << f1 + f2;
    cout << "\nf3 - f4 = " << f3 - f4;

    return 0;
}