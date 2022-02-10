#include "DSHS.h"
#include "Hocsinh.h"
#include <iostream>
#include <iomanip>
using namespace std;
DSHS::DSHS(int m):n(m){
    data = new Hocsinh [n];
}
DSHS::DSHS(const DSHS &ds):n(ds.n){
    data = new Hocsinh [n];
    for(int i = 0; i<n; i++){
        data[i] = ds.data[i];
    }
}
void DSHS::Nhap(){
    for(int i=0; i<n; i++){
        cout<<"Nhập hoc sinh thu "<<i+1<<":"<<endl;
        this->data[i].Nhap();
    }
}
istream &operator>>(istream &in, DSHS &ds){
    for(int i=0; i<ds.n; i++){
        cout<<"Nhập hoc sinh thu "<<i+1<<":"<<endl;
        cin>>ds.data[i];
    }
    return in;
}
void DSHS::Xuat() const{
    for(int i=0;i<n; i++) {
        cout<<setw(3)<<i+1;
        data[i].Xuat();
    }
}
ostream &operator<<(ostream &out, DSHS &ds){
    for(int i=0;i<ds.n; i++) {
        out<<setw(3)<<i+1;
        out<<ds.data[i];
    }
    return out;
}
void DSHS::Sapxep(){
    
    for (int i = 0; i < n; i++)
    {
        for(int j=i+1;j<n;j++){
            if(!(data[i]>data[j])){
                Hocsinh temp(data[i]);
                data[i]=data[j];
                data[j]=temp;

            }
        }
    }
    
}