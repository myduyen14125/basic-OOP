#include<string.h>
#include<iostream>
using namespace std;

#ifndef POLY_H
#define POLY_H

class plot {
    protected:
        string id;
        int price;
    public: 
        plot(string id, int price);
        virtual ~plot(){}
        virtual int area() = 0;
        virtual int sumPrice() = 0;
        virtual void Display();
};
//Hình chữ nhật
class rectangle : public plot {
    protected: 
        int length, width;
    public: 
        rectangle(string id, int price, int length, int width) : plot(id, price){
            this->length = length;
            this->width = width;
        };
        int area();
        int sumPrice();
        void Display();
};
//Hình thang 
class trapezoid : public plot {
    protected: 
        int length, width, height;
    public: 
        trapezoid(string id, int price, int length, int width, int height) : plot(id, price){
            this->length = length;
            this->width = width;
            this->height = height;
        };
        int area();
        int sumPrice();
        void Display();
};
//Hình tam giác
class triangle : public plot {
    protected: 
        int length, width;
    public: 
        triangle(string id, int price, int length, int width) : plot(id, price){
            this->length = length;
            this->width = width;
        };
        int area();
        int sumPrice();
        void Display();
};
#endif
