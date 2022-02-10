#include <iostream>

using namespace std;
#include <string>

//Cau 1
// class Base
// {
// protected:
//     int prop;
//     /* data */
// public:
//     Base(int);
//     ~Base();
//     int getProp();
// };
// Base::Base(int prop) : prop(prop) { }
// Base::~Base(){ }
// int Base::getProp() {
//     return this->prop;
// }
// class Derived : public Base {
//     int prop;
// public:
//     Derived(int, int);
//     ~Derived();
//     void Func();
// };
// Derived::Derived(int x, int y) : Base(x), prop(y) { }
// Derived::~Derived() { }
// void Derived::Func() {
//     cout << this->prop;
// }
// int main() {
//     Derived obj(3, 4);//kq: 4, prop ăn theo y, x ăn theo base
//     obj.Func();
// }

/*-----------------DDAP AN = 4 ---------------------------*/
/*---------------------------------------------------------*/
//Cau 2
// template <typename T>
// T Max(T x, T y)
// {
//     return (x > y) ? x : y;
// }
// int main()
// {
//     cout << Max(3, 7) << Max(3.0, 7.0) << Max(3, 7.0);
// }
// template <class T>
// class Exam
// {
// public:
//     Exam();
//     ~Exam();
//     T Func1(T);
//     T Func2(T);
// };
// template <class T>
// Exam<T>::~Exam()
// {
// }
// template <class T>
// T Exam<T>::Func1(T x)
// {
//     return x;
// }
// template <class T>
// T Exam<T>::Func2(T x)
// {
//     return x;
// }
// int main()
// {
//     Exam<int> obj_i;
//     Exam<double> obj_d;
//     cout << obj_i.Func1(200) << obj_d.Func2(3.123);
// }



/*-----------------COMPILE ERROR ---------------------------*/
/*---------------------------------------------------------*/

//Cau 3
// template <class T>
// class Exam
// {
//     T prop;

// public:
//     Exam();
//     ~Exam();
// };
// template <class T>

// Exam<T>::Exam()
// {
// }
// template <class T>

// Exam<T>::~Exam()
// {
// }

// int main()
// {
//     Exam<char> obj_c;
//     Exam<int> obj_i;
//     Exam<double> obj_d;
//     cout << sizeof(obj_c) << sizeof(obj_i) << sizeof(obj_d);
// }
/*--------------------- 148 ---------------------------*/
/*---------------------------------------------------------*/

//Cau 4
// template <class T>
// void Func(T x)
// {
//     cout << x;
// }
// int main()
// {
//     double x = 5.5;
//     string str("IT");
//     Func(x);
//     Func(str);
// }

/*--------------------- 5.5IT ---------------------------*/
/*---------------------------------------------------------*/

//Cau 5
// class A{
//     public: void print();
// };
// void A::print(){
//     cout<<"A::print()";
// }
// class B : private A{
//     public :
//     void print();
// };
// void B::print(){
//     cout<<"B::print()";
// }
// class C:public B{
//     public: void print();
// };
// void C::print(){
//     A::print();
// }
// int main(){
//     C b;
//     system("pause");
//     b.print();
// }

/*---------------------------------------------*/
//Cau 6
// class Base {
//     int x, y, z;

// public:
//     Base() {
//         x = y = z = 0;
//     }
//     Base(int xx, int yy = 'A', int zz = 'B') {
//         x = xx;
//         y = x + yy;
//         z = x + y;
//     }
//     void Display() {
//         cout << x << y << z;
//     }
// };

// class Derived : public Base {
//     int x, y;

// public:
//     Derived(int xx = 65, int yy = 66) : Base(xx, yy) { //base nhận xx yy, không ảnh hưởng gì tới derived. 
//         y = xx;
//         x = yy;
//     }
//     void Display() {
//         cout << x << y; //6566
//     }
// };
// int main() {
//     Derived objD; //tạo objD xx yy
//     objD.Display();
//     system("pause");
//     return 0;
// }


//Cau 7
// #include <vector>
// int main()
// {
//     vector<int> v;
//     for (int i = 1; i <= 5; i++)
//         v.push_back(i);
//     vector<int>::const_iterator i;
//     i = v.begin(); 
//     *i = 3; //lỗi đây vì i là con trỏ -> com err, con trỏ phải gán với địa chỉ. 
//     for (int i = v.begin(); i != v.end(); ++i) //tương tự lỗi vì i là iterator
//     {
//         cout << *i << " ";
//     }
//     cout << endl;
//     return 0;
// }


