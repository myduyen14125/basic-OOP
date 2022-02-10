#include<iostream>
#include<math.h>
#include "Student.h"
using namespace std;

int Student::count = 0; //Định nghĩa thành viên tĩnh - cấp phát vùng nhớ 
Student::Student(string name) {
    this->name = name;
}
Student::Student(string name, float x, float y): name(name), math(x),literature(y) {
    // this->name = name;
    // this->math = x;
    // this->literature = y;
    //C2: khoi tao cach 2 o tren ham luon ne 
    // ``` name(name), math(x),literature(y) ``` 
    count++;
}
Student::Student(const Student& s) {
    this->name = s.name;
    this->math = s.math;
    this->literature = s.literature;
    count++;
}

//Ham nhap xuat
void Student::setStudent() {
    int option, x, y;
    cout << " 1. Khong nhap (HS mac dinh)" << endl;
    cout << " 2. Ho ten (Diem mac dinh)" << endl;
    cout << " 3. Ten, diem Toan, diem Van" << endl;
    cout << "Nhap lua chon: ";
    cin >> option;
    
    if (option == 1);
    else if (option == 2) {
        cout << "  Nhap ho ten: ";
        cin.ignore();
        getline(cin, this->name);
    }
    else if (option == 3) {
        cout << "  Nhap ho ten: ";
        cin.ignore();
        getline(cin, this->name);
        cout << "  Nhap diem Toan: ";
        cin >> this->math;
        cout << "  Nhap diem Van: ";
        cin >> this->literature;
    }
    else cout << "Lua chon khong hop le!";
}
void Student::display() {
    cout << "------------" << endl;
    cout << "Ho ten: " << this->name << endl;
    cout << "Diem toan: " << this->math << endl;
    cout << "Diem van: " << this->literature << endl;
    cout << "------------" << endl;
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

//Ham tinh toan xep loai 
float Student::avg() {
    return (math + literature) / 2;
}
void Student::type(Student s) {
    float dtb = s.avg();
    if (dtb >= 8.0)
        cout << "Gioi" << endl;
    else if (dtb >= 7.0) 
        cout << "Kha" << endl;
    else if (dtb >= 5.0) 
        cout << "Trung binh" << endl;
    else    
        cout << "Yeu" << endl;
}

Student::~Student() {
}

int main() {
    Student s, s1(s), s2;
    cout << "Nhap vao thong tin HS: " << endl;    
    s.setStudent();

    // C2: set Thong tin hoc sinh bang tung ham
    // cout << "Nhap vao thong tin HS: " << endl; 
    // string name;
    // float math, literature;
    // cout << "Ten: ";
    //     cin.ignore();
    //     getline(cin, name);
    //     s2.setName(name);
    // cout << "Diem Toan: ";
    //     cin >> math;
    //     s2.setMath(math);
    // cout << "Diem Van: ";
    //     cin >> literature;
    //     s2.setMath(literature);

    s.display();
    // C2: Output bang tung ham 
    // cout << "Ten: " << s.getName() << endl;
    // cout << "Diem Toan: " << s.getMath() << endl;
    // cout << "Diem Van: " << s.getLiterature() << endl;

    cout << "Diem trung binh: " << s.avg() << endl;
    cout << "Xep loai: ";
    s.type(s);
    return 0;
}