//Cài đặt 1 ngăn xếp cấp phát động 
// Ứng dụng ngăn xếp để đổi 1 số từ hệ thập phân sang hệ thập lục phân 
#ifndef STACK_H
#define STACK_H

class Stack {
    private:
        int size; //Kich thuoc ngan xep 
        int *data;
        int top; //dinh ngan xep 
    public:
        Stack(int n = 4);
        Stack(const Stack &);
        ~Stack() {delete [] data;};
        bool Push(int x); //Push vao ngan xep 
        bool Pop(int &x); //Pop ra khoi ngan xep 
        bool isFull(); //Check if size === top 
        bool isEmpty();
};

#endif