//Cau 8
// class Base
// {
// public:
//     virtual void show() = 0;
// };
// int main()
// {
//     Base b; //comp err: base hàm thuần ảo
//     Base *bp;
// }
/*------------------------------*/

//Cau 9
// #include <exception>
// class Myexception : public exception
// {
//     virtual const char *what() const throw() //không lỗi 
//     {
//         return "My exception";
//     }
// } me;
// int main()
// {
//     try
//     {
//         throw me;
//     }
//     catch (exception &e)
//     {
//         cout << e.what(); //kq: my exception
//     }
// }

//Cau 10 
// int main()
// {
//     try
//     {
//         int *arr = new int[1000];
//         cout << "Allocated"; //Kq: allocated Đ
//     }
//     catch (exception &e)
//     {
//         cout << "Standard" << e.what();
//     }
// }


//Cau 11
// class Base
// {
//     int _x;

// public:
//     Base(int x)
//     {
//         _x = x;
//         cout << "A";
//     }
// };
// class Child : public Base
// {
//     int _y;
// public:
//     Child(int x, int y) : Base(x)
//     {
//         _y = y;
//         cout << "B";
//     }
// };
// int main()
// {
//     Child c1(1, 2);
//     Child c2; //comp err vì thiếu constructor child() Đ
//     c2 = c1;
//     return 0;
// }


//Cau 12 Note
// void Func(int x)
// {
//     int y;
//     y = 1;
//     while (true)
//     {
//         if (y >= x)
//             throw y ;
//         cout << y ; //kq: 123456.... 20 y>=x khi y = 20 thì throw y
//         y++;
//     }
// }
// int main()
// {
//     try
//     {
//         Func(20);
//     }
//     catch (int e)
//     {
//         cout << e; //cout y = 20 ở đây
//     }
// }


//Cau 13
// struct A
// {
//     int i;
//     char j;
//     float f;
//     void func();
// };
// void A::func() {}

// struct B
// {
// public:
//     int i;
//     char j;
//     float f;
//     void func();
// };

// void B::func() {}

// int main()
// {
//     A a;
//     B b;
//     a.i = b.i = 1;
//     a.j = b.j = 'c';
//     a.f = b.f = 3.14159;
//     a.func();
//     b.func();
//     cout << "Alocated"; //kq: allocated Đ
// }


//Cau 14
// struct A {
//     virtual void f()
//     {
//         cout << "A";
//     }
// };
// struct B : A {
//     virtual void f()
//     {
//         cout << "B";
//     }
// };
// struct C : A {
//     virtual void f()
//     {
//         cout << "C";
//     }
// };
// void f(A *arg) //truyền vô là con trỏ kiểu A, đúng ! 
// {
//     B *bp = dynamic_cast<B *>(arg); //downcast BC, chuyển con trỏ A * arg nớ về BC, được vì có virtual và có hàm f() giống nhau. 
//     C *cp = dynamic_cast<C *>(arg);
//     if (bp)
//         bp->f();
//     else if (cp)
//         cp->f(); // chạy 1 -> in C
//     else
//         arg->f(); //chạy 2 -> in A 
// }

// int main() {
//     A aobj;
//     C cobj;
//     A *ap = &cobj; //con trỏ kiểu A trỏ đến vật thuộc class C 
//     A *ap2 = &aobj; //................................... class A 
//     f(ap); //Kq: CA Đ 
//     f(ap2);
// }


//Cau 15
// template <typename T>
// inline T Func(T x)
// {
//     T result = x * x;
//     return result;
// };
// int main()
// {
//     int x, y;
//     float z, t;
//     double m, n;
//     x = 2;
//     z = 2.2;
//     m = 2.2;
//     y = Func(x);
//     n = Func(m);
//     cout << x << "x " << y << " y" << m << " m" << n << " n";//2 4 2.2 4.... chạy bthg
// }


