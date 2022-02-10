#include <iostream>
#include "Vecto.cpp"
using namespace std;
int main()
{
    Vecto<int> a, c;
    Vecto<int> b;
    bool flag;
    do
    {
        flag = true;
        try
        {
            cout << "Nhập vecto a: " << endl;
            cin >> a;
            b = a;
            cout << "Vecto b:" << b;
            cout << "Nhập lại vecto b: " << endl;
            cin >> b;
        }
        catch (const invalid_argument &e)
        {
            std::cerr << e.what() << '\n';
            flag = false;
        }
        catch (const bad_alloc &e) //không thể cấp phát bộ nhớ
        {
            std::cerr << e.what() << '\n';
            flag = false;
        }
        catch (...)
        {
            flag = false;
        };

    } while (flag == false);

    try
    {
        cout << "a[3] = ";
        cout << a[3] << endl;
    }
    catch (const out_of_range &e)
    {
        std::cerr << e.what() << '\n';
    };

    try
    {
        c = a + b;
        cout << "Vecto a :" << a;
        cout << "Vecto b :" << b;
        cout << "Vecto c = a + b:" << c;
        c = a - b;
        cout << "Vecto c = a - b:" << c;
        cout << "Tích vô hướng b * c = " << b * c << endl;
        cout << "Phan tu thu 2 cua c: " << c[1] << endl;
    }
    catch (const invalid_argument &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (const bad_alloc &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (...)
    {
        cout << "Invalid error!" << endl;
    };

    return 0;
}