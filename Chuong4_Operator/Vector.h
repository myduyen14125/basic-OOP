//Khai báo lớp Vecto cấp phát động để biểu diễn 1 vecto
//trong không gian n chiều
//định nghĩa các phép toán =, [], + , -
#ifndef VECTO_H
#define VECTO_H
#include <iostream>
using namespace std;
class Vecto {
    int n; //số chiều của vecto
    int *data; //mảng động chứa tọa độ của vecto
    static int count;//thành viên tĩnh dùng chung cho tất cả các đối tượng thuộc lớp
public:
    Vecto(int size = 3);//default constructor
    Vecto(const Vecto &x);//copy constructor để thực hiện sao chép "sâu"
    ~Vecto(); //destructor: không có đối số, ko có kiểu tra về =>không thể đa năng hóa hủy
    void Nhap();
    void Xuat() const;
    int getn() const { return n;}

    friend istream &operator >>(istream &in, Vecto &x);
    friend ostream &operator <<(ostream &out, const Vecto &x);
    //a = b = c
    // đề tránh việc thực hiện  (a = b) = c thì hàm trả về là 01 tham chiếu hằng
    const Vecto &operator = (const Vecto &x);

    //a[i]: hàm thành viên, toán tử 2 ngôi có 01 tham số 
    int &operator [] (int i) const;
    static int CountObject() {return count;}

    //a + b
    Vecto operator + (const Vecto &x);
    int operator * (const Vecto &x);
    friend void Display(const Vecto &x);//hiện thị tọa độ của vecto
};
Vecto operator - (const Vecto &a, const Vecto &b);
#endif