//Cau 16 Note
// class Base {
// public:
//     virtual string print() const;
// };
// string Base::print() const {
//     return "B";
// }
// class Derived : public Base {
// public:
//     virtual string print() const;
// };
// string Derived::print() const {
//     return "D";
// }
// void describe(Base p) {
//     cout << p.print();
// }
// int main() {
//     Base b;
//     Derived d;
//     describe(b); //đúng -> b.print => ra B 
//     describe(d); //d được kế thừa từ B -> tạo b rồi tạo d. K bị compile nè, phần B tạo ra dùng được với hàm describe => ra B 
// } //Kq: BB 


//Cau 17 Note 
// class Base
// {
// public:
//     Base();
//     ~Base(); // không có virtual nên k thừa kế xuống derived 
// };
// Base::Base()
// {
//     cout << "CB_";
// }
// Base::~Base()
// {
//     cout << "DB_";
// }
// class Derived : public Base
// {
// public:
//     Derived();
//     ~Derived();
// };
// Derived::Derived()
// {
//     cout << "CD_";
// }
// Derived::~Derived()
// {
//     cout << "DD_";
// }
// int main()
// {
//     Base *Var = new Derived();
//     delete Var; //xóa var thuộc class base nên chỉ DB thui 
// }//kq: CBCDDB


//Cau 18 
// template <class T>
// T Func(T x)
// {
//     return x;
// }
// template <class T, class U>
// T Func(U x)
// {
//     return (T)x;
// }
// int main()
// {
//     int x = 5;
//     int y = Func(x);
//     int z = Func(5.5); //vì return T(x) trả về kiểu của T là kiểu của z 
//     cout << y << z;
// }//Kq: 55


// Cau 19 Note!
// class A
// {
// public:
//     virtual void func();
// };
// class B
// {
// public:
//     void fun();
//     int x;
// };
// int main()
// {
//     int a = sizeof(A), b = sizeof(B);
//     cout << a << b;
//     if (a == b)
//         cout << "a==b";
//     else if (a > b)
//         cout << "a>b";
//     else
//         cout << "a<b";
// }//kq: 8 1 , a>b. 
//Note: virtual có kích thước 8 bytes. 


//Cau 20 Note
// class Base
// {
//     int prop;
// public:
//     Base();
//     void Func();
// };
// Base::Base() : prop(0)
// {
// }
// void Base::Func()
// {
//     this->prop++;
//     cout << this->prop;
// }
// class Derived : private Base
// {
// public:
//     void Func();
// };
// void Derived::Func()
// {
//     this->Func();
// }
// int main()
// {
//     Derived obj;
//     obj.Func();
// }//runtime err trùng tên hàm -> segment fault Đ 


//Cau 21
// template <class T>
// class Exam
// {
// public:
//     void operator()(T);
// };
// template <class T>
// void Exam<T>::operator()(T obj)
// {
//     cout << obj;
// }
// int main()
// {
//     Exam<string> obj_s;
//     Exam<int> obj_i;
//     int var_i = 2019;
//     string str = "ITF";
//     obj_i(var_i);
//     obj_s(str);
// }//kq: 2019ITF Đ

//Cau 22
// #include <stdarg.h>
// void Func(string str, ...)
// {
//     va_list ptr;
//     int var_x;
//     va_start(ptr, str);
//     var_x = va_arg(ptr, int); // x = 1
//     var_x = va_arg(ptr, int); // x = 4
//     var_x = va_arg(ptr, int);
//     var_x = va_arg(ptr, int); //x được gán lại giá trị sau các lần duyệt 
//     var_x = va_arg(ptr, int);
//     cout << var_x;
// }
// int main()
// {
//     Func("ITFa1DUT", 1, 4, 7, 11, 0);
// } //Kq: 0 


//Cau 23
// class Base
// {
//     int x;

// public:
//     Base();
//     Base(const Base &);
//     Base &operator=(const Base &);
// };
// Base::Base() : x(0)
// {
// }
// Base::Base(const Base &obj)
// {
//     this->x = obj.x;
//     cout << "ITF";
// }
// Base &Base::operator=(const Base &obj)
// {
//     this->x = obj.x;
//     cout << "DUT";
//     return *this;
// }
// int main()
// {
//     Base obj1, obj2;
//     Base obj3(obj1); //chỉ gọi tới base(const base &), k dùng operator 
// }//Kq: ITF Đ 

