#include <iostream>
using namespace std;

template <typename T>
void input(T a[], int n){
    for(int i = 0; i < n; i++){
        cout<<"Phan tu thu "<<i<<":";
        cin >> a[i];
    }
}
template <typename T>
void output(T a[], int n) {
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
template <typename T>
bool ascending(T l, T r){
    return l > r;
}
template <typename T>
bool descending(T l, T r){
    return l < r;
}
template <typename T>
void swap(int &num1, int &num2){
    T temp = num1;
    num1 = num2;
    num2 = temp;
}
template <typename T>
void selectionSort(T arr[], int n, bool (*func_ptr)(T, T)=ascending){
    int i, j, min_idx;
 
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++){
            if((*func_ptr)(arr[min_idx],arr[j]))
                min_idx = j;
        }
 
        swap(arr[min_idx], arr[i]);
    }
}
template <typename T>
void bubbleSort(T arr[], int n, bool (*func_ptr)(T, T) =ascending){
    int i, j;
    for (i = 0; i < n-1; i++){         
       for (j = 0; j < n-i-1; j++){
           if ((*func_ptr)(arr[j], arr[j + 1]))
              swap(arr[j], arr[j+1]);
       }
    }
}
template <typename T>
void insertionSort(T arr[], int n, bool (*func_ptr)(int , int)=ascending){
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && (*func_ptr)(arr[j],key)) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
template <typename T>
int partition (T arr[], int low, int high, bool (*func_ptr)(int , int)){ 
    int pivot = arr[high]; // pivot 
    int i = low - 1;
  
    for (int j = low; j <= high - 1; j++) 
    { 
        if ((*func_ptr)(arr[j],pivot)) 
        { 
            i++;
            swap(arr[i], arr[j]); 
        } 
    } 
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
} 
template <typename T>
void quickSort(T arr[], int low, int high, bool (*func_ptr)(T, T)=ascending) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high, func_ptr); 
  
        quickSort(arr, low, pi - 1, func_ptr); 
        quickSort(arr, pi + 1, high, func_ptr); 
    } 
} 
template <typename T>
void quickSortUtility(T a[], int n, bool (*func_ptr)(int , int)=ascending){
    quickSort(a, 0, n - 1, func_ptr);
}
template <typename T>
void sorting(void (*func_ptr)(T*, T, bool (*func)(T, T)), T a[], int n, bool (*f)(T, T)=ascending){
    (*func_ptr)(a,n,f);
}
template <typename T>
int search(T a[], int n, int x){
    for(int i = 0; i < n; i++)
        if(a[i] == x)
            return i;
    return -1;
}

int main(){
    int n;
    cout<<"Nhập số phần tử của mảng:"; cin >> n;
    int *a = new int[n];
    cout<<"Nhập mảng a:"<<endl;
    input(a,n);
    cout<<"Mảng vừa nhập:";
    output(a,n);
    cout<<"Mảng theo thứ tự tăng dần sx bằng pp selectionSort:"<<endl;
    sorting(selectionSort, a,n);
    output(a,n);
    cout<<"Mảng theo thứ tự giảm dần sx bằng pp bubbleSort:"<<endl;
    sorting(bubbleSort, a, n, descending);
    output(a,n);
    cout<<"Mảng theo thứ tự tăng dần sx bằng pp quickSort:"<<endl;
    sorting(quickSortUtility,a,n,ascending);
    output(a,n);
    cout<<"Mảng theo thứ tự giảm dần sx bằng pp insertionSort:"<<endl;  
    sorting(insertionSort,a,n,descending);
    output(a,n);
    
    cout << search(a,n,2);

    return 0;
}