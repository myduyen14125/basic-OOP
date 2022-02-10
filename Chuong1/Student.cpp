#include<iostream>
using namespace std;

struct Student {
    char name[50];
    float math, literature;
};
istream &operator >> (istream &in, Student &A) {
    cout << "\tHo ten: "; 
    cin.ignore();
    in.getline(A.name, sizeof(A.name));
    cout << "\tDiem toan: ";
    in >> A.math;
    cout << "\tDiem van: ";
    in >> A.literature;
    return in;
    
}
ostream &operator << (ostream &out, Student &A) {
    out << "Name: " << A.name << endl;
    out << "Math grade: " << A.math << endl;
    out << "Literature grade: " << A.literature << endl;
    return out;
}
bool checkScore(Student &A) {
    if (A.math < 0 || A.math > 10 || A.literature < 0 || A.literature > 10) 
        return 0;
    return 1;
}
float average(Student &A) {
    return (A.math + A.literature) / 2;
}
void grading(Student &A) {
    float score = average(A);
    if (score >= 8.0) 
        cout << "Loai Gioi" << endl;
    else if (score >= 7.0) 
        cout << "Loai Kha" << endl;
    else if (score >= 5.0) 
        cout << "Loai Trung binh" << endl;
    else 
        cout << "Loai Yeu" << endl;
}
bool operator <(Student &A, Student &B) {
    if (average(A) < average(B)) 
        return 1;
    return 0;
}
bool operator >(Student &A, Student &B) {
    if (average(A) > average(B)) 
        return 1;
    return 0;
}
bool operator ==(Student &A, Student &B) {
    if (average(A) == average(B)) 
        return 1;
    return 0;
}
int main() {
    Student A, B;
    cout << "Nhap vao hoc sinh A: " << endl;
    cin >> A;
    cout  << "------" << endl;
    cout << "Nhap vao hoc sinh B: " << endl;
    cin >> B;
    cout  << "------" << endl;
    //Check student A
    if (checkScore(A) == 1) {
        cout << "Diem trung binh hoc sinh A: " << average(A) << " => ";
        grading(A);
    }
    else 
        cout << "Diem hoc sinh A khong hop le! ";
    //Check student B
    if (checkScore(B) == 1) {
        cout << "Diem trung binh hoc sinh B: " << average(B) << " => ";
        grading(B);
    }
    else 
        cout << "Diem hoc sinh B khong hop le! ";
    //Compare 2 students
    if (checkScore(A) == 1 && checkScore(B) == 1) {
        if (average(A) == average(B))
            cout << "\nHai hoc sinh co diem bang nhau";
        if (average(A) < average(B))
            cout << "\nHoc sinh A co diem thap hon B";
        if (average(A) > average(B))
            cout << "\nHoc sinh A co diem cao hon B";
    }
    else    
        cout << "\nKhong the so sanh vi co diem khong hop le!";
}