// struct Struct
// {
// public:
//     int Addition(int, int = 10);
//     double Addition(int, double);
// };
// int Struct::Addition(int x, int y)
// {
//     return (x *= y + 2);
// }
// int main()
// {
//     Struct obj;
//     cout << obj.Addition(1) << obj.Addition(3, 4);
// }


//Cau 24 
// class BaseA {
//     int x;
// };
// class BaseB {
//         int x;
//     BaseA obj;
//     public:
//         operator BaseA();
//         operator int();
// };
// BaseB::operator BaseA()
// {
//     return this->obj;
// }
// BaseB::operator int()
// {
//     return this->x;
// }
// void Func(int x)
// {
// }
// void Func(BaseA obj) {}
// int main()
// {
//     BaseB obj;
//     Func(obj);
// } //comp err Đ. lỗi vì func phải truyền vô obj kiểu BaseA


//Cau 25
// class Base
// {
//     int x;

// public:
//     Base(int = 0);
//     Base operator+(int);
//     friend ostream &operator<<(ostream &, Base);
// };
// Base::Base(int x) : x(x) {}
// Base Base::operator+(int x)
// {
//     Base obj;
//     obj.x = this->x + x;
//     return obj;
// }
// ostream &operator<<(ostream &o, Base obj)
// {
//     o << obj.x;
//     return o;
// }
// int main()
// {
//     Base obj(1), obj2;
//     obj2 = obj + 2;
//     cout << obj2;
// } // 3 chạy bthg 


//Cau 26
// class Complex {
//     double R;
//     double I;
// public:
//     Complex();
//     Complex operator()(const double &, const double &);
//     Complex operator()(const double &);
//     void Func();
// };
// Complex::Complex() : R(0), I(0) { }
// Complex Complex::operator()(const double &R, const double &I) {
//     this->R += R;
//     this->I += I;
//     return *this;
// }
// Complex Complex::operator()(const double &R) {
//     this->R += R;
//     return *this;
// }
// void Complex::Func() {
//     cout << "(" << R << ", " << I << ")";
// }
// int main() {
//     Complex obj_x, obj_y;
//     obj_y = obj_x(3.2, 5.3); //x y bằng nhau 
//     obj_x(6.5, 2.7);  //cộng thêm cho x 
//     obj_y(1.9); //cộng thêm giá trị đầu R cho y 
//     obj_x.Func();
//     obj_y.Func();
// }// kq: (9.7, 8)(5.1, 5.3)


//Cau 27 Note!
// class Base
// {
//     int x;
// public:
//     Base(int = 1); //Vẫn có hàm dựng được nè 
//     friend Base operator,(int, Base &);
//     friend ostream &operator<<(ostream &, Base &);
// };
// Base::Base(int x) : x(x) {}
// Base operator,(int x, Base &obj)
// {
//     obj.x = x;
//     return obj;
// }
// ostream &operator<<(ostream &o, Base &obj)
// {
//     int x = 2;
//     o << (x, obj).x;
//     return o;
// }
// int main()
// {
//     Base obj;
//     // cout << obj,(10); nháp thoi 
//     cout << obj;
// } //Kq: 2, int x = 2 tại operator << 


//Cau 28
// class Complex
// {
//     double R, I;

// public:
//     Complex(double, double);
//     Complex(double);
//     friend Complex operator+(Complex &, Complex &);
//     friend ostream &operator<<(ostream &, Complex);
// };
// Complex::Complex(double R, double I) : R(R), I(I) {}
// Complex::Complex(double R)
// {
//     this->R = this->I = R;
// }
// Complex operator+(Complex &obj1, Complex &obj2)
// {
//     return Complex(obj1.R + obj2.R, obj1.I + obj2.I);
// }
// ostream &operator<<(ostream &o, Complex obj)
// {
//     o << obj.R << ", " << obj.I;
//     return o;
// }
// int main()
// {
//     Complex obj1(3, 4);
//     Complex obj3(4, 4);
//     Complex obj2 = obj1 + obj3;
//     cout << obj2;
// }// 7,8 Đ


//Cau 29 n.
// const int Max = 4;
// class Exam
// {

