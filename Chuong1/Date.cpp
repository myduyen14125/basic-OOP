#include<iostream>
using namespace std;

struct Date {
    int day, month;
    long year;
};

long daysOfYear(long y); //Kiem tra so ngay trong nam: Nhuan/Khong?
int daysOfMonth(int m, long y); //Kiem tra so ngay trong tung thang
istream &operator >> (istream &in, Date &D);
ostream &operator << (ostream &out, Date &D);
bool checkDate (Date &D); //Kiem tra ngay hop le
void dayOfWeek(Date &D); //Thu cua ngay trong tuan
void operator ++ (Date &D);
void operator -- (Date &D);
bool operator > (Date &A, Date &B) ;
bool operator < (Date &A, Date &B);
bool operator == (Date &A, Date &B);
bool operator != (Date &A, Date &B);

int main() {
    Date A, B;
    cout << "Nhap vao ngay A " << endl;
    cin >> A;
    cout << "Nhap vao ngay B" << endl;
    cin >> B;
    //Check date A
    if (checkDate(A) == 0) {
        cout << "\nNgay A khong hop le!" << endl;
    }
    else {
        cout << "\nNgay dau tien la ";
        dayOfWeek(A);
        cout << "\nTang len 1 ngay: ";
            ++A;
            cout << "\tNgay A =>" << A << endl;
        cout << "Giam di 1 ngay: ";
            --A; --A;
            cout << "\tNgay A =>" << A << endl;
    }
    //Check date B
    if (checkDate(B) == 0) {
        cout << "\nNgay B khong hop le!" << endl;
    }
    else {
        cout << "\nNgay thu hai la ";
        dayOfWeek(B);
        cout << "\nTang len 1 ngay: ";
            ++B;
            cout << "\tNgay B =>" << B << endl;
        cout << "Giam di 1 ngay: ";
            --B; --B;
            cout << "\tNgay B =>" << B << endl;
    }
    
    //Compare A and B
    if (checkDate(A) == 1 && checkDate(B) == 1) {
        cout << "\nSo sanh 2 ngay: ";
        if (A == B) 
            cout << "A, B giong nhau";
        else if (A < B) 
            cout << "Ngay A truoc ngay B";
        else if (A > B) 
            cout << "Ngay A sau ngay B";
    }
    else cout << "\nKhong the so sanh vi co ngay khong hop le!";
    
}

long daysOfYear(long y) {
    if ( (y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0)) ){
        return 366; //Leap year
    }
    return 365;
}
int daysOfMonth(int m, long y) {
    switch(m){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
            break;
        case 2:
            return daysOfYear(y) - 337;
            break;
        default:
            return 30;        
    }
}
istream &operator >> (istream &in, Date &D){
    cout << "\tNgay: "; in >> D.day;
    cout << "\tThang: "; in >> D.month;
    cout << "\tNam: "; in >> D.year;
    return in;
}
ostream &operator << (ostream &out, Date &D){
    out << D.day << "/" << D.month << "/" << D.year;
    return out;
}
bool checkDate (Date &D) {
    if (D.year <= 0 || D.month <= 0 || D.month > 13 || D.day <= 0 || D.day > 31) 
        return 0;
    switch (D.month) {
        case 2:
            if (daysOfYear(D.year) == 365 && D.day > 28) return 0;
            if (daysOfYear(D.year) == 366 && D.day > 29) return 0;
            break;
        default:
            if (D.day > 30) return 0;
    }
    return 1;
}
void dayOfWeek(Date &D) {
    //Zeller's formula
    int thu, day, month, a;
    long year;
    a = (14 - D.month) / 12; 
    day = D.day;
    month = D.month + 12 * a - 2;
    year = D.year - a;
    thu = (day + year + year/4 -year/100 +year/400 + (31 * month) /12) % 7; //Result: 0 <= thu <= 6;
    
    if(thu == 0) cout << "Chu nhat";
    else cout << "Thu " << thu + 1;
}
void operator ++ (Date &D) {
    D.day++;
    if (D.day > daysOfMonth(D.month, D.year)) {
        D.day = 1;
        D.month++;
        if(D.month > 12) {
            D.month = 1;
            D.year++;
        }
    } 
}
void operator -- (Date &D) {
    D.day--;
    if (D.day == 0) {
        D.month--;
        if(D.month == 0) {
            D.month = 12;
            D.year--;
        }
        D.day = daysOfMonth(D.month, D.year);
    }
}
bool operator > (Date &A, Date &B) {
    if (A.year > B.year)
        return 1;
    else if ((A.year == B.year) && (A.month > B.month))
        return 1;
    else if ((A.year == B.year) && (A.month == B.month) && (A.day > B.day))
        return 1;
    else return 0;
}
bool operator < (Date &A, Date &B) {
    if (A.year < B.year)
        return 1;
    else if ((A.year == B.year) && (A.month < B.month))
        return 1;
    else if ((A.year == B.year) && (A.month == B.month) && (A.day < B.day))
        return 1;
    else return 0;
}
bool operator == (Date &A, Date &B) {
    if ((A.year == B.year) && (A.month == B.month) && (A.day == B.day))
        return 1;
    else return 0;
}
bool operator != (Date &A, Date &B) {
    if ((A.year != B.year) || (A.month != B.month) || (A.day != B.day))
        return 1;
    else return 0;
}