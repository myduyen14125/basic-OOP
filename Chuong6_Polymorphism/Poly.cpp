#include<string.h>
#include<iostream>
#include<iomanip>
#include "Poly.h"
using namespace std;

plot::plot(string id, int price) : id(id), price(price){
}
void plot::Display() {
    cout << "\n\t Diện tích: " << area();
    cout << "\n\t Giá tiền : " << sumPrice();
}
//Hình chữ nhật 
int rectangle::area() {
    return length * width;
}
int rectangle::sumPrice() {
    return price * area();
}
void rectangle::Display()  {
    cout << "\nHình chữ nhật: ";
    plot::Display();
}

//Hình thang 
int trapezoid::area() {
    return (length + width) * height / 2;
}
int trapezoid::sumPrice() {
    return price * area() * 0.1;
}
void trapezoid::Display()  {
    cout << "\nHình thang: ";
    plot::Display();
}

//Hình tam giác 
int triangle::area() {
    return length * width / 2;
}
int triangle::sumPrice() {
    return price * area() * 0.1;
}
void triangle::Display()  {
    cout << "\nHình tam giác: ";
    plot::Display();
}

int main() {
	plot *p[100];
	int n = 0, price, a, b, c, sumArea, sumPrice; 
    string id;  
	char type, check;
	do {
		cout<<"\nNhập mã số miếng đất:"; 
        cin >> id;
        cout << "\nNhập đơn giá 1m2: "; 
        cin >> price;
		cout<<"\nMảnh đất hình gì? Chữ nhật (C)/Thang (H)/ Tam giác (T)";
        cin>>type;
		type = toupper(type);
		switch (type){
			case 'C': 
            {
                cout << "\nNhập chiều dài, chiều rộng: ";
                cin >> a >> b;
                p[n++] = new rectangle(id, price, a, b);
                break;
            } 
            case 'H': 
            {
                cout << "\nNhập 2 đáy, chiều cao: ";
                cin >> a, b, c;
                p[n++] = new trapezoid(id, price, a, b, c);
                break;
            } 
            case 'T': 
            {
                cout << "\nNhập đáy, chiều cao: ";
                cin >> a, b;
                p[n++] = new triangle(id, price, a, b);
            } 
		}
		cout<<"Bạn iu nhập nữa hong ? (C/K)"; 
        cin.ignore();
        cin >> check;
		check = toupper(check);
		if (n == 3 || check == 'K') {
            break;
        }
	} while (1);
	cout <<"Diện tích, giá tiền của các mảnh đất:"<<endl;
	for (int i = 0; i < n; i++)
		 p[i]->Display();	
	return 0;
}