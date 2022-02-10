#include <iostream>
#include <vector>
using namespace std;

class exam {

};
// void func1() throw () {
//     cout << "1";
// }
// void func() throw(int) {
//     cout << "2";
//     throw(1);
// }

// int main() {
//     try {
//         func1(); 
//         func(); 

//     }
//     catch (int) {
//         cout << "3";
//     }
//     return 0;
// }

//--------------------
// template<class T>
// inline T func(T x) {
//     T res = x * x;
//     return res;
// }
// template<>
// string func<string>(string str) {
//     return (str+str);
// }
// int main() {
//     int x = 2, y; 
//     string str("itf");
//     y = func<int>(x); 
//     cout << x << y << func<string>(str);
// }
//----------------------------------------------------------------
// struct myexception:public exception {
//     const char* what() const throw () { return "C++ exxception";}
// };
// int main () {
//     try {
//         throw myexception();
//     }
//     catch (myexception&e) {
//         cout << "exeoption caught: " << e.what() << endl;
//     }
// }
//----------------------------------------------------------------
// void func (char c) {
//     if (c<numeric_limits<char>::max())
//         return 
// }
//----------------------------------------------------------------
// class a {
//     public: 
//         virtual void func();
// };
// class b {
//     public: 
//         void func();
// };
// int main () {
//     int a = sizeof(a), b = sizeof(b);
//     if (a==b) cout << "hehe";
// }
//---------------------------------
// int main() {
//     vector<int> obj; 
//     obj.assign(3,4); 
//     for(int i = 0; i < obj.size(); i++){
//         cout << obj[i];
//     }
// }
//----------------------------------------
// int main(){
//     try {
//         throw 1;
//     }
//     catch (int &e) {
//         cout << "Error: " << e;

//     }
//     return 0;
// }
//-------------------------------------
// template <class T>
// T func (T&x; T &y)
// {
//     cout << "1"; 
//     reuturn (x>y)? x:y;
// }
// template <>
// {
//     cout << "1"; 
//     reuturn (x>y)? x:y;
// }

//----------------------------------------------
// class a {
//     public: a(); ~a(); 
//     private: 
//     protected:
// };
// a::a(){}
// a::~a(){}
// int main() {
//     cout << "Run";
//     system("pause");
// }
//----------------------------------------
// template <class T, class U> 
// class exam {
//     T pro_x;
//     U pro_y;
// };
// int main(){
//     exam<char,char> c;
//     exam<int,int> i; 
//     cout << sizeof(c) << sizeof(i);
// }
//-----------------------------------------------
#include <bitset>
// int main() {
//     bitset<8>  b1(20); 
//     cout << b1.test(1);
//     cout << b1.test(2);

// }
//----------------------------------
