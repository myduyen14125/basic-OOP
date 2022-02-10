#include <iostream>
#include <string>
#include "Matrix.h"

using namespace std;

Matrix::Matrix(int size) { //constructor 2
    this->size = size;
    data = new int *[size];
    // Cap phat dong - khoi tao cac hang
    for (int i = 0; i < size; i++) {
        data[i] = new int[size];
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            data[i][j] = 0;
        }
    }
}
Matrix::Matrix(int Init[], int size) { //constructor 3
    this->size = size;
    data = new int *[size];
    for (int i = 0; i < size; i++) {
        data[i] = new int[size];
    }

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            data[i][j] = Init[i]; //Khoi tao gia tri
        }
}

Matrix::Matrix(const Matrix &x) : size(x.size) {
    data = new int *[size];
    for (int i = 0; i < size; i++)
        data[i] = new int[size];
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            data[i][j] = x.data[i][j];
        }
}

Matrix::~Matrix() { // hủy 1 mảng hai chiều được cấp phát động
    for (int i = 0; i < this->size; i++)
        delete[] data[i];
    delete[] data;
}

//Ham nhap xuat 
ostream &operator << (ostream &out, const Matrix &a) {
    for (int i = 0; i < a.size; i++) {
        for (int j = 0; j < a.size; j++) {
            cout << "[" << i << "][" << j << "] = " << a.data[i][j] << "  ";
        }
        cout << endl;
    }
    return out;
}
istream &operator >> (istream &in, Matrix &a) {
    for (int i = 0; i < a.size; i++) {
        for (int j = 0; j < a.size; j++) {
            cout << "[" << i << "][" << j << "] = ";
            cin >> a.data[i][j];
        }
    }
    return in;
}

//Operator 
Matrix Matrix::operator + (Matrix a) {
    Matrix result(a.size); //tạo matrix nhận kết quả với size = size a
    if (a.size != this->size)
        return *this;
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            result.data[i][j] = data[i][j] + a.data[i][j];
        }
    }
    return result;
}
Matrix Matrix::operator - (Matrix a) {
    Matrix result(a.size); //tạo matrix nhận kết quả với size = size a
    if (a.size != this->size)
        return *this;
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            result.data[i][j] = data[i][j] - a.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator * (Matrix a) {
    Matrix result(*this);
    if (a.size != size)
        return result;
    for (int i = 0; i < size; i++)
        for (int k = 0; k < size; k++) {
            result.data[i][k] = 0;
            for (int j = 0; j < size; j++)
                result.data[i][k] = result.data[i][k] + a.data[i][j] * data[j][k];
        }
    return result;
}

const Matrix &Matrix::operator = (Matrix a) {
    this->size = a.size;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            data[i][j] = a.data[i][j];
    return *this;
}

int Matrix::operator () (int a, int b) {
    return data[a][b];
}

Matrix::operator int() {
    int i, j, k, count = 0, kt = 0;
    int b[100], h, det = 1, c[100];
    for (i = 0; i < size - 1; i++) {
        if (data[i][i] == 0) {
            kt = 0;
            for (j = 0; j < size; j++) {
                if (data[i][j] != 0) {
                    for (k = 0; k < size; k++) {
                        c[k] = data[k][i];
                        data[k][i] = data[k][j];
                        data[k][j] = c[k];
                    }
                    count++;
                    kt++;
                    break;
                }
            }   
        }
        if (kt == 0)
            return 0;
        b[i] = data[i][i];
        for (j = 0; j < size; j++) {
            data[i][j] = data[i][j] / b[i];
        }
        for (j = i + 1; j < size; j++) {
            h = data[j][i];
            for (k = 0; k < size; k++)
                data[j][k] = data[j][k] - h * data[i][k];
        }
    }
    b[size - 1] = data[size - 1][size - 1];
    for (i = 0; i < size; i++)
        det = det * b[i];
    int dinhthuc;
    if (count % 2 == 0)
        dinhthuc = (int)det;
    else
        dinhthuc = -(int)det;
    return dinhthuc;
}


int main () {
    int n;
    cout << "Nhap kich thuoc ma tran A: "; 
        cin >> n;
        cout << "Nhap ma tran A:" << endl;
        Matrix a(n); cin >> a;
    cout << "\n---------" << endl;
        cout << a;
    cout << "\n---------" << endl;
    cout << "Nhap kich thuoc ma tran B: ";
        cin >> n;
        cout << "Nhap ma tran B: " << endl;
        Matrix b(n); Matrix c(n);
    cin >> b;
    cout << "---------" << endl;
        cout << b;
    cout << "---------" << endl;
    cout << "\nA + B" << endl;
    c = a + b;
    cout << c;
    cout << "\nA - B" << endl;
    c = a - b;
    cout << c;
    cout << "\nA * B" << endl;
    c = a * b;
    cout << c;
    cout << "\nDung phep gan ma tran C=B "<<endl;
    c = b;
    cout << c;
    cout << "\nDung toan tu lay phan tu () : ";
    cout << c(0, 0) << endl;
    cout << "\nDinh thuc A : " << (int)a << endl;
    
}