//     int arr[Max];
// public:
//     int &operator[](const int &);
// };
// int &Exam::operator[](const int &idx)
// {
//     if (idx == Max - 1)
//     {
//         int tmp;
//         for (int i = 0; i < Max; ++i)
//         {
//             if (*(this->arr + idx) > *(this->arr + idx))
//             {
//                 tmp = *(this->arr + idx);
//                 *(this->arr + idx) = *(this->arr + idx);
//                 *(this->arr + idx) = tmp;
//             }
//         }
//     }
//     return *(this->arr + idx);
// }
// int main()
// {
//     Exam obj;
//     for (int i = 0; i < Max; ++i)
//         obj[i] = i * 10; //gán như bthg vô thôi 
//     for (int i = 0; i < Max; ++i)
//     {
//         int tmp = obj[i];
//         cout << tmp; //in lần lượt ra 
//     }
// }//Kq: 0 10 20 30


//Cau 30 
// class Base
// {
// private:
//     void *operator new(size_t size) {}
//     void *operator new[](size_t size) {}
// };
// int main()
// {
//     Base *ptr1 = new Base;
//     Base *ptr2 = new Base[10];
// } //comp err vì private Đ

/*----------------------------------------------------------*/

//Cau 31
// class Exam {
//     double prop_length;
//     double prop_breadth;
//     double prop_height;
// public:
//     ~Exam();
//     double getVolume();
//     void setLength(double);
//     void setBreadth(double);
//     void setHeight(double);
//     Exam operator+(const Exam &);
// };
// Exam::~Exam() { }
// double Exam::getVolume() {
//     return this->prop_length * this->prop_breadth * this->prop_height;
// }
// void Exam::setLength(double prop_length) {
//     this->prop_length = prop_length;
// }
// void Exam::setBreadth(double prop_breadth)
// {
//     this->prop_breadth = prop_breadth;
// }
// void Exam::setHeight(double prop_height) {
//     this->prop_height = prop_height;
// }
// Exam Exam::operator+(const Exam &obj) {
//     Exam obj_x;
//     obj_x.prop_length = this->prop_length + obj.prop_length;
//     obj_x.prop_breadth = this->prop_breadth + obj.prop_breadth;
//     obj_x.prop_height = this->prop_height + obj.prop_height;
//     return obj_x;
// }
// int main() {
//     Exam obj_x;
//     Exam obj_y;
//     Exam obj_z;
//     double volume = 0.0;
//     obj_x.setLength(6.0);
//     obj_x.setBreadth(7.0);
//     obj_x.setHeight(5.0);
//     obj_y.setLength(12.0);
//     obj_y.setBreadth(13.0);
//     obj_y.setHeight(10.0);
//     volume = obj_x.getVolume();
//     cout << volume;
//     volume = obj_y.getVolume();
//     cout << volume;
//     obj_z = obj_x + obj_y;
//     volume = obj_z.getVolume();
//     cout << volume;
// }//kq: 2101560 5400 (5400 là voulm của z, là nhân 3 cái vô 1 lần nữa nghe)


//Cau 32 Note! hỏi tòn 
// class Exam
// {
// public:
//     int prop;
//     Exam *operator->();
// };
// Exam *Exam::operator->()
// {
//     return this;
// }
// int main()
// {
//     Exam obj;
//     obj->prop = 10;
//     cout << obj.prop << obj->prop;
// } //1010 Đ 


//Cau 33 Note! 
// class Base
// {
//     int x;

// public:
//     Base(int = 1);
//     friend void operator<<(ostream &, Base);
// };
// Base::Base(int x) : x(x) {}
// void operator<<(ostream &o, Base obj)
// {
//     o << obj.x;
// }
// int main()
// {
//     Base obj1(2), obj2(4);
//     cout << obj1 << obj2; //Lỗi compile ở dấu << thứ 2, chưa định nghĩa operator ni nè . cout << obj1; cout << obj2 thì được. 
// } //kq: 24 bthg 


//Cau 34 
// class Base
// {
// public:
//     Base();
//     Base(const Base &);
//     void operator=(const Base &);
// };
// Base::Base()
// {
//     cout << "A";
// }
// Base::Base(const Base &obj)
// {
//     cout << "B";
// }
// void Base::operator=(const Base &obj)
// {
//     cout << "C";
// }
// int main()
// {
//     Base obj1;
//     Base obj2;
//     obj2 = obj1;
// }//kq: AAC Đ 


