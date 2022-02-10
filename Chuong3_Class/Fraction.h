#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
    private:
        int tuso;
        int mauso;
    public: 
        Fraction() { 
            tuso = 0;
            mauso = 1;
        } //Constructor default = 0
        Fraction(int); //Constructor Truyen 1 tham so - Khoi tao tu gia tri nguyen
        Fraction(int, int); //Constructor Truyen 2 tham so
        Fraction(const Fraction &fr); //Tham chieu, sao chep tu phan so khac

        void setFraction(); //Set phan so
        void display(); //Xuat
        
        int getNumerator(); //Lay tu so 
        int getDenumerator(); //Lay mau so  
        void setNumerator(int);
        void setDenumerator(int);

        //Phep toan tren phan so
        void inverse(); //Nghich dao Phan so
        void reduceFrac(); //Rut gon phan so 
        void addFrac(Fraction fr); //Cong 2 phan so
        void subFrac(Fraction fr); //Tru phan so
        void mulFrac(Fraction fr); //Nhan 2 phan so
        void divFrac(Fraction fr); //Chia 2 phan so
        void compareFrac(Fraction fr);

};

#endif