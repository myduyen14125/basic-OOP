#include <iostream>
#include "Vecto.h"
using namespace std;
template <typename T>
Vecto<T>::Vecto(int size):n(size),data(new T [n]){
}
template <typename T>
Vecto<T>::Vecto(const Vecto<T> &x):n(x.n){
    this->data = new T [n];
    for(int i=0; i<n; i++)
        this->data[i] = x.data[i]; 
}
template <typename T>
Vecto<T>::~Vecto(){
    delete [] data; 
}
template <typename U>
istream &operator >>(istream &in, Vecto<U> &x){
    for(int i = 0; i<x.n; i++){
        cout<<"Toa do thu "<<i<< " : ";
        in>>x[i]; //
    }
    return in;
}
template <typename T>
T &Vecto<T>::operator [] (int i) const{
    return data[i];
}
template <typename U>
ostream &operator <<(ostream &out, const Vecto<U> &x){
    for(int i=0;i < x.n;i++){
        out<<x[i]<<" ";
    }
    out<<endl;
    return out;
}
template <typename T>
Vecto<T> Vecto<T>::operator + (const Vecto<T> &a)
{
    Vecto<T> b=*this;
    for(int i=0;i<b.n;i++)
    {
        b.data[i]+=a.data[i];
    }
    return b;
}
template <typename T>
Vecto<T> Vecto<T>::operator - (const Vecto<T> &a)
{
    Vecto<T> b = *this;
    for(int i=0;i<b.n;i++)
    {
        b.data[i]-=a.data[i];
    }
    return b;
}
template <typename T>
T Vecto<T>::operator * (const Vecto<T> &a)
{
    T p=0;
    for(int i=0;i<n;i++)
    {
        p+=this->data[i]*a.data[i];
    }
    return p;
}
template <typename T>
const Vecto<T> &Vecto<T>::operator = (const Vecto<T> &x){
    if (this != &x) {
        n = x.n;
        delete [] data;
        data = new T [n];
        for (int i = 0; i<n; i++)
            this->data[i] = x[i]; 
    }
    return *this;
}