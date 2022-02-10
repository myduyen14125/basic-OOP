#include<iostream>
#include <iomanip>
#include <string>
using namespace std;

class Date{
    private:
        int day;
        int month;
        int year;
    public:
        Date() {
            day = 1;
            month = 1;
            year = 2021;
        }; //Constructor default 
        Date(int day, int month, int year) {
            this->day = day;
            this->month = month;
            this->year = year;
        }; //constructor full info
        Date(const Date &d) {
            this->day = d.day;
            this->month = d.month;
            this->year = d.year;
        }; //ham dung sao chep
        ~Date(){};

        void setDate() {
            cout << "\tNhap ngay: ";
            cin >> this->day;
            cout << "\tNhap thang: ";
            cin >> this->month;
            cout << "\tNhap nam: ";
            cin >> this->year;
        }; //Nhap
        void display() {
            if(day < 10) cout << "0" << day << "/";
            else cout << day << "/";
            if(month < 10) cout << "0" << month << "/";
            else cout << month << "/";
            cout << year << endl;
        }; //Xuat

        void setDay(int day) {this->day = day;}
        void setMonth(int month) {this->month = month;}
        void setYear(int year) {this->year = year;}
        int getDay() {return day;}
        int getMonth() {return month;}
        int getYear() {return year;}
};


class PhongKS {
    private: 
        string maPhong;
        int soNguoi;
        bool tinhTrang;
        Date ngayNhan;
        Date ngayTra;
        double giaPhong;
    public: 
        PhongKS() {
            maPhong = "";
            soNguoi = 0;
            tinhTrang = false;
            Date ngayNhan(0,0,0);
            Date ngayTra(0,0,0);
            giaPhong = 0;
        };
        PhongKS(string ma, int so, bool check, Date day1, Date day2, double gia) {
            maPhong = ma;
            soNguoi = so;
            tinhTrang = check;
            ngayNhan = day1;
            ngayTra = day2;
            giaPhong = gia;
        };
        PhongKS(const PhongKS &p) {
            maPhong = p.maPhong;
            soNguoi = p.soNguoi;
            tinhTrang = p.tinhTrang;
            ngayNhan = p.ngayNhan;
            ngayTra = p.ngayTra;
            giaPhong = p.giaPhong;
        };
        void NhapKS() {
            string temp;
            int n;
            bool check1 = false, check2 = false;
            do {
                cout << "Nhap ma phong: ";
                cin >> temp;
                if (temp.length() > 5) {
                    cout << "Ma phong khong hop le!";
                    check1 = false;
                }
                else {
                    maPhong = temp;
                    check1 = true;
                }
            } while (check1 = false);
            do {
                cout << "Nhap so nguoi: ";
                cin >> n;
                if (n < 1 || n > 4) {
                    cout << "So nguoi khong hop le!";
                    check2 = false;
                }
                else {
                    soNguoi = n;
                    check2 = true;
                }
            }while (check2 = false);
            cout << "Nhap tinh trang phong da thue/chua thue (1/0): ";
            cin >> tinhTrang;
            cout << "Nhap ngay nhan phong: " << endl;
            ngayNhan.setDate();
            cout << "Nhap ngay tra phong: " << endl; 
            ngayTra.setDate();
            cout << "Nhap gia phong: ";
            cin >> giaPhong;
        }
        void XuatKS() {
            cout << endl;
            cout << "- Ma phong: " << maPhong << endl;
            cout << "- So nguoi: " << soNguoi << endl;
            cout << "- Tinh trang: " << tinhTrang << endl;
            cout << "- Ngay nhan: "; ngayNhan.display();
            cout << "- Ngay tra: "; ngayTra.display();
            cout << "- Gia phong: " << giaPhong << endl;
        }

        int getMaPhong() { //chuyen ma phong ve int
            int code = stoi(maPhong);
            return code;
        };
        void setMaPhong(string maPhong) {
            this->maPhong = maPhong;
        }
};

