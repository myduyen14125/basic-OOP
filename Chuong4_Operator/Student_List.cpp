#include<iostream>
#include<math.h>
#include<string>
#include<fstream>
#include "Student_List.h"
#include "Student.h"
using namespace std;

//functions with class node. 
void node::setData(Student data) {
    this->data = data;
}
Student node::getData() {
    return data;
}
void node::setNext(Node next) {
    this->next = next;
}
Node node::getNext() {
    return next;
}
void node::print() {
    cout << getData() << endl;
}

//functions with linkedlist
linkedlist::linkedlist (const linkedlist &l) : size(l.size) {
    Node p = new node ();
    for (Node copy = l.head; copy != NULL; copy = copy->next) {
        p->data = copy->data;
    }

}
linkedlist::~linkedlist() { //release list 
    Node k = NULL; 
    while (head != NULL) {
        k = head; 
        head = head->next;
        delete(k);
    }
} 

void linkedlist::setTail(Node tail) {
    this->tail = tail;
}
int linkedlist::getSize() {
    return size;
}
void linkedlist::display() {
    int count = 1;
    for (Node k = head; k != NULL; k = k->next) {
        cout << "\n\t Sinh vien thu " << count++ << endl;
        cout << k->data; //goi den << 1 SV
    }
}
// ostream &operator << (ostream &out, const linkedlist &l) {
//     int count = 1;
//     for (Node k = l.head; k != NULL; k = k->next) { //How to accessible 2 layer/
//         cout << "\n\t Sinh vien thu " << count++ << endl;
//         cout << k->data; //goi den << 1 SV
//     }
// }


linkedlist linkedlist::operator + (Node p) {//add to to last 
    if (head == NULL) {
        head = tail = p;
    }
    else {
        tail->next = p; 
        tail = p;
    }
} 
linkedlist linkedlist::operator - (Node s) {//delete node bat ki
    if (head == NULL) return; 

    Node g = new node();
    for (Node k = head; k != NULL; k = k->next) {
        if (k->data == s->data) {
            k->next = g->next; 
            delete(k);
        }
        g = k; // g la node truoc k 
    }

} 
const linkedlist &linkedlist::operator = (linkedlist l) {
    this->size = l.size;
    for (Node k = head; k != NULL; k = k->next) {
         
    }
}
Node linkedlist::operator () (int index) {
    if (index < 0 || index > size)
        return NULL; 
    Node temp = head; 
    for (int i = 0; i < index; i++) {
        temp = temp->getNext();
    } 
    return temp;
}



int main() {
    Linkedlist l = new linkedlist ();

    while(1) {
        Student s;
        cout << "Nhap vao thong tin HS: " << endl; 
        cin >> s;
        bool option;
        cout << "\nBan co nhap tiep khong?\t0.Khong\t1.Co";
        cin >> option;
        if (option == 0) break; 
    }
    cout << "\n-------------";
    cout << "\nDanh sach hoc sinh: " << endl; 
    l->display();
    cout << "\nThem hoc sinh vao cuoi danh sach: ";
    Student s1;
    cin >> s1;
    Node p = new node();
    p->getData() = s1;
    l = l + p; 
    
}
