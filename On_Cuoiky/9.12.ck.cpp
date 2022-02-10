#include <bits/stdc++.h>
using namespace std;


//ĐỀ CỦA HIỀN CÂU 3 -> ....
//Câu 3 
// class exam {
//     int prop; 
//     public:  
//         exam(); 
//         exam(double prop);
//         ~exam(); 
//         bool operator <(const exam&);
// };
// exam::exam() { }
// exam::exam(double prop) :prop(prop) {
// }
// exam::~exam(){}
// bool exam::operator <(const exam& obj) {
//     return prop < obj.prop ? 1 : 0; //điền code vô đây nè
// }
// int main() {
//     exam obj_x(10);
//     exam obj_y = exam(14);
//     if (obj_x < obj_y) {
//         cout << "y has large prop";
//     }
//     else 
//         cout << "x has large prop";
//     return 0;
// }


// Cau 4
// #define maxValue 10  
// int main() {
//     int var_x = ++maxValue; //lỗi comp ở đây
//     cout << var_x << endl;
//     return 0;
// }
// Lỗi compile vì: define là giá trị mặc định, kiểu const, không thay đổi được. 


//Câu 5.
// class exam {
//     int var;
//     static int next_var; 
//     public: 
//         exam();
//         ~exam(); 
//         int getVar();
// };
// int exam::next_var = 1;  
// exam::exam() {
//     this->var = exam::next_var++;
// }
// exam::~exam() {

// }
// int exam::getVar() {
//     return this->var;
// }
// int main() {
//     exam a;
//     cout << a.getVar(); //kq: 1
//     return 0;
// }


//Cau 6 
// class base {
//     int x, y, z; 
//     public: 
//         void func(int = 12, int = 21, int = 9);
//         void show();
//         void setData(int, int);
// };
// void base::func(int x, int y, int z) {
//     this->x = x;
//     this->y = y += 10;
//     this->z = this->x -= 2;
// }
// void base::show() {
//     cout << this->x << " " << this->y;
// }
// void base::setData(int x, int y) {
//     this->func(x, 0, y); 
// }
// int main() {
//     base *ptr = new base;
//     (*ptr).setData(12,20); //== ptr->setData(...)
//     ptr->show();
//     delete ptr;
//     return 0;
// }
//kq: 1010


//Cau 7 Note
// class exam {
//     public:
//         ~exam();
// };
// exam::~exam() {
//     cout << "D";
// }
// int main() {
//     exam *ptr = new exam[3]; 
//     delete ptr; //lỗi runtime ở đây, vì không tìm ra biến ptr? mà đó là con trỏ ptr -> cần delete[] ptr thì không có lỗi. 
//     return 0;
// }


//Câu 8 
// int main() {
//     void x = 10, y = 10;
//     int z = x + y;
//     cout << z;
//     return 0;
// }
//Lỗi compile -> không có kiểu void


//Câu 9  
// class exam {
//     int prop; 
//     exam(); //ham dung chua public  
//     public:  
//         void setProp(int);
//         int getProp();
// };
// exam::exam() : prop(5) {
// }
// void exam::setProp(int prop) {
//     this->prop = prop;
// }
// int exam::getProp() {
//     return this->prop;
// }
// int main() {
//     exam obj; //Lỗi compile
//     obj.setProp(10);
//     cout << obj.getProp();
//     return 0;
// }


//Câu 10 (23/50)
// int main() {
//     int x = 10, y = 20, z = 30;
//     float t; 
//     try {
//         if ((x - y) != 0) {
//             t = z / (x - y);
//             cout << t;
//         }
//         else {
//             throw(x - y);
//         }
//     }
//     catch(int &e) {
//         cout << e;
//     }
//     return 0;
// }
//Kq: -3, chay binh thuong


//Cau 11 
// const int& func() {
//     static int x = 1;  
//     return x; 
// }
// int main() {
//     cout << func() << (func()++);
//     return 0;
// }
//Lỗi compile vì func là const 


//Câu 12 
// int main() {
//     char * ptr; 
//     unsigned long int x = sizeof(size_t(0) / 3); 
//     cout << x; // x = 8
//     try {
//         ptr = new char[size_t(0) / 3];
//         delete[] ptr;
//     }
//     catch (bad_alloc &e){
//         cout << e.what();
//     }
//     return 0;
// }
//Kq: 8 -> another answer
//size_t : giữ chỉ mục của mảng


//Câu 13 
// int main(int argc, char const *argv[]){
//     char str_x[4] = "ITF";
//     char str_y[4] = "DUT";
//     char str_z[12] = str_x + " " + str_y; 
//     cout << str_z; 
//     return 0;
// }
//Compile err

//Ca 14  
// int main() {
//     enum exam {
//         exam1 = 1,
//         exam2, 
//         exam3
//     };
//     int var_x = exam3;
//     int &ref_x = var_x; 
//     int &ref_y = var_x;
//     ref_x = exam2;
//     cout << ref_y++; 
//     return 0;
// }
//Kq: = 2 
//enum: lớp sắp xếp tăng dần. 


//Câu 15 
// int main() {
//     try {
//         char* ptr; 
//         strcpy(ptr, "ITF");
//     }
//     catch (const exception &e) {
//         cout << "hehe";
//     }
//     return 0;
// }

//Kq: lỗi compile ? runtime (segment fault) vì không có dùng strcpy cho 2 thằng nớ được, 1 bên là địa chỉ con trỏ, 1 bên là string