bool ascending(int l, int r);
bool descending(int l, int r);
void swap(PhongKS &num1, PhongKS &num2);
int partition (PhongKS *arr, int low, int high, bool (*func_ptr)(int , int));
void quickSort(PhongKS *arr, int low, int high, bool (*func_ptr)(int, int)=ascending);
class List {
    public: 
        int n; 
        PhongKS *data;
    public:
        List(int n = 3);
        List(const List &);
        ~List() {
            delete [] data;
        }

        void Nhap();
        void Xuat() const;

        
        int getSize() {return n;}

        void themDau(); 
        void themCuoi();
        void themBatKy();

        void xoaDau();
        void xoaCuoi();
        void xoaBatKy();

        void update();
        int interpolSearch(int x);
        void sapXepQuickSort(bool (*func_ptr)(int, int)=ascending);
};
List::List(int m):n(m){
    data = new PhongKS [n];
}
List::List(const List &ds):n(ds.n){
    data = new PhongKS [n];
    for(int i = 0; i < n; i++){
        data[i] = ds.data[i];
    }
}
void List::Nhap(){
    cout << "Nhap so phong khach san: " ; 
    cin >> n;
    for(int i = 0; i < n; i++){
        cout <<"Nhap khach san thu "<< i+1 << ":" <<endl;
        this->data[i].NhapKS();
    }
}
void List::Xuat() const{
    for(int i = 0; i < n; i++) {
        cout << setw(3) << i+1;
        data[i].XuatKS();
        cout << "---------" << endl;
    }
}

void List::themDau() {
    int size = this->n + 1;
    PhongKS *b = new PhongKS[size];
    for(int i = size-1; i >= 1; i--) {
        b[i] = this->data[i-1];
    }
    cout<<"Nhap khach san can them: "<<endl;
    b[0].NhapKS();
    delete [] data;
    this->data = new PhongKS[size];
    this->n = size;
    for (int i = 0; i < size; i++)
        this->data[i] = b[i];
}
void List::themCuoi() {
    int size = this->n + 1;
    PhongKS *b = new PhongKS[size];
    for(int i = 0; i < size - 1; i++) {
        b[i] = this->data[i];
    }
    cout<<"Nhap khach san can them: " << endl;
    b[size-1].NhapKS();

    delete [] data;
    this->data = new PhongKS[size];
    this->n = size;
    for (int i = 0; i < size; i++)
        this->data[i] = b[i];
}
void List::themBatKy() {
    int index;
    do {
        cout<<"Nhap vi tri can chen: ";
        cin>>index;
        if(index <0 || index>n)     cout<<"Vi tri ban nhap khong hop le !!!"<<endl;
    } while(index<0 || index>n);

    if(index==0) {
        themDau();
    }
    else if(index == n) {
        themCuoi();
    }
    else{
        int size = this->n + 1;
        PhongKS *b = new PhongKS[size];
        for(int i = 0; i < index; i++) {
            b[i] = this->data[i];
        }
        cout<<"Nhap phan tu can them: "<<endl;
        b[index].NhapKS();
        for(int i = index + 1; i < size;i++) {
            b[i] = this->data[i-1];
        }
        delete [] data;
        this->data = new PhongKS[size];
        this->n = size;
        for (int i = 0; i < size; i++)
            this->data[i] = b[i];
    }
}
void List::xoaDau() {
    for(int i = 0; i < n-1; i++) {
        data[i] = data[i+1];
    }
    this->n--;
}
void List::xoaCuoi() {
    this->n--;
}
void List::xoaBatKy() {
    int index;
    do {
        cout<<"Nhap vi tri can xoa: ";
        cin>>index;
        if(index <0 || index>n-1)     
        cout<<"Vi tri ban xoa khong hop le !!!"<<endl;
    } while(index<0 || index>n-1);
    for(int i = index; i < n-1; i++) {
        data[i] = data[i+1];
    }
    this->n--;
}
void List::update() {
    string ma;
    int index;
    do {
        cout<<"Moi ban nhap ma so phong can thay doi: ";
        cin>>ma;
        int maPhong = stoi(ma);
        index = interpolSearch(maPhong);
        if(index == -1) {
            cout<<"Ma phong khong hop le.\n";
            cout<<"Vui long nhap lai ma so phong.\n";
        }
    } while(index == -1);
    cout<<"Moi ban nhap ma phong moi: ";
    cin>>ma;
    this->data[index].setMaPhong(ma);
}
//Sap xep ne, sap xep quicksort 
bool ascending(int l, int r){
    return l > r;
}

