#include<bits/stdc++.h>
using namespace std;

//Đề của Khánh 
//Câu 1
// template<int n>
// struct exam {
//     static const int prop = 2 * exam<n - 1>::prop; //đệ quy 2* n-1 lần
// };
// template<>
// struct exam<0> { //nếu truyền số 0 vô thì prop = 1
//     static const int prop = 1;
// };
// int main() {
//     cout << exam<10> ::prop;
//     return 0;
// }
//Kq: 2*2...(10 lần) = 1024


//Câu 2
// int x = 1; 
// int& func() {
//     static int x = ::x++; 
//     return x;
// }
// int main() {
//     cout << x; //1 
//     cout << func();//1
//     func()++; 
//     cout << func();
//     return 0;
// }
// :: khong di voi prefix 


//Câu 3 Note
// template<class T, class U>
// class exam {
//     T x;
//     U y; 
//     static int count;//biến static dùng chung bộ nhớ -> không tăng size
// };
// int main() {
//     exam<char, char> x; 
//     exam<int, int> y;
//     cout << sizeof(x) << sizeof(y);
//     return 0;
// }
//Kq: 28


//Câu 4 
// int main() {
//     int var_x = 5, &ref_x = var_x;
//     cout << &var_x << "," << &ref_x;
//     return 0;
// }
//Kq: address of x , address of x


//Cau 5 
// namespace exam {
//     int var_x = 10; 
// }
// namespace exam {
//     int var_y = 15;
// }
// int main(){
//     exam::var_x = exam::var_y = 5; 
//     cout << exam::var_x << exam::var_y; 
//     return 0;
// }
//Kq: 55. Chay binh thuong


//Cau 6
// class exam {
//     public:
//         int prop; 
//         exam *operator->();
// };
// exam* exam::operator->() {
//     return this;
// }
// int main() {
//     exam obj; 
//     obj->prop = 10; 
//     cout << obj.prop << obj->prop;
//     return 0;
// }
//Kq: 1010, chay binh thuong 


//Cau 7
// class base {
//     int prop; 
//     public:
//         virtual void func() = 0;
// };
// class derived : public base {
//     public:
//         void func();
// };
// void derived::func() {
//     cout << "ITF";
// }
// int main() {
//     base obj; //compile err vi base la ham thuan ao 
//     obj.func();
//     return 0;
// }


//Cau 8  
// int func(int x, int y) {
//     cout << x; 
//     cout << y; 
//     return 0;
// }
// int main() {
//     int(*ptr)(char, int);
//     ptr = func; //compile err vi char != int 
//     func(2,3); 
//     ptr(2,3); 
//     return 0;
// }


//Cau 9 
// template<class T>
// T func(T var_x) {
//     cout << var_x; 
//     return var_x;
// }
// template<class U>
// void func(U var_x) {
//     cout << var_x;
// }
// int main() {
//     int var_x = 5; 
//     int var_y = func(var_x); //compile err vi trung ten ham func, void != int
//     return 0;
// }


//Cau 10 
// class exam {
//     static int count; 
//     public:
//         exam();
//         ~exam();
//         static int getCount();
// };
// int exam::count = 0; 
// exam::exam() {
//     exam::count++;
// }
// exam::~exam() { }
// int exam::getCount() {
//     return exam::count;
// }
// int main() {
//     cout << exam::getCount();// = 0
//     exam arr[5];
//     cout << exam::getCount(); // 5
//     return 0;
// }
//Kq: 05


//Cau 11 N
// void func(char var_c) {
//     if (var_c < numeric_limits<char>::max())
//         return invalid_argument;//Lỗi compile ở đây nè, void khong return hehe
// }
// int main() {
//     try {
//         func(256);
//     }
//     catch (invalid_argument &e) {
//         cerr << e.what(); 
//         return 1;
//     }
//     return 0;
// }


//Cau 12  
// int main() {
//     class exam{
//         int var = 1;
//     }obj;
//     cout << obj.var; //compile err private class
//     return 0;
// }


//Cau 13 
// class base {
//     public:
//         int x; 
// };
// int main() {
//     base obj1 = {1}; //Chay binh thuong ra 11 
//     base obj2 = obj1;
//     cout << obj1.x << obj2.x;
//     return 0;
// }


//Cau 14 
// class exam {
//     ~exam();
// };
// exam::~exam() {
//     cout << "D";
// }
// int main() {
//     exam *ptr_x = new exam();
//     exam *ptr_y = new exam();
//     delete ptr_x;
//     return 0;
// }
//Kq: empty output vì hàm hủy private 


