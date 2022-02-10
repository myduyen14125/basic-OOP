#include <bits/stdc++.h>
using namespace std;

// Đềcủa Hiền 
// class exam {
//     int var1, var2;
//     public:  
//         exam(int);
//         ~exam();
//         void func();
// };

// exam::exam(int var1) : var1 {var2 + 1}, var2 {var1 + 1} {

// }
// exam::~exam() {}
// void exam::func() {
//     cout <<this->var1 << " " << this->var2;
// }
// int main() {
//     exam obj(5);
//     obj.func();
// }

// Đề của hiền ---------------------------------------
// class Base {
//     int prop; 
//     public: 
//         void setProp(int); 
//         int getProp(); 
// };
// void Base::setProp(int prop) {
//     this->prop=prop; 
//     // cout << prop << "hehe";
// }
// int Base::getProp() {
//     return this->prop; 
//     cout << "goi getprop";
// }
// class Derived:public Base {
//     int prop; 
//     public: 
//         void setprop(int); 
//         int func(); 
// };
// void Derived::setprop(int) {
//     this->prop=prop; 
// }
// int Derived::func() {
//     return this->prop * getProp(); //Lỗi ở đây ra giá trị rác vì getProp chưa được gọi tới
// }
// int main() {
//     Base obj1;
//     Derived obj2;
//     obj2.setProp(15); 
//     cout<<obj2.func(); 
//     return 0; 
// }

// Bài 1 Phúc-------------------------------------
// class exam {
//     int prop;
//     public:
//         exam(int);
//         int operator()(int);
// };
// exam::exam(int prop) {
//     this->prop = prop;
// }
// int exam::operator()(int prop) {
//     return this->prop + prop;
// }
// int main() {
//     exam obj(5);
//     int var_i = 5; 
//     cout << obj(var_i); // vì gọi obj(abc) nên đã gọi tới operator() nên đã cộng vô nè hehe
// }


// ----------------------------------------------------------------
// #define max 10
// int main() {

// }

// Bài 2 Phúc-----------------------------------------
// class base {
//     int x;
//     public:  
//         base(int = 1);
//         int operator,(int);
// };
// base::base(int x):x{x} {};
// int base::operator,(int x) {return x;}
// int main() {
//     base obj; 
//     int x = 2;
//     cout << obj.operator,(x);
    
//     return 0;
// }
// ======> Kết quả ra = 2 bình thường, có thể đa năng hóa được nè 
// Các toán tử không thể đa năng hóa: . .? :: .* sizeof


// Bai 3 Phuc 
// Đa năng hóa toán tử postfix++  
// base operator++ (int) 
// Tiền tố: Có & mà không có (int) 
// Hậu tố: có (int) mà không có & 
// Prototype: 
//     mynum& mynum::operator++() //tăng trước 
//     const mynum mynum::operator++(int) //tăng sau 
// vd như: ++x = 5 là được vì là tham chiếu 
//         x++=5 thì compile vì là const 


// Bài 4 Phúc 
// int myaccumulator(int x, int y) {
//     return x-y;
// }
// int myproduct(int x, int y) {
//     return x+y;
// }
// int main() {
//     int a = 100; 
//     int series1[] = {10,20,30};
//     int series2[] = {1,2,3};
//     cout << inner_product(series1, series1+3, series2, a, myaccumulator, myproduct);
//     // cout << inner_product(series1, series1 + 3, series2, 0);
// }
// ====> Kết quả bằng 34
// Mặc định là init là + , trong 2 series là nhân tích từng cặp. khi custom lại thì: hàm đầu (myaccumulator) là trừ sẽ dùng với init, còn myproduct là + sẽ dùng với từng cặp. 
// Kết quả: 100 - (10+1) - (20+2) - (30+3) = 34


// Bài 5 Phúc 
// class exam {
//     int arr[10]; 
//     public:
//         int &operator[] (const int&);
// };
// int &exam::operator[] (const int& index) {
//     return this->arr[index];
// }
// int main() {
//     exam obj;  
//     obj[5] = 4;
//     cout << obj[5];
// }
// ====> Kết quả ra 4 thôi, không lỗi gì cả


