#include<iostream>
#include<math.h>
#include "DynamicArray.h"
using namespace std;

D_Array::D_Array(int size, int a[]) {
    this->size = size;
    for (int i = 0; i < size; i++) {
        this->arr[i] = a[i];
    }
}
D_Array::D_Array(const D_Array &a) {
    this->size = a.size;
    arr = new int [size];
    for (int i = 0; i < size; i++) {
        this->arr[i] = a.arr[i];
    }
}

//Ham nhap xuat
void D_Array::Init() {
    cout << "Nhap mang: " << endl;
    cout << "1. Khong nhap (mang mac dinh)" << endl;
    cout << "2. Nhap chi tiet cac gia tri cua mang" << endl;
    cout << "Nhap lua chon: ";
    int option; 
    cin >> option;
    if (option == 1);
    if (option == 2) {
        cout << "\nNhap kich thuoc mang: ";
        cin >> this->size;
        for (int i = 0; i < this->size; i++) {
            cout << "array[" << i << "] = ";
            cin >> arr[i];
        }
    }
}
void D_Array::Out() {
    cout << "array[] = ";
    for (int i = 0; i < this->size; i++) {
        cout << arr[i] << " ";
    }
}

//Ham get - set gia tri
int D_Array::getSize() {
    return this->size;
}
int D_Array::getIndexValue(int index) {
    for(int i = 0; i < this->size; i++) {
        if (i == index) return arr[i];
    }
    return -1;
}
void D_Array::setIndexValue(int index) {
    int value;
    cout << "Nhap gia tri muon thay doi: ";
    cin >> value;
    for(int i = 0; i < this->size; i++) {
        if (i == index) 
            this->arr[i] = value;
    }
}

//Cac ham tinh toan
void D_Array::swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void D_Array::ascenBubbleSort() {
    for (int i = 0; i <= size - 1; i++) {
        for (int j = size - 1; j >= i; j--) {
            if (arr[j - 1] > arr[j])
                swap(&arr[j - 1], &arr[j]);
        }
    }
}
void D_Array::descenSort() {
    cout << "array[] = ";
    for (int i = size - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
}
int D_Array::binarySearch(int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(left, mid - 1, x);
        return binarySearch(mid + 1, right, x);
    }
    return -1;
}
int main() {
    D_Array a;   
    int i, x, check; 
    a.Init();
    a.Out();
    cout << "\n----------";
    cout << "\n- Kich thuoc mang: " << a.getSize(); 
    cout << "\n- Sap xep tang dan: ";
        a.ascenBubbleSort();
        a.Out();
    cout << "\n- Sap xep giam dan: ";
        a.descenSort();
    cout << "\n- Kiem tra gia tri x co ton tai trong mang khong: ";
        cout << "\n\tNhap gia tri x: ";
        cin >> x;
        check = a.binarySearch(0, a.getSize() - 1, x);
        if (check == -1) cout << "=> Khong ton tai gia tri !";
        else cout << "=> Gia tri x co trong mang a!";
    cout << "\n- Nhap vi tri can lay gia tri: ";
        cin >> i; 
    cout << "=> Gia tri tai " << i << " = " << a.getIndexValue(i - 1);
    cout << "\n- Nhap vi tri can thay doi gia tri: "; 
        cin >> i;
    a.setIndexValue(i - 1);
    a.Out();
}