//Cau 35 
// class Base
// {
//     int x;
// public:
//     Base(int = 1);
//     friend void operator<<(ostream &, Base &);
// };
// Base::Base(int x) : x(x) {}
// void operator<<(ostream &o, Base &obj)
// {
//     o << obj.x;
// }
// int main()
// {
//     Base obj(2);
//     obj << cout; //compile err here 
// }


//Cau 36 
// class Exam
// {
// public:
//     Exam();
//     Exam(Exam const &);
//     Exam &operator=(Exam const &);
// };
// Exam::Exam()
// {
//     cout << "ITF";
// }
// Exam::Exam(Exam const &)
// {
//     cout << "DUT";
// }
// Exam &Exam::operator=(Exam const &)
// {
//     cout << "CNTT";
//     return *this;
// }
// Exam Func()
// {
//     Exam obj;
//     return obj;
// }
// int main()
// {
//     Exam obj = Func();
// }


//Cau 37
// class Complex
// {
//     int R;
//     int I;
// public:
//     Complex();
//     Complex(int, int);
//     ~Complex();
//     Complex operator+(const Complex &);
//     friend ostream &operator<<(ostream &, const Complex &);
// };
// Complex::Complex()
// {
// }
// Complex::Complex(int R, int I) : R(R), I(I)
// {
// }
// Complex::~Complex()
// {
// }
// Complex Complex::operator+(const Complex &obj)
// {
//     return Complex(this->R + obj.R, this->I + obj.I);
// }

// ostream &operator<<(ostream &o, const Complex &obj)
// {
//     o << obj.R << " +i" << obj.I;
//     return o;
// }
// int main()
// {
//     Complex obj_x(1, 2), obj_y(3, 4);
//     Complex obj_z = obj_x + obj_y;
//     cout << obj_z;
// }


//Cau 38
// class Exam
// {
//     int prop;

// public:
//     Exam(/* args */ int = 1);
//     ~Exam();
//     const Exam operator+(const Exam &) const;
//     Exam &operator+=(const Exam &);
//     friend ostream &operator<<(ostream &, const Exam &);
// };

// Exam::Exam(int prop) : prop(prop)
// {
// }

// Exam::~Exam()
// {
// }

// const Exam Exam::operator+(const Exam &obj) const
// {
//     return Exam(this->prop + obj.prop);
// }
// Exam &Exam::operator+=(const Exam &obj)
// {
//     this->prop += obj.prop;
//     return *this;
// }
// ostream &operator<<(ostream &o, const Exam &obj)
// {
//     o << obj.prop;
//     return o;
// }

// int main()
// {
//     Exam obj_x, obj_y(2), obj_z(3);
//     obj_z += obj_x + obj_y;
//     cout << obj_x << obj_y << obj_z;
// }

// void Func(int x, int y)
// {
//     if (y == 0)
//         throw "error!";
//     else
//         cout << x << y;
// }
// int main()
// {
//     try
//     {
//         try
//         {
//             /* code */
//             Func(5, -1);
//         }
//         catch (int e)
//         {
//             if (e == 0)
//             {
//                 throw "A";
//             }
//             else
//                 throw "B";
//         }
//     }
//     catch (char *e)
//     {
//         cout << e;
//     }
// }

// template <typename T>
// void Func(const T &var_x)
// {
//     static int count = 0;
//     cout << var_x << count;
//     ++count;
//     return;
// }
// int main()
// {
//     Func<int>(1);
//     Func<int>(1);
//     Func<double>(2.1);
//     Func<float>(3.1);
// }

// int main()
// {
//     try
//     {
//         throw 1;
//     }
//     catch (int &e)
//     {
//         cout << "Excep" << e;
//         return 0;
//     }
//     cout << "No Excep";
// }

// class Base
// {
// public:
//     int prop;
//     Base(int = 0);
// };
// Base::Base(int prop) : prop(prop)
// {
//     cout << "ITF";
// }
// class Derived : public Base
// {

// public:
//     double prop;
//     Derived(double = 0.0);
// };
// Derived ::Derived(double prop) : prop(prop)
// {
//     cout << "DUT";
// }
// int main()
// {
//     Base b;
//     Derived d;
// }

