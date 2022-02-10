
#include <iostream>
#include "Vecto.h"
using namespace std;
int main(){
    Vecto<int> a,c;
    cout<<"Nhập vecto a: "<<endl;
    cin>>a;
    Vecto<int> b;
    b = a; //b.operator = (a)
    cout<<"Vecto b:"<<b;
    cout<<"Nhập lại vecto b: "<<endl;
    cin>>b;
    c = a+b;
    cout<<"Vecto a:"<<a;
    cout<<"Vecto b:"<<b;
    cout<<"Vecto c=a+b:"<<c;
    c = a-b;
    cout<<"Vecto c=a-b:"<<c;
    cout<<"Tích vô hướng b * c = " << b*c << endl;
    cout<<"Phan tu thu 3 cua c: "<< c[2]<< endl;
    return 0;
}