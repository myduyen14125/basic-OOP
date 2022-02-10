#ifndef POINT_H
#define POINT_H

class Point {
    private:
        static int count; //thanh vien du lieu tinh 
        //chi duoc cap phat 1 vung nho duy nhat de dung cho tat ca cac doi tuong duoc dinh nghia thuoc lop Point
        int x, y;
    public:
        Point() { 
            x = y = 0;
        }; //constructor khong có đối số - hàm dựng mặc định, không cần truyền tham số vào, default constructor
        Point(int, int); //default constructor
        Point(const Point &p); //phải là tham chiếu, tham trị (k có dấu và, thì bị lỗi)
        Point(double, double);
        ~Point() {count--;};
        void SetPt(int, int);
        void OfsetPt(int, int);
        void Display();
        static void PrintCount();
};

#endif