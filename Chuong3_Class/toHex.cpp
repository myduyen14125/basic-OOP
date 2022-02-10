#include<iostream>
using namespace std;
#include "Stack.h"
#include "Stack.cpp"

int main() {
    Stack S(8);
    int n; 
    cout << "Nhap so thap phan can doi :";
    cin >> n;  
    do {
        S.Push(n % 16);
        n /= 16;
    } while (n != 0 && !S.isFull());
    int x;
    char HEX[] = "0123456789ABCDEF";

    Stack S1 = S;
    while (!S.isEmpty()) {
        S.Pop(x);
        cout << HEX[x];
    }
    return 0;
}