// Bài 5 Phúc-----------------------------------------
// class base {
//     int x;
//     public:  
//         base(int = 1);
//         int operator,(int);
// };
// base::base(int x):x{x} {};
// int base::operator,(int x) {return this->x;}
// int main() {
//     base obj; 
//     int x = 2;
//     cout << obj.operator,(x);
//     return 0;
// }
// ======> Kết quả ra = 1 nè, chú ý đoạn return: return x là lấy x ở dưới hàm main luôn, tức là x truyền vô, còn return this->x là lấy x được khởi tạo từ phút giây ban đầu. 


// Bài 6 Phúc 
// ostream &operator <<(ostream &out, int var_x) {
//     return out;
// }
// int main() {
//     cout << 5;
//     cin.get(); 
//     return 0;
// }
// Lỗi compile, ambiguous overload for ‘operator<<’ (operand types are ‘std::ostream’. Do bị mơ hồ không biết gọi tới << nào. 


// Câu 23 Phúc
// Không định nghĩa lại hàm đa năng khác kiểu trả về: ví dụ: void foo() và int foo() 
// All except: 
// int func3(int *ptr, int n) 
// int func(int ptr[], int n)


// Bài 8 Phúc 
// class base {
//     int x; 
//     public:
//         void fun(double, int, char); 
//         void fun(double, char, char);
// };
// void base::fun(double, char y, char z) {
//     this->x = char(z); //x = int (A) = 65 
//     // this->x = int(y); //x = 65 + 65 = 130
//     // this->x = y+z; 
//     cout << x;
// }
// int main() {
//     base obj; 
//     obj.fun(15.09, 'A', char('A' + 'A'));
//     return 0;
// }
// Ascii char A = 65 
// this-> x = z ===> -126 nên 65 -126 = -61
// this->x = char(z) => = -126 ;
// 'A' + 'A' = -126; 'A' + 'B' = -125 hehe
// Kết quả -61. 



// Bài 9 Phúc 
// struct Struct {
//     public: 
//         int addition(int, int = 10);
//         double addition(int, double);
// };
// int Struct::addition(int x, int y) {
//     return (x *= y + 2);
// }
// int main() {
//     Struct obj; 
//     cout << obj.addition(1) <<" "<<obj.addition(3,4);
//     return 0;
// }
// =====> Kết quả 18. Không lỗi chi hết, chạy bình thường nè 


// Bài 10 Phúc 
// int Func(int,int); 
// int Func(int,int,int);
// int main() {
//     cout<<Func(2,4); // => runtime:: mơ hồ 
//     return 0;
// } 
// int Func(int x,int y) {
//     return x*y;
// }
// int Func(int x, int y, int z=5) {
//     return x*y*z; 
// }
// //===> Kết quả ra 8. do dòng 244, hàm 
//     int Func(int x, int y, int z=5) 
// định nghĩa ở dưới, nên không ảnh hưởng chi đến nguyên mẫu hàm ở trên. Main hắn sẽ gọi tới hàm fun1 và in ra 8 như bình thường. 
// Nếu mà bỏ z = 5 ở trên nguyên mẫu hàm luôn thì lỗi runtime, mập mờ nì.
// Nếu bỏ đi int fun(int x, int y) + đưa nguyên mẫu hàm nớ lên trên thì ra 40 như bình thường. Còn nếu k xóa thì hắn coi như có 2 hàm nên lỗi runtime ó. 


// Bài 11 Phúc 
// class Complex {
//     int r, i; 
//     public: 
//         Complex(int = 0, int = 0);
// };
// Complex::Complex(int r, int i) {
//     this->r = r;
//     this->i = i;
// }
// int main() {
//     Complex obj1(10,5), obj2(2,4);
//     (obj1 == obj2) ? cout << "Same" : cout << "Not"; 
//     return 0;
// }
// Compile err do toan tu == chua dinh nghia 


// Bai 12 Phuc 
// class Exam {
//     public: 
//         void operator () (int); 

