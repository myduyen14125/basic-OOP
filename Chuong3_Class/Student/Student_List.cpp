#include<iostream>
#include<math.h>
#include<iomanip>
#include "Student_List.h"
#include "Student.h"
using namespace std;

List::List(int n):size(n) {
    data = new Student[size];
}
List::List(const List &l):size(l.size) {
    data = new Student[size]; 
    for(int i = 0; i < size; i++) {
        data[i] = l.data[i];
    }
}
void List::Input() {
    for(int i = 0; i < size; i++) {
        cout << "Nhap hoc sinh thu " << i << " : " << endl;
        data[i].setStudent();
    }
}
void List::Output() const {

}