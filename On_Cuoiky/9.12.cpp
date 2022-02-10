#include <bits/stdc++.h>
using namespace std;

// Cau 1
//  template<class T, class U, class V = double>
//  class exam {
//      T x;
//      U y;
//      V z;
//  };
//  int main() {
//      exam<int, int> i;
//      exam<double, double> d;
//      cout << sizeof(i) << " " << sizeof(d); //16 24 , 16 = 4(int) + 4(int) + 8(double), 24 = 8*3
//      return 0;
//  }
 //Nếu không định nghĩa biến thuộc class V thì sẽ k tốn kiểu dữ liệu khi gọi exam<type1, type2>

// Cau 2
//  template <class T>
//  class Exam {
//      public:
//          Exam();
//          ~Exam();
//  } ;
//  template <typename T>
//  Exam<T>::Exam() {
//      cout<<"C";
//  }
//  template <typename T>
//  Exam<T>::~Exam() {
//      cout<<"D";
//  }
//  int main() {
//      Exam obj;  // compile phải Exam <int/char/...>, khi có template thì lúc tạo đối tượng phải thêm kiểu cho nó.
//      return 0;
//  }

// Câu 3
//  template<class T>
//  class Exam {
//      T prop;
//      public:
//          static int count;
//          Exam();
//          ~Exam();
//  };
//  template<class T>
//  int Exam<T>::count = 0;
//  template<class T>
//  Exam<T>::Exam() {
//      Exam<T>::count++;
//  }
//  template<class T>
//  Exam<T>::~Exam() {}
//  int main() {
//      Exam<int> x;
//      Exam<int> y;
//      Exam<double> z;
//      cout << Exam<int>::count << " " << Exam<double>::count;
//      return 0;
//  }
// Ra 2 1. Exam<int> = 2 vì có x, y -> qua 2 hàm dựng. Exam<double> = 1.



// Câu 4
//  int main() {
//      complex <double> obj_d (4.0, 3.0);
//      complex <float> obj_f (polar(5.0, 0.75));
//      cout<<(obj_d += sqrt(obj_d));
//      //(6.12132,3.70711)
//  }
// Cách tìm căn bậc 2 số phức:  dùng hệ pt đó .
// The polar function is used to find the complex number from phase angle and magnitude.: tìm cực trị và số pha
// số phức biểu diễn lên mặt phẳng giống cái toạ độ cực

// Câu 5
//  class base {
//      public:
//          virtual void show();
//  };
//  void base::show() {
//      cout << "B";
//  }
//  class derived: public base {
//      public:
//          void show();
//  };
//  void derived::show() {
//      cout << "D";
//  }
//  int main() {
//      base *bp = new derived();
//      bp->base::show();
//      return 0;
//  }
// Ra B. Upcast: con trỏ bp được tạo bằng derived nhưng upcast gọi lên hàm show của lớp cha.


// Câu 6.
//  class Base {
//      int x,y,z;
//      public:
//          Base() {
//              x=y=z=0;
//          }
//          Base (int xx, int yy='A', int zz='B') {
//              x=xx; y=x+yy; z=x+y;
//          }
//          void Display() {
//              cout<<x<<y<<z;
//              cout << "hehe";
//          }
//  };
//  class Derived:public Base {
//      int x,y;
//      public:
//          Derived(int xx=65, int yy=66):Base(xx,yy) {
//              y=xx; x=yy;
//          }
//          void Display() {
//              //lap vo han o day
//              cout<<x<<y;
//              Display();    //không có dòng ni thì không bị lặp, ra 6665 nè.
//          }
//  };
//  int main() {
//      Derived objD;
//      objD.Display();
//      return 0;
//  }
// ra 66656665...... lặp vô hạn. -> another answer


// Câu 7
//  template <class T, class U>
//  class exam {
//      T x;
//      U y;
//  };
//  int main() {
//      exam<char,char> cc; //char = 1 byte
//      exam<int, int> ii; //int = 4 byte
//      cout << sizeof(cc) << " " << sizeof(ii); //ra 28
//      return 0;
//  }
//  char  : 1 byte
//  short : 2 bytes
//  int   : 4 bytes
//  long  : 4 bytes
//  float : 4 bytes
//  double: 8 bytes


