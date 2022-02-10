#include <iostream>
#include<math.h>
using namespace std;

class Hinh
{
protected:
    double length; 
    double area;

public:
    Hinh(double length):length(length){};
    virtual double getLength() { return length; }
    virtual double getArea() { return area; } //tinh dien tich
    void display() {}
};

class Hinh2d : public Hinh
{
protected:
    double perimeter;

public:
    Hinh2d(double length):Hinh(length){};
    double getPerimeter() { return perimeter; } //Lay chu vi
};

class Hinhtron : public Hinh2d
{
public:
    Hinhtron(double radius = 0):Hinh2d(length) //Ban kinh = radius
    {
        length = radius;
        area = 3.14 * length * length;
        perimeter = 3.14 * 2 * length;
    }
};

class Hinhvuong : public Hinh2d
{
public:
    Hinhvuong(double aEdge = 0):Hinh2d(length) //canh a
    {
        length = aEdge;
        area = length * length;
        perimeter = 4 * length;
    }
};

class Tamgiac : public Hinh2d
{
public:
    Tamgiac(double aEdge = 0):Hinh2d(length)
    {
        length = aEdge;
        area = sqrt(3)/4 * length * length; 
        perimeter = 3 * length;
    }
};

class Hinh3d : public Hinh
{
protected:
    double volume;

public:
    Hinh3d(double length):Hinh(length){};
    double getVolume() { return volume; }; //Lay the tich
};

class Lapphuong : public Hinh3d
{
public:
    Lapphuong(double aEdge = 0):Hinh3d(length)
    {
        length = aEdge;
        area = 6 * length * length;
        volume = length * length * length;
    }
};

class Hinhcau : public Hinh3d
{
public:
    Hinhcau(double radius = 0):Hinh3d(length)
    {
        length = radius;
        area = 4 * 3.14 * length * length;
        volume = 4.0 / 3 * 3.14 * length * length * length;
    }
};

int main()
{    
    Hinh *H[100];
	int N=0;
	char Chon;
    int type;
	double length;
	do
	{
		cout<<"Nhap do dai canh a:";
		cin>> length;
		cout<<"Hinh 2D hay 3D? (2/3) ";
		cin>>type;
		if (type=='2')
		{
            cout << "----Chon hinh----" << endl;
            cout << "1. Hinh Tron" << endl;
            cout << "2. Hinh Vuong" << endl;
            cout << "3. Hinh Tam Giac" << endl;
            cout << "-----------------" << endl;
			H[N++]=new Hinh2d(length);
		}
		if (type=='3')
		{
            cout << "----Chon hinh----" << endl;
            cout << "1. Hinh Lap Phuong" << endl;
            cout << "2. Hinh Cau" << endl;
            cout << "-----------------" << endl;
			H[N++]=new Hinh3d(length);
		}
        else {
            cout << "khong hop le" << endl;
            break;
        }
		cout<<"Tiep tuc (C/K)? ";
		cin>>Chon;
		Chon=toupper(Chon);
		if ((N==100)||(Chon=='K'))
			break;
	}
	while (1);
	cout<<"Danh sach Hinh:"<<endl;
	for(int I=0;I<N;++I)
	if (H[I]->getArea())
			H[I]->display();
	cout<<endl;
	return 1;

    return 0;
}