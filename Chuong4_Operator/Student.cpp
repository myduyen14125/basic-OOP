#include<iostream>
#include <iomanip>
#include "Student.h"
using namespace std;

Student::Student(string name) {
    this->name = name;
}
Student::Student(string name, float x, float y){
    this->name = name;
    this->math = x;
    this->literature = y;
    this->avg = (math + literature) / 2; 
    this->type = (avg < 5) ? "Yeu" : (avg < 6.5) ? "Trung binh" : (avg < 8) ? "Kha" : "Gioi";
}
Student::Student(const Student& s) {
    this->name = s.name;
    this->math = s.math;
    this->literature = s.literature;
    this->avg = s.avg;
    this->type = s.type;
}

//Ham nhap xuat 1SV
ostream &operator << (ostream &out, const Student &s) {
    cout << "------------" << endl;
    cout << "Ho ten   : "; out << s.name << endl;
    cout << "Diem toan: "; out << s.math << endl;
    cout << "Diem van : "; out << s.literature << endl;
    cout << "Diem TB  : "; out << s.avg << endl;
    cout << "Xep loai : "; out << s.type << endl;
    cout << "------------" << endl;
    return out; 
}

istream &operator >> (istream &in, Student &s) {
    cout << "  Nhap ho ten: ";
    getline(in, s.name);
    cout << "  Nhap diem Toan: ";
    in >> s.math;
    cout << "  Nhap diem Van : ";
    in >> s.literature;
    s.avg = (s.math + s.literature) / 2;
    s.type = (s.avg < 5) ? "Yeu" : (s.avg < 6.5) ? "Trung binh" : (s.avg < 8) ? "Kha" : "Gioi";
    return in;
}

bool Student::checkScore(const Student &s) {
    if (s.math < 0 || s.math > 10 || s.literature < 0 || s.literature > 10) 
        return 0;
    return 1;
}

//Get - Set each attribute 
void Student::setName(string name) {
    this->name = name;
}
void Student::setMath(float x) {
    this->math = x;
}
void Student::setLiterature(float x) {
    this->literature = x;
}
string Student::getName() {
    return this->name;
}
float Student::getMath() {
    return this->math;
}
float Student::getLiterature() {
    return this->literature;
}

//Operator
bool Student::operator > (Student &s) {
    if (this->avg > s.avg) return true;
    return false;
} 
bool Student::operator < (Student &s) {
    if (this->avg < s.avg) return true;
    return false;
} 
bool Student::operator == (Student &s) {
    if (this->avg == s.avg) return true;
    return false;
} 
bool Student::operator >= (Student &s) {
    if (this->avg >= s.avg) return true;
    return false;
} 
bool Student::operator <= (Student &s) {
    if (this->avg <= s.avg) return true;
    return false;
} 
bool Student::operator != (Student &s) {
    if (this->avg != s.avg) return true;
    return false;
} 
const Student Student::operator = (Student &s) {
    name = s.name;
    math = s.math;
    literature = s.literature;
    avg = s.avg;
    type = s.type;
    return (*this);
}

Student::~Student() {
    cout << "\ndelete";
}

int main() {
    Student s1;
    cout << "Nhap vao thong tin HS: " << endl; 
    cin >> s1;
    cout << "Hoc sinh 1: "  << endl << s1;  
    Student s2 = s1;
    cout << "Hoc sinh 2: "  << endl << s2;  
    Student s3("Nguyen An", 10, 7);
    cout << "Hoc sinh 3: "  << endl << s3;  
    if (s1 > s3) cout << "\nHoc sinh 1 diem cao hon hoc sinh 3";
    else if (s1 < s3) cout << "\nHoc sinh 1 diem thap hon hoc sinh 3";
    else if (s1 == s3) cout << "\nHoc sinh 1 bang diem hoc sinh 3";
    return 0;
}