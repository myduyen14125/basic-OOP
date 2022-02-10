#include <string>
#include <iostream>
using namespace std;
#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
    private:
        int size;
        int** data = NULL;
    public:
        Matrix() {
            this->size = 0;
            data = new int *[0];
        };
        Matrix(int size); 
        Matrix(int Init[], int size);
        Matrix(const Matrix &x);
        ~Matrix();

        friend ostream &operator << (ostream &out, const Matrix &a);
        friend istream &operator >> (istream &in, Matrix &a);
        
        Matrix operator + (Matrix a);
	    Matrix operator - (Matrix a);
	    Matrix operator * (Matrix a);
        
        const Matrix &operator = (Matrix a);
        int operator () (int a, int b);
	    operator int(); // ep kieu
        
};

#endif