// }; 
// void  Exam::operator () (int i) {
//     cout<<i; 
// }
// int main() {
//     Exam obj; 
//     obj(5);   // chạy bth ra 5
//     return 0; 
// }
// ==> Chay binh thuong ra 5. Operator () xuat ra phan tu. 


// Bai 13 Phuc 
// class base {
//     private: 
//         void * operator new(size_t size) {}  //line 1 //nếu k có cái ni là dòng 3 oke nè
//         void * operator new[](size_t size) {} //line 2
// };
// int main() {
//     base *ptr1 = new base; //line 3. com err do operator * là private
//     base *ptr2 = new base[10]; //line 4. cũng com err luôn tương tự. 
//     return 0;
// }


// Bài 14 Phúc 
// int main () {
//     set<int> myset; 
//     myset.insert(20); 
//     myset.insert(30); 
//     myset.insert(10);
//     while (!myset.empty())
//     {
//         cout<<" "<<*myset.begin();
//         myset.erase(myset.begin()); 
//     }
//     cout<<'\n';   // => 10 20 30 chạy bth mà set là có sắp xếp
//     return 0; 
// }
// => Kết quả: 10 20 30 set là có sắp xếp lại đó hehe


// Câu 15 tòn
// int main() {
//     complex <double> cn(3.0, 4.0); 
//     cout << "Norm is: " <<norm(cn);
//     return 0;
// }
// Định thức số phức: norm: thực bình + ảo bình. > kết quả ra 25 nè. 


// Câu 16 Phúc 
// template <class T> 
// T Func(const T var_x, const T var_y) {
//     cout << "no specilization";
//     return var_x < var_y ? var_y : var_x;
// }

// template<> 
// const char* Func(const char* var_x, const char* var_y){
//     cout << "goi ham duoi ne";
//     return (strcmp(var_x, var_y) < 0) ? var_y : var_x;
//     //vi var_x, var y < 0
// }
// int main() {
//     const char* ptr_x = "class";
//     const char* ptr_y = "template";
//     const char* ptr_z = Func(ptr_x, ptr_y);
//     cout << ptr_z;
//     return 0;
// }
// Ra template, chay ham duoi -> kiem tra x, y < 0.hắn ưu tiên cái hàm không truyền template vô trước, nếu k có, ví dụ như kiểu int, double... dưới chưa có định nghĩa thì hắn gọi tới cái ở trên nè. 


// Cau 17 Note 
// class base{
// 	int arr[10];
// };
// class b1: public base{
	
// };
// class b2:public base{
	
// };
// class devired : public b1, public b2{
	
// };
// int main() {
// 	cout<<sizeof(devired);
// 	// ra 80 
// 	// vi
// 	// thua ke b1 co 1 mang 10 phan tu kieu int(4 byte) => 10.4 = 40
// 	// thua ke b2 co 1 mang 10 phan tu kieu int(4 byte) => 10.4 = 40
// 	return 0;
// }


// Cau 18 Note 
// int main() {
// 	tuple <int, char, string> tp1; //khai báo, định nghĩa tuple
// 	tp1 = make_tuple(6, 'a', "Hello"); //gán giá trị cho tuple bằng make_tuple
// 	int x;
// 	string y;
// 	tie(x, ignore, y) = tp1; //tie() giải nén tuple thành các biến riêng biệt thì ra các giá trị x y rầu
// 	cout<<"x: "<<x<<"\ny: "<<y<<endl;
// 	// x: 6
// 	// y: Hello
// }
// make_tuple() is used to assign tuple with values. The values passed should be in order with the values declared in tuple. (được sử dụng để gán bộ giá trị, giá trị ra theo order)


// Cau 19 
// class Exam{
// 	public:
// 		virtual ~Exam();
// };
// Exam::~Exam() {
	
// }
// int main() {
// 	// khong loi: hàm hủy dùng virtual bình thường, hàm dựng thì không được dùng nè. 
// 	return 0;
// }


