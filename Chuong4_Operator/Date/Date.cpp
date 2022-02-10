// Cài đặt 1 lớp Date gồm ngày tháng năm 
// Định nghĩa các phép toán >> << nhập xúâ ngày
// Địhj nghĩa phép toán ++ -- tăng giảm 1 ngày 
#include<iostream>
using namespace std;
#ifndef DATE_H 
#define DATE_H

class Date {
    private: 
        int day, month, year;
        int checkDay() const;
    public: 
        Date(int dd = 1, int mm = 1, int yy = 2021);
        // Date(int dd, int mm, int yy);
        friend istream &operator >>(istream &in, Date &x);
        friend ostream &operator <<(ostream &out, const Date &x);
        //++a tien to, ham toan tu tra ve doi tuong da thay doi -> tang gia tri len 1 don vi -> tra ve doi tuong da thya doi nen tra ve la mot tham chieu. 
        Date &operator ++();
        //a++: hau to, ham thay doi gia tri toan hang a -> tra ve gia tri cua doi tuong truoc khi thay doi -> tra ve mot gia tri chu khong phai la tham chieu.
        Date operator ++(int);
};

#endif

Date::Date(int dd, int mm, int yy):day(dd), month(mm), year(yy) {
    // day = dd;
    // month = mm; 
    // year = yy;
}
//cin >> today : ham toan cuc, co cin thuoc lop istream nen phai la ham toan cuc
int Date::checkDay() const {
    int songay[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        songay[2] = 29;
    }
    return songay[month];
}

istream &operator >>(istream &in, Date &x) {
    cout << "Nhap ngay: "; in >> x.day;
    cout << "Nhap thang: " ; in >> x.month;
    cout << "Nhap nam: "; in >> x.year;
    return in;
}
ostream &operator <<(ostream &out, const Date &x) {
    out << x.day << "/" << x.month << "/" << x.year;
    return out;
}
Date &Date::operator ++() {
    if (day < checkDay()) day++;
    else {
        day = 1;   
        if (month < 12) month++;
        else {
            month = 1;
            year++;
        }
    }
    return *this;
}
Date Date::operator ++(int) {
    Date t = *this; 
    ++(*this); //Han la doi so gia kieu int
    return t; //Ngay truoc khi thay doi
}


int main() {
    Date today;
    cout << "Nhap vao ngay bat ki: " << endl;
    cin >> today;
    cout << "Ngay vua nhap: " << today << endl;
    cout << "Ngay hom sau: " << today++ << endl;
    return 0;
}