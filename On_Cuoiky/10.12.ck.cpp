#include<bits/stdc++.h>
using namespace std;

//Đề KHDL
//Cau 1 
// class Base {
//     virtual void Func();
// };
// void Base::Func() { } 
// class Derived : public Base {
//     int prop;
// };
// int main() {
//     try {
//         Base * ptr_x = new Derived; 
//         Base * ptr_y = new Base; 
//         Derived * ptr_d; 
//         ptr_d = dynamic_cast<Derived*>(ptr_x);//x có kiểu dữ liệu gốc là Derived === <Derived> -> trả về con trỏ => d != null
//         if(ptr_d == 0) {
//             cout << "Null pointer on first type-cast";
//         }
//         ptr_d = dynamic_cast<Derived*>(ptr_y);
//         if(ptr_d == 0) {
//             cout << "Null pointer on second type-cast";
//         }
//     }
//     catch (exception &e) {
//         cout << "Exception";
//     }
//     return 0;
// }
//Kq: Null pointer on second type-cast
// dynamic_cast<> là keyword truyền dữ liệu từ 1 con trỏ sang 1 con trỏ khác
//ép một con trỏ từ lớp cơ sở -> dẫn xuất  
//upcast nè: cha -> con  
// p = static_cast <Type *> (ptr) 
    //p là con trỏ thuộc lớp con -> mà sẽ ép về ptr á -> tức là sau câu lệnh sẽ trỏ về lớp cha nè hehe 
    //ptr là tên con trỏ thuộc lớp cha - cần để ép kiểu
    //Type: con trỏ p kiểu chi - thì <Type> trong ngoặc nhọn ni nè phải cùng kiểu, nếu k là lỗi đó


//Câu 2
// typedef int P;
// int main() {
//     int x=1,y=2; 
//     P* ptrx, ptr_y;   // P *ptrx; P ptr_y; 
//     ptrx = &x; 
//     ptr_y = &y;   //compile do ptr_y khong phải là con trỏ
//     cout<< *ptrx << *ptr_y;
//     return 0;  
// }


//Câu 3 Note
// class exam {
//     public: 
//         exam();
//         ~exam(); 
// };
// exam::exam() {
//     cout << "C";
// }
// exam::~exam() {
//     cout << "D";
// }
// int main() {
//     exam *ptr = new exam[3];
//     delete ptr;
//     return 0;
// }
// Kq: CCCDDD
// new exam[3] vẫn được khởi tạo bình thường
//Nếu delete ptr thì lỗi runtime, vì không tìm ra ptr?



//Cau 4
// #define SquareOf(x) x*x; 
// int main () {
//     int x; 
//     cout<<SquareOf(x+4);  // x+4*x+4
//     //x không xác định nên trả về giá trị rác
//     return 0; 
// }
//Vdu: nếu x = 1 => kq = 9, 1 + 4*1 + 4 = 9 => không ăn dấu ngoặc


//Câu 5
// int main() {
//     char arr[100];
//     cin.getline(arr, 10, 't'); //getline (mảng tên chi, mấy phần tử, phần tử cuối)
//     cout << arr;
// }
//kq: chạy bình thường, cin vô


//Câu 6 
// int main () {
//     int x = 1, y = 2, z = 3; 
//     int t = (x,y,z);  // toán tử , trả về thr cuối cùng
//     cout << t;    // kq: 3
//     return 0; 
// }


//Câu 7  
// int main() {
//     int x; 
//     cin >> x + 4; //lỗi compile >> ? chưa đa năng hóa
//     cout << x;
//     return 0;
// }


//Câu 8 
// namespace Exam {
//     int x=9; 
//     int y=1; 
// }
// namespace y=Exam; 
// int main() {
//     cout<<y::x;  //9  kiểu y là một namespace thôi ha 
//     return 0; 
// }


//Câu 9 
// int main() {
//     int arr[] = {10, 20, 30};
//     cout << *arr + 1; //*arr vị trí đầu tiên của mảng = 10 -> 10+1 = 11
//     return 0;
// }
//kq: 11


//Câu 10
// class Exam {
// private:
//     int& ref; 
// public:
//     Exam(int);
//     ~Exam();
//     int getRef(); 
// };
// Exam::Exam(int ref) :ref(ref) { }
// Exam::~Exam() { }
// int Exam::getRef() {
//     return this->ref; 
// }
// int main() {
//     Exam obj(1); 
//     cout<<obj.getRef();  // 1 chạy như bth ha
//     return 0; 
// }


//Câu 11. 
// class exam {
//     public:
//         exam(char); 
//         ~exam();
// };
// exam::exam(char var) {
//     var = 'C';
//     cout << var;
// }
// exam::~exam() {
//     cout << 'D';
// }
// int main() {
//     exam *ptr = new exam[3];//compile err, không có constructor exam()
//     delete[] ptr;
// }


//Câu 12 
// typedef int* P; 
// int main() {
//     int x = 1, y = 2;
//     P ptr_x, ptr_y; 
//     ptr_x = &x; 
//     ptr_y = &y; 
//     cout << *ptr_x << *ptr_y;  //1 2 lần ni ok rồi, chạy bthg thui
//     return 0;
// }