//Câu 15 
// class base {
//     protected:
//         int prop; 
//     public: 
//         base(int);
//         ~base();
//         int getProp(); 
// };
// base::base(int prop) : prop(prop) {} 
// base::~base(){ }
// int base::getProp() { return this->prop; }
// class derived : public base {
//     int prop; 
//     public: 
//         derived(int, int);
//         ~derived();
//         void func();
// };
// derived::derived(int x, int y) :base(y), prop(x) { }
// derived::~derived() { }
// void derived::func() {
//     cout << prop;
// }
// int main() {
//     derived d(5,2);
//     d.func(); //cout ra 1 
// }


//Cau 16 
// template <class T> 
// inline T func(T var_x) {
//     T result = var_x * var_x;
//     return result;
// };
// template<>
// string func<string>(string str) {
//     return (str + str);
// };
// int main() {
//     int x = 2, y;
//     string str("ITF");
//     y = func<int>(x);
//     cout << x << y << func<string>(str);
// }
//Kq: 24ITFITF. Chay bthg 


//Cau 17
// template <typename T> 
// void func(T x) {
//     int count = 3;
//     T arr[count];
//     for (int i = 0; i < count; i++) {
//         arr[i] = x++;
//         cout << arr[i];
//     }
// };
// int main() {
//     double x = 2.1;
//     func(x);
//     return 0;
// }
//Kq: 2.13.14.1


//Cau 18 
// void terminator() {
//     cout << "Terminate";
// }
// void (*old_terminate)() = set_terminate(terminator);
// class Botch {
//     public: 
//         class Fruit{ };
//         void f() {
//             cout << "One";
//             throw Fruit();
//         }
//         ~Botch() {
//             throw 'c'; //Runtime err ở đây, hàm hủy thường sẽ gọi terminate, nên không dùng throw -> gây core dump. Nếu k có thì cout Oneside_catch bthg. 
//         }
// };
// int main() {
//     try {
//         Botch b; 
//         b.f();
//     }
//     catch (...) {
//         cout << "inside_catch";
//     }
//     return 0;
// }


//Cau 19 
// template <class T>
// class exam {
//     public: 
//         void operator()(T);
// };
// template <class T>
// void exam<T>::operator()(T obj) {
//     cout << obj;
// }
// int main() {
//     exam<string> obj_s;
//     exam<int> obj_i;
//     int var_i = 2019;
//     string str = "ITF";
//     obj_i(var_i);
//     obj_s(str);
//     return 0;
// }
//Kq: Chay bthg: 2019ITF


//Cau 20
// class base {
//     int x;
//     public: 
//         void input(int);
//         void show();
// };
// void base::input(int x) {
//     this->x = x++;
// }
// void base::show() {
//     cout << this->x;
// }
// int main() {
//     base obj;
//     obj.input(5);
//     obj.show();
// }
//Kq: 5


//Cau 21 Note.
// class base {
//     public: 
//         virtual void show() = 0;
// };
// class derived:public base {
// };
// int main() {
//     derived q; 
//     return 0;
// }
//Kq: Derived is abstract (derived bị trừu tượng, do virtual trên base thừa kế xuống. Base đang là hàm thuần ảo. Cần phải override hàm show để hủy hàm thuần ảo ở derived. 
//void show(){};


//Cau 22 
// class base {
//     public: 
//         virtual base();
// };
// base::base() {
//     cout << "1";
// }
// int main() {
//     base obj; 
//     return 0;
// }
//Kq: comp err. Constructor khong the dung virtual


//Cau 23
// template<class T>
// class exam {
//     public: 
//         exam();
//         ~exam();
//         T func1(T);
//         T func2(T);
// };
// template<class T>
// exam<T>::exam() { }
// template<class T>
// exam<T>::~exam() { }
// template<class T>
// T exam<T>::func1(T x) {
//     return x;
// }
// template<class T>
// T exam<T>::func2(T x) {
//     return x;
// }
// int main() {
//     exam<int> obj_i;
//     exam<double> obj_d;
//     cout << obj_i.func1(200) << obj_d.func2(3.123);
// }
//Kq: 2003.123. Chay binh thuong 