// Câu 8
// int Func(char x, ...) {
//     return x; //trả về tham số đầu tiên trong tất cả tham số truyền vô func
// }
// int main() {
//     int x, y;
//     x = Func('A', 1, 2, 3);
//     y = Func('1', 1.0, 1, '1', 1.0f, 1l);
//     cout << x << y; // 6549 chạy bth 65 là của 'A' còn 49 là của '1'
//     return 0;
// }
// ... vẫn nhận hết tham số truyền vô. 


//Câu 9. 
// const int bsize = 512; 
// int * pa; 
// bool allocate = true; 
// void get_memory() {
//     cerr << "free store exhausted" << endl;
//     delete[] pa; 
//     allocate = false;
// }
// void eat_memory(int size) {
//     int *p = new int[size]; 
//     if (allocate) 
//         eat_memory(size);
//     else 
//         cerr << "free store addr = " << p << endl;  
// }
// int main() {
//     set_new_handler(get_memory); //đầu tiên là get bộ nhớ ra
//     pa = new int[bsize];  //cho con trỏ pa với kích thước
//     cerr << "free store addr = " << pa << endl; 
//     eat_memory(bsize); //ăn bộ nhớ 
//     return 0;
// }
//Ra free store addr = 0x557b6eb0feb0 .
//Chạy xong, ăn xong bộ nhớ thì lỗi runtime vì bị lỗi phân đoạn, k tìm ra chỗ để thực thi nữa
//The new-handler function is the function called by allocation functions whenever a memory allocation attempt fails. Its intended purpose is one of three things: 



//Câu 10 
// double Func(int x, int y) {
//     if (y==0) {
//         throw "Error!";
//     } 
//     return x/y; 
// }
// int main() {
//     int x = 50; 
//     int y = 0; 
//     double z = 0; 
//     try {
//         z = Func(x,y); 
//         cout << z; 
//     }
//     catch (const char* e) {
//         cout<<e; 
//     }
//     return 0; 
// }  
//kq: Error!  do y=0 chay bth, throw ra error, e = error! 


//Câu 11 
// class Myexception : public exception {
//     virtual const char* what() const throw() { 
//         return "My exception";
//     }
// } me;
// int main() {
//     try {
//         throw me;
//     }
//     catch (exception &e) {
//         cout << e.what() << endl;
//     }
//     return 0;
// }
// //Kq: My exception. 
//  const char* what() const throw();
//  |-> return type
//              |-> name of the method
//                  |-> parameter
//                     |-> it is a const method
//                           |-> exception specification
// => Nó là một phương thức const được gọi là phương thức what() không nhận tham số, trả về một const char * và được chỉ định để không ném ra một ngoại lệ.


//Câu 12  ~ note cau 31 file 10.12.cpp
// class Base {
//     private:
//     /* data */
//     public:
//         Base();
//         ~Base(); //chú ý: base không dùng virtual -> không thừa kế đến con thì không gọi DD
// };
// Base::Base(/* args */) {
//     cout<<"CB"; 
// }
// Base::~Base() {
//     cout<<"DB"; 
// }
// class Derived :public Base {
//     private:
//     /* data */
//     public:
//         Derived(/* args */);
//         ~Derived();
// };
// Derived::Derived(/* args */) {
//     cout<<"CD"; 
// }
// Derived::~Derived() {
//     cout<<"CD"; 
// }
// int main(void) {
//     Derived* ptrd=new Derived();   // CBCD Derived() gọi construction của Base và Derived luôn
//     Base* ptrb = ptrd; // chỉ có con trỏ k gọi construction, cho con trỏ kiểu Base trỏ tới địa chỉ con trỏ ptrd thôi. 
//     delete ptrb;  // DB gọi destruction của B, vì là kiểu Base 
// } 
//kq: CBCDDB



//Câu 13.  
// int main() {
//     forward_list<int> fl1 = {1,2,3,4,5};
//     forward_list<int>::iterator ptr = fl1.begin(); //con trỏ trỏ đến vị trí begin của fl1 = 1. 
//     fl1.erase_after(ptr); //xóa sau con trỏ là xóa 2
//     for(int& c : fl1) {
//         cout << c << " ";
//     }
//     return 0;
// }
//kq: 1 3 4 5 