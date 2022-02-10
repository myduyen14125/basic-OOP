#include <iostream>
using namespace std;

void Init(int arr[], int arrLength);
void Out(int arr[], int arrLength);

void swap(int *x, int *y);
int compare(const void *a, const void *b);
void outDescending(int arr[], int size);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertSort(int arr[], int n);
void HeapSort(int arr[], int n, int i);

int binarySearch(int arr[], int left, int right, int x);
int linearSearch(int x, int arr[], int arrLength);

int main()
{
    int arrLength;
    cout << "Nhap do dai mang: ";
    cin >> arrLength;
    int *arr = new int[arrLength];

    Init(arr, arrLength);
    cout << "\n-----------------" << endl;
    Out(arr, arrLength);
    cout << "\n-----------------" << endl;
    qsort(arr, arrLength, sizeof(int), compare);
    // bubbleSort(arr, arrLength);
    // selectionSort(arr, arrLength);
    // insertSort(arr, arrLength);

    cout << "\nMang duoc sap xep tang dan:" << endl;
    Out(arr, arrLength);
    cout << "\nMang duoc sap xep giam dan:" << endl;
    outDescending(arr, arrLength);
    cout << "\n----------------" << endl;
    int x;
    cout << "Nhap phan tu x can tim: ";
    cin >> x;
    int resSearch = binarySearch(arr, 0, arrLength - 1, x);
    if (resSearch == -1)
    {
        cout << "\nKhong tim thay " << x << " trong array!" << endl;
    }
    else
        cout << "\nTim thay x trong mang !" << endl;
    return 0;

    delete[] arr;
    return 0;
}

void Init(int arr[], int arrLength)
{
    cout << "\nNhap mang: " << endl;
    for (int i = 0; i < arrLength; i++)
    {
        cout << "array[" << i << "] = ";
        cin >> arr[i];
    }
}
void Out(int arr[], int arrLength)
{
    cout << "array[] = ";
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
//Sort algorithms
//Compare for qsort algo
int compare(const void *a, const void *b)
{
    const int *x = (int *)a;
    const int *y = (int *)b;
    if (*x > *y)
        return 1;
    else if (*x < *y)
        return -1;
    return 0;
}
//Ham in giam dan
void outDescending(int arr[], int arrLength)
{
    int i;
    cout << "array[] = ";
    for (i = arrLength - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
}
void bubbleSort(int arr[], int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = n; j >= i + 1; j--)
        {
            if (arr[j - 1] > arr[j])
                swap(&arr[j - 1], &arr[j]);
        }
    }
}
void selectionSort(int arr[], int n)
{
    int position;
    for (int i = 1; i <= n - 1; i++)
    {
        position = i;
        for (int j = i + 1; j <= n; j++)
        {
            if (arr[position] > arr[j])
                position = j; //Find min tu i+1 den n
        }
        swap(&arr[i], &arr[position]);
    }
}
void insertSort(int arr[], int n)
{
    int x;
    int j;
    for (int i = 2; i <= n; i++)
    {
        x = arr[i];
        j = i - 1;
        while (j >= 1 && x < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}
void HeapSort(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        HeapSort(arr, n, largest);
    }
}
//Search algorithms
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

int linearSearch(int x, int arr[], int arrLength)
{
    int i = 1;
    while (i < arrLength && arr[i] != x)
        i = i + 1;
    return (i);
}
