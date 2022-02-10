#include <iostream>
#include "Vector.h"
#include "Vector.cpp"
using namespace std;

int main(){
    cout<<"Co "<<Vecto<int>::CountObject()<<" vecto."<<endl;
    Vecto<int> a;//
    cout<<"Nhập vecto a: "<<endl;
    cin>>a;
    cout<<"Co "<<Vecto<int>::CountObject()<<" vecto."<<endl;
    //a.CountObject(): không có tham số ẩn this truyền vào trong lời gọi hàm
    Vecto<int> b;
    b = a; //phép gán
    cout<<"Co "<<a.CountObject()<<" vecto."<<endl;
    cout<<"Nhập vecto b: "<<endl;
    cin>>b;
    Vecto<int> c = a + b; // hàm dựng sao chép -> Vì hắn sao chép để cộng -> nên xong hàm ni là có 1 cái hàm hủy chạy lun nè. 
    cout<<"Co "<<a.CountObject()<<" vecto."<<endl;
    cout<<"Vecto a:"<<a;
    cout<<"Vecto b:"<<b;
    cout<<"Vecto c:"<<c;
    
    Vecto<int> d;  
    d = a - b; //hàm toán tử gán =

    
    cout<<"Vecto d:"<<d;
    return 0;
}