#include <string>
using namespace std;
#ifndef MATHSET_H
#define MATHSET_H

class Mathset {
    private:
        int *data;
        int size;
    public:
        Mathset();
        Mathset(int [], int);
        Mathset(const Mathset &);
        ~Mathset() {delete[] data;};
        Mathset operator+(const Mathset &a);
        Mathset operator-(const Mathset &a);
        Mathset operator*(const Mathset &a);
        Mathset operator+(int);
        Mathset operator-(int);
        const Mathset &operator=(const Mathset&);
        int &operator [](int) const;
        bool operator ()(int);
        friend ostream &operator << (ostream&, const Mathset &);
};

#endif