// Cau 20 
// template <class T, class U, class V = double>
// class Exam{
// 	T x;
// 	U y;
// 	V z;
// };
// int main() {
// 	Exam<int , int> i;
// 	Exam<double, double> d;
// 	cout<<sizeof(i)<<sizeof(d);
// 	// 1624
// 	// sizeof(i) = 16 do co 2 int, 1 double => 4 + 4 + 8 =16
// 	// sizeof(d) = 24 do co 3 double => 3 * 8 = 24
//     //Vì 1 class có 3 thành phần, nên hắn sẽ thay kiểu cho phù hợp, và có đủ cả 3 cái. Nếu truyền zô 2 cái thì nhận 2. 
// }


// Cau 21  
// int main () {
//     double x=10, y=5, z;
//     char Operator='/';
//     try {
//         if (y==0) throw "Errol"; 
//         z=x/y; 
//         cout<<x<<"/"<<y<<"="<<z; 
//     }
//     catch (const char* e) {
//         cout<<"bad operator"<<e; 
//     }
//     return 0; 
// } //chạy bth ra 10/5=2


// Cau 22 
// int main() {
// 	try{
// 		throw 20;
// 	}
// 	catch (int e) {
// 		cout<<"An exxception occurred "<<e;
// 	}
// 	// ket qua: An exxception occurred 26
// 	// nem ra so nguyen nen e = 20
// }


// Cau 23 (tức 21/50)
// int main() {
// 	multiset<int> mymultiset;
	
// 	for(int i = 0; i < 5; i++) {
// 		mymultiset.insert(i);
// 	}
// 	multiset<int> ::key_compare compare = mymultiset.key_comp();
// 	// key_compare: tra lai ban sao doi tuong so sanh
//     //compare nớ bằng multiset cái trên luôn 
//     //gọi hàm key_comp() để so sánh 
// 	// tra ve true: neu doi so 1 < doi so 2
// 	// tra ve false: neu doi so 1 > doi so 2
	
// 	int highest = *mymultiset.rbegin();
// 	// luu tru gia tri phan tu cuoi cung
// 	// highest = 4

// 	multiset<int> ::iterator it = mymultiset.begin();
// 	// iterator: khai bao doi tuong de duyet
//     //iterator là con trỏ => it con trỏ *it nè 

// 	do{
// 		cout<<' '<<*it;
// 	}
// 	while(compare(*it++, highest)); //tức là khi hắn khác là hắn cứ làm tiếp, khi chưa hết ơ. 
// 	return 0;
// }
// ket qua: 0 1 2 3 4



// Câu 25/50 
// int main() {
//     vector<int> a(3,0); 
//     vector<int> b(5,0);
//     b = a; //size b từ 5 -> = 3 
//     a = vector<int>(); //size a = 0 
//     cout << int(a.size()) << int(b.size());
//     return 0;
// }
// Ra 0 3 


// Câu 26 
// template<typename T, int count> 
// void Func(T var_x) {
//     T arr[count]; 
//     for(int i = 0; i < count; ++i) { //arr lưu kiểu double, i: 0->2
//         arr[i] = var_x++; //postfix
//         cout << arr[i] << " ";
//     }
// }
// int main() {
//     double x = 2.1; 
//     Func<double, 3>(x); 
//     return 0;
// }
// ra 2.1 3.1 4.1, vẫn cộng được cho số thực  


// Câu 27 
// template <class T>
// T Func(T &x, T &y) {
//     return (x > y) ? x : y; 
// }
// int main () {
//     int x = 5, y = 6, z;
//     long i = 10, j = 5, k; 
//     z = Func(x,y);   // return 6
//     k = Func(i,j);  //return 10
//     cout << z << k;   //610
//     return 0; 
// }


// Câu 28 
// template <class T>
// T Func(T x) {
//     cout<<x; 
//     return x; 
// }
// int Func(int x) {
//     cout<<x;
//     return x; 
// }
// int main() {
//     int x=5; 
//     int y=Func(x);  //5
//     double z=Func(5.5); //5.5
//     return 0;   
// }
// Ra 55.5
