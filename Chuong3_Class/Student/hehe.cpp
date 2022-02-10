#include <iostream>
using namespace std;

class SV {
  private:
    double _DTB;
    string _name;
  public:
    SV(double = 0.0, string = "");
    ~SV();
    double getDTB();
    string getName();
    void show();
};

class QLSV {
  private:
    SV *p;
    int n;
  public:
    QLSV();
    ~QLSV();
    void show();
    void sort();
    void add(SV);
};

SV::SV(double dtb, string name) : _DTB(dtb), _name(name) {}


double SV::getDTB() {
  return this->_DTB;
}

string SV::getName() {
  return this->_name;
}

SV::~SV() {

}

void SV::show() {
  cout << "NAME: " << this->_name << ", DTB: " << this->_DTB << endl;
}

QLSV::QLSV() {
  this->n = 0;
  this->p = nullptr;
}

QLSV::~QLSV() {}

void QLSV::add(SV s) {
  if (this->n == 0) {
    this->p = new SV[this->n + 1];
    this->p[this->n] = s;
  } else {
    SV *temp = new SV[this->n];
    for (int i = 0; i < this->n; i++) {
      temp[i] = (this->p)[i];
    }
    delete[] p;
    this->p = new SV[this->n + 1];
    for (int i = 0; i < this->n; i++) {
      (this->p)[i] = temp[i]; 
    }
    (this->p)[this->n] = s; 
  }
  this->n++;
}

void QLSV::show() {
  for (int i = 0; i < this->n; i++) {
    (this->p)[i].show();
  }
}

void QLSV::sort() {
  for (int i = 0; i < this->n - 1; i++) {
    for (int j = i + 1; j < this->n; j++) {
      if (this->p[j].getDTB() < this->p[i].getDTB()) {
        SV s = this->p[j];
        this->p[j] = this->p[i];
        this->p[i] = s;
      }
    }
  }
}

int main() {
  QLSV qlsv;
  qlsv.add(SV(3.3, "Minh"));
  qlsv.add(SV(4.3, "Duyen"));
  qlsv.add(SV(3.7, "Duyen beo"));
  qlsv.add(SV(2.3, "Duyen ngao"));
  qlsv.sort();
  qlsv.show();
}