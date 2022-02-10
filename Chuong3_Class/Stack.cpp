#include<iostream>
using namespace std;

#include "Stack.h" 

Stack::Stack(int n) {
    size = n;
    data = new int [n];
    top = -1;
}
Stack::Stack(const Stack &x) {
    this->size = x.size;
    this->top = x.top;
    //Data = x.data //sao chép nông nè 
    data = new int [size]; //sao chép sâu
    for(int i = 0; i <= top; i++) 
        this->data[i] = x.data[i];
}
bool Stack::Push(int x) {
    if (!isFull()) data[++top] = x; 
    else return false;
    return true;
}; 
bool Stack::Pop(int &x) {
    if (!isEmpty()) x = data[top--];  
    else return false;
    return true;
}; 
bool Stack::isFull() {
    return top == (size - 1);
}; 
bool Stack::isEmpty() {
    return (top == -1);
};