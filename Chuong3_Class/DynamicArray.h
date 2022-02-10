#include <iostream>
using namespace std;
#ifndef D_ARRAY_H
#define D_ARRAY_H

class D_Array {
    private:
        int size;
        int *arr = new int[size];
    public: 
        D_Array() { 
            size = 5;
            for (int i = 0; i < size; i++) {
                arr[i] = 0;
            }
        } //Constructor Default a[i] = 0, size = 5
        D_Array(int, int a[]); //Constructor 2
        D_Array(const D_Array &); 

        void Init(); 
        void Out(); 
        
        int getSize();
        int getIndexValue(int);
        void setIndexValue(int);

        void swap(int *x, int *y);
        int binarySearch(int left, int right, int x);
        void ascenBubbleSort();
        void descenSort();

        ~D_Array() {delete [] arr;};
};

#endif