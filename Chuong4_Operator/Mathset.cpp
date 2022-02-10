#include <iostream>
#include <math.h>
#include "Mathset.h"
using namespace std;

Mathset::Mathset () {
    size = 0;
}

Mathset::Mathset(int a[], int n) {
    size = n;
    data = new int[size];
    for (int i = 0; i<size; i++) 
        data[i] = a[i];
}

Mathset :: Mathset(const Mathset &a) {
    size = a.size;
    data = new int[size];
    for (int i = 0; i<size; i++) 
        data[i] = a.data[i];
}

Mathset Mathset:: operator* (const Mathset &a){
    int t[100];
    int k = 0; //bien luu chi so cua phan tu tap giao
    int check = 0;//bien kiem tra
    for (int i = 0; i<size; i++)
    {
        for (int j = 0; j< a.size; j++) 
        {
            if (data[i] == a.data[j]) 
            {
                check = 1;
                break;
            }
            check  = 0;
        }
        if (check){
            t[k++]=data[i];
        }
    }
    Mathset giao(t,k);
    return giao;
}

Mathset const &Mathset::operator = (const Mathset&a) {
    if (this!=&a){
        size =a.size;
        data = new int[size];
        for (int i = 0; i<size; i++) 
            data[i] = a.data[i];
    }
    return *this;
}

Mathset Mathset:: operator- (const Mathset &a){
    Mathset giao;
    giao = *this * a; 
    int t[100]; 
    int k = 0; 
    int check = 0; 
    for (int i = 0; i<size; i++) 
    {
       for (int j = 0; j<giao.size; j++) {
           if (data[i]==giao.data[i]) {
               check = 0;
               break;
           }
           check = 1;
       }
       if (check){
           t[k++] = data[i];
       }
    }
    Mathset hieu(t,k);
    return hieu;
}

Mathset Mathset:: operator+ (const Mathset &a){
    int check = 0;
    int t[100]; 
    int k = 0; 
    Mathset giao;
    giao = *this * a;
    for (k = 0; k<size; k++){
        t[k] = data[k];
    }
    for (int i = 0; i<a.size; i++){
        for (int j = 0; j<giao.size; j++){
            if (a.data[i] == giao.data[j]){
                 check = 0;
                 break;
            }
            check =1;
        }
        if (check) t[k++] = a.data[i]; 
    }
    Mathset tong(t,k);
    return tong;
}

Mathset Mathset::operator+ (int a) {
    Mathset newthis;
    newthis.size = size+1;
    newthis.data = new int [newthis.size];
    for (int i = 0; i<newthis.size-1; i++){
        newthis.data[i]=data[i];
    }
    newthis.data[newthis.size-1] = a;
    return newthis;
}

Mathset Mathset::operator- (int a) {
    Mathset newthis; 
    int k;
    newthis.size = size-1;
    newthis.data = new int [newthis.size];
    for (int i = 0; i<size; i++) 
    {
        if (data[i]==a) 
        {
            k=i;
            break;
        }
    }
    for (int i = 0; i<k; i++){
	newthis.data[i] = data[i];
    }	
    for (int i=k+1; i<size; i++){
	newthis.data[i-1] =data[i];
    }
    return newthis;
}

ostream &operator << (ostream &out, const Mathset &a) {
    cout << "Tap hop co cac phan tu: (";
    for (int i = 0; i<a.size; i++){
        out << a.data[i];
        if (i!= a.size-1) out << ", ";
    }
    out << ")";
    return out;
}

int &Mathset::operator [](int i) const {
    return this->data[i];
}

bool Mathset::operator ()(int x) {
    int check = 0;
    for (int i = 0; i<size; i++) 
    {
        if (data[i]==x) check=1;
        else check = 0;
    }
    return check;
}


int main() {
    int a[] = {1,2,3,4,5,6,7,8,9,10}; int b[]={5,4,3,2,1};
    Mathset A(a,7); Mathset B(b,6);
    cout << "A:" << A <<endl;
    cout << "B:" <<B << endl;
    cout << "A giao B"<< endl << A*B <<endl;
    cout << "A hop B"<<endl <<A+B <<endl;
    cout << "A hieu B" <<endl<< A-B <<endl;
    return 0;
}