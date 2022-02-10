#include "Hocsinh.h"
#include <iostream>
#include "DSHS.h"
int main(){
    DSHS ds;
    cin>>ds;
    cout<<"Danh sach hoc sinh vua nhap:"<<endl;
    cout<<ds;
    ds.Sapxep();
    cout<<"Sap xep giam dan"<<endl;
    cout<<ds;
    return 0;
    
}