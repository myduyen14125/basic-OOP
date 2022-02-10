//Khai báo lớp Vecto cấp phát động để biểu diễn 1 vecto
//trong không gian n chiều
//định nghĩa các phép toán =, [], + , -
#ifndef VECTO_H
#define VECTO_H
#include <iostream>
using namespace std;

template <typename T>
class Vecto {
    int n; //số chiều của vecto
    T *data; //mảng động chứa tọa độ của vecto, có kiểu T 
    static int count;//thành viên tĩnh dùng chung cho tất cả các đối tượng thuộc lớp
public:
    Vecto(int size = 3);//default constructor
    Vecto(const Vecto <T>& x) {
        
    };//copy constructor để thực hiện sao chép "sâu"
    ~Vecto(); //destructor: không có đối số, ko có kiểu tra về =>không thể đa năng hóa hủy
    void Nhap();
    void Xuat() const;
    int getn() const { return n;}

    template <typename U>
    friend istream &operator >>(istream &in, Vecto <U>& x);
    friend ostream &operator <<(ostream &out, const Vecto <U>& x);
    //a = b = c
    // đề tránh việc thực hiện  (a = b) = c thì hàm trả về là 01 tham chiếu hằng
    const Vecto &operator = (const Vecto T& x);

    //a[i]: hàm thành viên, toán tử 2 ngôi có 01 tham số 
    int &operator [] (int i) const;
    static int CountObject() {return count;}

    //a + b
    Vecto operator + (const Vecto <T>&x);
    Vecto operator - (const Vecto <T>&x);
    int operator * (const Vecto <T>&x);
    void Display();//hiện thị tọa độ của vecto
};

#endif

#include <iostream>
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