//Cau 24
// int main() {
//     int num = 3;
//     try {
//         if (num == 1) throw 5;
//         if (num == 2) throw 1.1f;
//         if (num != 1 || num != 2) throw string("Error!");//thuc thi
//     }
//     catch (int a) {cout << a;}
//     catch (float b) {cout << b;}
//     catch (...) {cout << "Error!";} //cout "error!"
// }


//Cau 25
// int main() {
//     int i, n;
//     int *p;
//     i = 2;
//     p = new (nothrow) int[i];
//     if (p == 0) cout << "err: memory couln't be allocated";
//     else {
//         for(n = 0; n < i; n++) p[n] = 5; //i = 2
//         for(n = 0; n < i; n++) cout << p[n];
//         delete[] p;
//     }
// }
//Kq: 55 
//nothrow: indicate that funcs not throw an exception on failure -> return a NULL POINTER instead. 


//Cau 26
// template<class T>
// T func(T x) {
//     cout << x; 
//     return x;
// }
// int func(int x) {
//     cout << x;
//     return x;
// }
// int main() {
//     int x = 5;
//     int y = func(x);
//     double z = func(5.5);
// }
//Kq: 55.5


//Cau 27
// int main() {
//     vector<int> obj;
//     obj.assign(3,4);
//     for (int i = 0; i < obj.size(); i++) {
//         cout << obj[i];
//     }
// }
//Kq: 444
//syntax: assign(size_type_n, const_value_val)


//Cau 28
// class base {
//     int _x;
//     public: 
//         base(int x) :_x(x) {
//             cout << "A";
//         }
// };
// class child : public base {
//     int _y;
//     public: 
//         child(int x, int y) : base(x), _y(y) {
//             cout << "B";
//         }
// };
// int main() {
//     child c1; //comp err here. Miss constructor child()
//     child c2(1,2);
// }


//Cau 29
// template<class T>
// class exam {
//     T prop; 
//     public: 
//         static int count;
//         exam();
//         ~exam();
// };
// template<class T>
// int exam<T>::count = 0;
// template<class T>
// exam<T>::exam() {
//     exam<T>::count++;
// }
// template<class T>
// exam<T>::~exam() { }
// int main() {
//     exam<int> obj_x;
//     exam<int> obj_y;
//     exam<double> obj_z;  
//     cout << exam<int>::count << exam<double>::count;
// }
//Kq:21 bthg


//Cau 30
// int sum(int x, int y) {
//     return x + y + 15; 
// }
// int func(int x, int y, int(*ptr)(int, int)) {
//     return (*ptr)(x, y);
// }
// int main() {
//     int x; 
//     int(*ptr)(int, int) = sum;
//     x = func(10, 15, ptr);
//     cout << x;
// }
//Kq: 40 = 10 + 15+15


//Cau 31
// class base {
//     public: 
//         base();
//         virtual ~base();
// };
// base::base() {
//     cout << "CB";
// }
// base::~base() {
//     cout << "DB";
// }
// class derived : public base {
//     public:
//         derived();
//         ~derived();
// };
// derived::derived() {
//     cout << "CD";
// }
// derived::~derived() {
//     cout << "DD";
// }
// int main() {
//     derived *ptr_d = new derived(); //cap cho ptr_d dữ liệu derived được thừa kế từ base -> CBCD
//     base * ptr_b = ptr_d; //con trỏ dính địa chỉ, k ăn dữ liệu 
//     delete ptr_b; //2 con trỏ đã chỉ chung 1 địa chỉ -> xóa DDDB
// }
//Kq: CBCDDDDB


//Cau 32
// class base {
//     public: 
//         char S, A, M;
//         base(char x, char y) {
//             S = y - y; A = x + x; M = x * x;
//         }
//         base(char, char y = 'A', char z = 'B') { //Vì truyền 3 char nên dùng constructor ni nè -> 3 biến là: AAB
//             S = y; A = y + 1; M = z - 1; //Biến đổi thành: ABA
//         }
//         void display() {
//             cout << S << A << M; //cout ABA
//         }
// };
// class derived : public base {
//     char x, y, z;
//     public: 
//         derived(char xx = 65, char yy = 66, char zz = 65) : base(x) {
//             x = xx; y = yy; z = zz; //set x y z = A B A, truyền x = A vô Base
//         }
//         void display(int n) {
//             if (n) base::display(); //0-1 khác 0 -> chạy base::display
//             else cout << x << y << z;
//         }
// };
// int main() {
//     derived objDev;
//     objDev.display(0 - 1);
// }
//Kq: ABA. Chay bthg ne hehe