bool descending(int l, int r){
    return l < r;
}

void swap(PhongKS &num1, PhongKS &num2){
    PhongKS a = num1;
    num1 = num2;
    num2 = a;
}

int partition (PhongKS *arr, int low, int high, bool (*func_ptr)(int , int)){ 
    int pivot = arr[high].getMaPhong(); // pivot 
    int i = low - 1;
  
    for (int j = low; j <= high - 1; j++) 
    { 
        if (!(*func_ptr)(arr[j].getMaPhong(),pivot)) 
        { 
            i++;
            swap(arr[i], arr[j]); 
        } 
    } 
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
} 

void quickSort(PhongKS *arr, int low, int high, bool (*func_ptr)(int, int)) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high, func_ptr); 
        quickSort(arr, low, pi - 1, func_ptr); 
        quickSort(arr, pi + 1, high, func_ptr); 
    } 
} 
void List::sapXepQuickSort(bool (*func_ptr)(int, int)) {
    quickSort(data, 0, this->n - 1, func_ptr);
}

int List::interpolSearch(int x) {
    int left = 0;
    int right = n-1;
    while (left <= right && x >= data[left].getMaPhong() && x <= data[right].getMaPhong())
    {
        double val1 = (double) (x - data[left].getMaPhong()) / (data[right].getMaPhong()-data[left].getMaPhong());
        int val2 = (right-left);
        int Search = left + val1*val2;
    
        if (data[Search].getMaPhong() == x)
        return Search;
    
        if (data[Search].getMaPhong() < x)
        left = Search + 1;
        else
        right = Search - 1;
    }
    return -1;
}

int main() {
    List l; 
    l.Nhap();
    cout << "Danh sach khach san vua nhap: " << endl;
    l.Xuat();
    while (1) {
        cout << "----MENU----" << endl;
        cout << "1. Them dau" << endl;
        cout << "2. Them cuoi" << endl;
        cout << "3. Them bat ki" << endl;
        cout << "4. Quicksort" << endl;
        cout << "5. Tim kiem Inter" << endl;
        cout << "6. Xoa dau" << endl;
        cout << "7. Xoa cuoi" << endl;
        cout << "8. Xoa bat ky" << endl;
        cout << "9. Update" << endl;
        cout << "10. Xuat List" << endl;
        cout << "11. Thoat" << endl;
        int option;
        cout << "Nhap lua chon: " ; cin >> option;
        if (option == 1) {
            l.themDau();
        }
        else if (option == 2) {
            l.themCuoi();
        }
        else if (option == 3) {
            l.themBatKy();
        }
        else if (option == 4) {
            cout << "Interpolation Search - Nhap so muon tim: ";
            int x; cin >> x;
            l.interpolSearch(x);
        }
        else if (option == 4) {
            l.sapXepQuickSort();
        }
        else if (option == 6) {
            l.xoaDau();
        }
        else if (option == 7) {
            l.xoaCuoi();
        }
        else if (option == 8) {
            l.xoaBatKy();
        }
        else if (option == 9) {
            l.update();
        }
        else if (option == 10) {
            l.Xuat();
        }
        else {break;}
    }
    
    l.Xuat();
}