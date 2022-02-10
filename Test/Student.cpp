#include<iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student {
    private:
        string name;
        float math;
        float literature;
        float avg;
        string type;
    public: 
        Student() { 
            name = "Nguyen Tran My Duyen";
            math = 0.0;
            literature = 0.0;
        } //Constructor default 
        Student(string); //Constructor 1 tham so name
        Student(string, float, float); //constructor full info
        Student(const Student &); //Tham chieu, sao chep tu so phuc khac
        ~Student();

        void setStudent(); //Nhap HS
        void display(); //Xuat
        
        void setName(string); 
        void setMath(float); 
        void setLiterature(float);
        string getName(); 
        float getMath(); 
        float getLiterature();
        bool checkScore(const Student &s);

};

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
void Student::setStudent() {
    cout << "  Nhap ho ten: ";
    getline(cin, this->name);
    cout << "  Nhap diem Toan: ";
    cin >> this->math;
    cout << "  Nhap diem Van: ";
    cin >> this->literature;
    avg = (math + literature) / 2;
    type = (avg < 5) ? "Yeu" : (avg < 6.5) ? "Trung binh" : (avg < 8) ? "Kha" : "Gioi";
}

void Student::display() {
    cout << "------------" << endl;
    cout << "Ho ten   : " << this->name << endl;
    cout << "Diem toan: " << this->math << endl;
    cout << "Diem van : " << this->literature << endl;
    cout << "Diem TB  : " << this->avg << endl;
    cout << "Xep loai : " << this->type << endl;
    cout << "------------" << endl;
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


Student::~Student() {
    cout << "\ndelete";
}

int main() {
    Student s1;
    cout << "Nhap vao thong tin HS: " << endl; 
    s1.setStudent();
    cout << "Hoc sinh 1: "  << endl;
        s1.display();  
    Student s2 = s1;
    cout << "Hoc sinh 2: "  << endl;  
        s2.display(); 
    Student s3("Nguyen An", 10, 7);
    cout << "Hoc sinh 3: "  << endl;
        s3.display();   
    return 0;
}