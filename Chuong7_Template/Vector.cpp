#include <iostream>
#include "Vector.h"
using namespace std;

template <typename T>
int Vecto<T>::count = 0; //khai báo và cấp phát vùng nhớ cho thành viên tĩnh count

template <typename T>
Vecto<T>::Vecto(int size):n(size),data(new T [n]){
    count++;
    // n = size;
    // data = new int [n];
}

template <typename T>
void Vecto<T>::Nhap(){
    for(int i = 0; i < n; i++){
        cout<<"Nhap toa do thu "<<i<<":";
        cin>>this->data[i];
    }
}

template <typename T>
void Vecto<T>::Xuat() const {
    for(int i=0; i<n; i++) 
        cout<<data[i]<<" ";
    cout<<endl;
}

template <typename T>
//Hàm dựng sao chép: tham số bắt buộc phải là tham chiếu, thuộc lớp đang định nghĩa, đảm bảo tham chiếu không bị thay đổi thì dùng const
Vecto<T>::Vecto<T>(const Vecto <T>& x):n(x.n){
    // this->n = x.n;
    // data = x.data; //sao chép "nông"
    count++;
    this->data = new T[n];
    for(int i=0; i<n; i++)
        this->data[i] = x.data[i]; //sao chép sâu
}

template <typename T>
Vecto<T>::~Vecto(){
    count--;
    cout<<"Đang gọi hàm hủy"<<endl;
    delete [] data; //thu hồi vùng nhớ mà data đang chứa địa chỉ
}

template <typename T>
void Vecto<T>::Display(){
    for(int i=0;i< n; i++){
        cout << data[i] << " ";
    }
    cout<<endl;
}

template <typename T>
istream &operator >>(istream &in, Vecto<T>&x){
    for(int i = 0; i<x.n; i++){
        cout<<"Toa do thu "<<i<< " : ";
        in>>x.operator [] (i); //
    }
    return in;
}

template <typename T>
int &Vecto<T>::operator [] (int i) const{ //Phai khai bao la ham hang vi lam viec voi x la doi tuong hang 
    return data[i];
}


template <typename T>
ostream &operator <<(ostream &out, const Vecto <T> &x){
    for(int i=0;i < x.n;i++){
        out<<x[i]<<" ";
    }
    out<<endl;
    return out;
}

template <typename T>
const Vecto<T> &Vecto<T>::operator = (const Vecto <T>&x){
    if (this != &x) {
        n = x.n;
        delete [] data;
        data = new T[n];
        for (int i = 0; i<n; i++)
            this->data[i] = x[i]; //sao chép giá trị
    }
    return *this;
}

template <typename T>
Vecto<T> Vecto<T>::operator + (const Vecto <T>&x){
    if (n == x.n) {
        Vecto t(n);
        for (int i = 0; i<n; i++)
            t[i] = data[i] + x[i];
        return t;
    }
    return *this;
}

template <typename T>
Vecto<T> Vecto<T>::operator - (const Vecto <T>&x){
    if (n == x.n) {
        Vecto t(n);
        for (int i = 0; i<n; i++)
            t[i] = data[i] + x[i];
        return t;
    }
    return *this;
}

template <typename T>
int Vecto<T>::operator * (const Vecto <T>& x){
    int mul = 0;
    if (n == x.n) {
        for (int i = 0; i<n; i++)
            mul += data[i] * x[i];
        return mul;
    }
    
}

