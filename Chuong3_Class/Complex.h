#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
    private:
        double r;
        double i;
    public: 
        Complex() { 
            r = 0;
            i = 0;
        } //Constructor Default = 0
        Complex(int); //Constructor truyen 1 tham so r
        Complex(int, int); //Constructor Truyen 2 tham so
        Complex(const Complex &); //Tham chieu, sao chep tu so phuc khac

        void setComplex(); //Set so phuc
        void display(); //Xuat
        
        int getReal(); //Lay phan thuc 
        int getImaginary(); //Lay phan ao  
        void setReal(int);
        void setImaginary(int);

        //Phep toan tren so phuc
        double module();
        void add(Complex c); //Cong 2 so phuc
        void sub(Complex c); //Tru so phuc
        void mul(Complex c); //Nhan 2 so phuc
        void div(Complex c); //Chia 2 so phuc
        void compare(Complex c);
};

#endif