// #include <string>
// template <class T>
// inline T Func(T var_x)
// {
//     T result = var_x + var_x;
//     return result;
// }
// template <>
// string Func<string>(string str)
// {
//     return (str + str);
// };
// int main()
// {
//     int x = 2, y;
//     string str("ITF");
//     y = Func<int>(x);
//     cout << x << Func<string>(str);
// }

// template <class T>
// class Exam
// {
// public:
//     Exam();
//     ~Exam();
// };
// template <typename T>

// Exam<T>::Exam()
// {
//     cout << "C";
// }
// template <typename T>
// Exam<T>::~Exam()
// {
//     cout << "D";
// }
// int main()
// {
//     Exam obj; // phai goi Exam<...>
// }

// template <int n>
// struct Exam
// {
//     static const int prop = 2 * Exam<n - 1>::prop;
// };
// template <>
// struct Exam<0>
// {
//     static const int prop = 1;
// };
// int main()
// {
//     cout << Exam<10>::prop << " " << endl;
//     cout << Exam<9>::prop << " " << endl;
//     cout << Exam<8>::prop << " " << endl;
// }
// #include <vector>
// int main()
// {
//     vector<int> myvector(5);
//     int *p = myvector.data();
//     *p = 10;
//     ++p;
//     *p = 20;
//     p[2] = 100;
//     for (unsigned i = 0; i < myvector.size(); ++i)
//         cout << " " << myvector[i];
// }
/*----------KQ 10 20 0 100 0 --------------*/

// int main()
// {
//     double x = 10, y = 5, z;
//     char Operator = '/';
//     try
//     {
//         if (y == 0)
//             throw "error";
//         z = x / y;
//         cout << x << "/" << y << "= " << z;
//     }
//     catch (const char *e)
//     {
//         cout << "bad Operator" << e;
//     }
// }

// class SV
// {

// protected:
//     int MSSV;

// public:
//     void getMSSV(int);
//     void putMSSV();
// };
// void SV::getMSSV(int MSSV)
// {
//     this->MSSV = MSSV;
// }
// void SV::putMSSV() {}
// class Text : public SV
// {
// protected:
//     double mark1, mark2;

// public:
//     void getMark(double, double);
//     void putMark();
// };

// void Text::getMark(double mark1, double mark2)
// {
//     this->mark1 = mark1;
//     this->mark2 = mark2;
// }
// void Text::putMark() {}
// class Sport
// {
// protected:
//     double score;

// public:
//     void getScore(double);
//     void putScore();
// };
// void Sport::getScore(double score)
// {
//     this->score = score;
// }
// void Sport::putScore() {}

// class Result : public Text, public Sport
// {
//     double total;

// public:
//     void display();
// };
// void Result::display()
// {
//     this->total = this->mark1 + this->mark2 + this->score;
//     putMSSV();
//     putMark();
//     putScore();
//     cout << this->total;
// }
// int main()
// {
//     Result SV;
//     SV.getMSSV(123);
//     SV.getMark(27.5, 33.0);
//     SV.getScore(6.0);
//     SV.display();
// }

// #include <iostream>
// using namespace std;
// template <class T, int max>
// int arrMin(T arr[], int n)
// {
//     int m = max;
//     for (int i = 0; i < n; i++)
//     {

//         if (arr[i] < m)
//             m = arr[i];
//     }

//     return m;
// }

// int main()
// {
//     int arr1[] = {10, 20, 15, 12};
//     int n1 = sizeof(arr1) / sizeof(arr1[0]);
//     cout << n1;
//     char arr2[] = {1, 2, 3};
//     int n2 = sizeof(arr2) / sizeof(arr2[0]);
//     cout << n2;
//     cout << arrMin<int, 10000>(arr1, n1) << endl;
//     cout << arrMin<char, 256>(arr2, n2);
//     return 0;
// }

// template <class T>
// T Func(T &var_x, T &var_y)
// {
//     cout << "1";
//     return (var_x > var_y) ? var_x : var_y;
// }

// template <>

// int Func<int>(int &x, int &y)
// {
//     cout << "2";
//     return (x > y) ? x : y;
// }
// int main()
// {
//     int x = 10, y = 20;
//     cout << Func<int>(x, y);
// }