//Câu 13. 
// class base {
//     int prop;
//     public:  
//         base(); 
//         void func();
// };
// base::base() : prop(0) { }
// void base::func() {
//     this->prop++; 
//     cout << this->prop;
// }
// class derived : private base {
//     public: 
//         void func();
// };
// void derived::func() {
//     // cout << 1; vd cout 1 thì chạy ra 1 nùi 1 vòng lặp, vì không biết func nào
//     this->func(); //runtime error: mơ hồ về tên hàm func đúng k ta
// }
// int main() {
//     derived obj;
//     obj.func();
//     return 0;
// }


//Câu 14.
// template <class T>
// T Func(T& x,T& y) {
//     return (x > y ? x : y); 
// }
// int main() {
//     int x = 5,y = 6, z; 
//     long i = 10, j = 5, k; 
//     z = Func(x, y);
//     k = Func(i, j); 
//     cout << z << k;  //6 10 chạy bth 
//     return 0; 
// }


//Câu 15 
// int main() {
//     try {
//         char *ptr; 
//         strcpy(ptr, "ITF"); //segment fault, lỗi runtime do ptr là địa chỉ con trỏ thôi, k copy được.
//     }
//     catch (const exception &e) {

//     }
//     return 0;
// }


//Câu 16
// int main() {
//     try {
//         char* ptr;         
//         strcpy(ptr, "ITF");  // ptr cấp phát động nhưng chưa cung cấp bộ nhớ    
//                             //chắc runtime, segment fault ở đây. 
//         cout<<ptr[0]<<ptr[1]<<ptr[2]; 
//     }
//     catch (const exception &e) {
//         cout<<"do exception"<<endl;
//     }
//     catch (...) {
//         cout<<"bat all"; 
//     };
//     return 0; 
// }


//Câu 17
// int func1(int x = 1) {
//     int y = x; 
//     return y;
// }
// int func2(int x = 1) {
//     int y = x;
//     return y + 1;
// }
// int main() {
//     int x = 1; 
//     cout << func1(func2(x)) << func2(func1(x)); 
//     return 0;
// }
//Kq: 22. Chạy bthg nè


//Câu 18 
// class base {
//     public:  
//         struct Struct {
//             int x; float y; 
//             void func() {
//                 y = x = (x = 4 * 4);
//                 y = --y * y; 
//             }
//             void Show() {
//                 cout << y;
//             }
//         } obj2;
// } obj1; 
// int main() {
//     obj1.obj2.Show();
//     return 0;
// }
//kq: 0 garbage value vì chưa gọi hàm func, x,y chưa có giá trị


//Câu 19. 
// class Exam {
// private:
//     /* data */
// public:
//     Exam(/* args */);
//     ~Exam();
// };

// Exam::Exam(/* args */) {
//     cout<<"C"; 
// }

// Exam::~Exam() {
//     cout<<"D"; 
// }
// int main() {
//     delete new Exam();   
//     return 0; 
// }
//Kq: CD .Tạo bằng new Exam() rồi xoá kkk


//Câu 20 
// void func(int x, int y) {
//     if(y == 0) {
//         throw "Error!";
//     }
//     else {
//         cout << x << y;
//     }
// }
// int main() {
//     try {
//         func(5, 0);
//     }
//     catch (char *e) {
//         cout << e;
//     }
//     return 0;
// }
//Lỗi runtime, core dumped. Đổi thành const char *e thì ok


//Câu 21
// class base {
//     public:
//         virtual void func();
// };
// void base::func() {
//     cout << "B";
// }
// class derived : public base {
//     int prop;
//     public:  
//         void func();
//         derived();
//         int getProp() const;
// };
// void derived::func() {
//     cout << "D";
// }
// derived::derived() {
//     this->prop = 10;
// }
// int derived::getProp() const {
//     return this->prop;
// }
// int main() {
//     derived obj_d; //Nếu base obj thì cout ra B 
//     base *ptr = &obj_d; 
//     ptr->func();
//     //cout << ptr->getProp(); //Lỗi compile ở đây. Nếu k có dòng này thì cout ra D. 
//     //Nếu cout << obj_d.getProp thì ra 10. 
//     return 0;
// }
//Tức là lớp base phải có tên hàm đó, phải virtual, thì upcast xuống con mới có thể gọi tên được. 
//class base với derived nếu không kế thừa nhau, mà gán cho nhau là sai nè



//Câu 22. 
// int main() {
//     char* ptr; 
//     cout<<size_t(0)<<endl;  //ép kiểu size_t gần như là không ép chi giữ nguyên giá trị 
//     unsigned long int x=(size_t(0)/3); // size_t là k phải là kiểu cố định, dạng auto 
//     cout<<x; //in ra 0 
//     try {
//         ptr =new char[size_t(0)/3];
//         delete [] ptr; 
//     }
//     catch (bad_alloc & e) {
//         cout<<e.what(); 
//     };
//     return 0; 
// } //kq: 0
