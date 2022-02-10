#include <iostream>
#include "Vector.h"
using namespace std;

int Vecto::count = 0; //khai báo và cấp phát vùng nhớ cho thành viên tĩnh count
Vecto::Vecto(int size):n(size),data(new int [n]){
    count++;
    // n = size;
    // data = new int [n];
}
void Vecto::Nhap(){
    for(int i=0; i<n; i++){
        cout<<"Nhap toa do thu "<<i<<":";
        cin>>this->data[i];
    }
}
void Vecto::Xuat() const {
    for(int i=0; i<n; i++) 
        cout<<data[i]<<" ";
    cout<<endl;
}
//Hàm dựng sao chép: tham số bắt buộc phải là tham chiếu, thuộc lớp 
//đang định nghĩa, đảm bảo tham chiếu không bị thay đổi thì dùng const
Vecto::Vecto(const Vecto &x):n(x.n){
    // this->n = x.n;
    // data = x.data; //sao chép "nông"
    count++;
    this->data = new int [n];
    for(int i=0; i<n; i++)
        this->data[i] = x.data[i]; //sao chép sâu
}
Vecto::~Vecto(){
    count--;
    cout<<"Đang gọi hàm hủy"<<endl;
    delete [] data; //thu hồi vùng nhớ mà data đang chứa địa chỉ
}
void Display(const Vecto &x){
    for(int i=0;i<x.n;i++){
        cout<<x.data[i]<<" ";
    }
    cout<<endl;
}
//cin>>x
istream &operator >>(istream &in, Vecto &x){
    for(int i = 0; i<x.n; i++){
        cout<<"Toa do thu "<<i<< " : ";
        in>>x.operator [] (i); //
    }
    return in;
}
int &Vecto::operator [] (int i) const{ //Phai khai bao la ham hang vi lam viec voi x la doi tuong hang 
    return data[i];
}
//cout<<x
ostream &operator <<(ostream &out, const Vecto &x){
    for(int i=0;i < x.n;i++){
        out<<x[i]<<" ";
    }
    out<<endl;
    return out;
}
const Vecto &Vecto::operator = (const Vecto &x){
    if (this != &x) {
        n = x.n;
        delete [] data;
        data = new int [n];
        for (int i = 0; i<n; i++)
            this->data[i] = x[i]; //sao chép giá trị
    }
    return *this;
}
Vecto Vecto::operator + (const Vecto &x){
    if (n == x.n) {
        Vecto t(n);
        for (int i = 0; i<n; i++)
            t[i] = data[i] + x[i];
        return t;
    }
    return *this;
}
int Vecto::operator * (const Vecto &x){
    int mul = 0;
    if (n == x.n) {
        for (int i = 0; i<n; i++)
            mul += data[i] * x[i];
        return mul;
    }
    
}
//a - b
Vecto operator - (const Vecto &a, const Vecto &b){
    if (a.getn() == b.getn()) {
        Vecto t(a.getn());
        for (int i = 0; i<t.getn(); i++)
            t[i] = a[i] - b[i];
        return t;
    }
    return a;
} //Bình thường là t.data[i] -> để có thể gán trái qua thì phải khai báo định nghĩa cái[] là tham chiếu.  

int main(){
    cout<<"Co "<<Vecto::CountObject()<<" vecto."<<endl;
    Vecto a;//
    cout<<"Nhập vecto a: "<<endl;
    cin>>a;
    cout<<"Co "<<Vecto::CountObject()<<" vecto."<<endl;
    //a.CountObject(): không có tham số ẩn this truyền vào trong lời gọi hàm
    Vecto b;
    b = a; //phép gán
    cout<<"Co "<<a.CountObject()<<" vecto."<<endl;
    cout<<"Nhập vecto b: "<<endl;
    cin>>b;
    Vecto c = a + b; // hàm dựng sao chép -> Vì hắn sao chép để cộng -> nên xong hàm ni là có 1 cái hàm hủy chạy lun nè. 
    cout<<"Co "<<a.CountObject()<<" vecto."<<endl;
    cout<<"Vecto a:"<<a;
    cout<<"Vecto b:"<<b;
    cout<<"Vecto c:"<<c;
    
    Vecto d;  
    d = a - b; //hàm toán tử gán =

    
    cout<<"Vecto d:"<<d;
    return 0;
}