#include <iostream>
#include <iomanip>
using namespace std;

void input(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

void output(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
bool ascending(int left, int right)
{
    return left > right;
}
bool descending(int left, int right)
{
    return left < right;
}

void selectionSort(int a[], int n, bool (*CompFunc)(int, int) = ascending)
{
    int i, j, position;

    for (i = 0; i < n - 1; i++)
    {
        position = i;
        for (j = i + 1; j < n; j++)
        {
            if ((*CompFunc)(a[position], a[j]))
                position = j;
        }
        swap(a[position], a[i]);
    }
}
void bubbleSort(int a[], int n, bool (*CompFunc)(int, int) = ascending)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if ((*CompFunc)(a[j], a[j + 1]))
                swap(a[j], a[j + 1]);
        }
    }
}
void insertionSort(int a[], int n, bool (*CompFunc)(int , int)= ascending){
    int x, j;
    for (int i = 1; i < n; i++) {
        x = a[i];
        j = i - 1;
        while (j >= 0 && (*CompFunc)(a[j],x)) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = x;
    }
}
int binarySearch(int array[], int left, int right, int x)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;

        if (array[mid] == x)
            return mid;

        if (array[mid] > x)
            return binarySearch(array, left, mid - 1, x);

        return binarySearch(array, mid + 1, right, x);
    }

    return -1;
}
int main()
{
    int n;
    cout << "Nhap so phan tu cua mang a: ";
    cin >> n;
    int *a = new int[n];
    cout << "Nhap mang a: " << endl;
    input(a, n);
    cout << "---------";
    cout << "\nSap xep theo thu tu tang dan: " << endl;
    selectionSort(a, n, ascending);
    output(a, n);
    int *temp = new int[n];
    temp = a;
    cout << "\nSap xep theo thu tu giam dan: " << endl;
    bubbleSort(a, n, descending);
    output(a, n);
    int x;
    cout << "Nhap phan tu x can tim: ";
    cin >> x;
    int resSearch = binarySearch(temp, 0, n - 1, x);
    if (resSearch == -1)
    {
        cout << "\nKhong tim thay " << x << " trong array!" << endl;
    }
    else
        cout << "\nTim thay x trong mang !" << endl;
    return 0;

    delete[] a;
    return 0;
}