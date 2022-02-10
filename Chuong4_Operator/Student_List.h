#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H
#include "Student.h"

typedef class node *Node;
class node {
    private:
        Student data;
        Node next;
    public: 
        node() { //constructor1, create a node 
            this->next = NULL;
        };
        node(Student data) {//con2,create a note
            this->data = data;
            this->next = NULL;
        }
        void setData(Student data);
        Student getData();
        void setNext(Node next);
        Node getNext();
        void print();
        friend ostream &operator << (ostream &out, const linkedlist &a);
        friend class linkedlist;
};

typedef class linkedlist* Linkedlist;
class linkedlist {
    private: 
        Node head; 
        Node tail; 
        int size;
    public:  
        linkedlist() { //constructor empty linkedlist, create list 
            head = NULL;
            tail = NULL; 
            size = 0; 
        }
        linkedlist(const linkedlist &l);
        ~linkedlist(); 

        void createList();
        void setTail(Node tail);
        int getSize();
        void display(); //putput list SV

        //Operator
        linkedlist operator + (Node s); //add Node contains student.
        linkedlist operator - (Node s); 
        const linkedlist &operator = (linkedlist a);
        Node operator () (int index); //get a node

        friend ostream &operator << (ostream &out, const linkedlist &a);
        friend class node;
};

#endif