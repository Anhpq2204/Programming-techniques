#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip>

using namespace std;
//dinh nghia so phuc
struct Complex {
    double real;
    double imag;
};
//da nang hoa toan tu +
Complex operator + (Complex a, Complex b) {

    Complex p;
    p.real=a.real+b.real;
    p.imag=a.imag+b.imag;
    return p;
}
//da nang hoa toan tu -
Complex operator - (Complex a, Complex b) {

    Complex p;
    p.real=a.real-b.real;
    p.imag=a.imag-b.imag;
    return p;
}
//da nang hoa toan tu *
Complex operator * (Complex a, Complex b) {

    Complex p;
    p.real=a.real*b.real-a.imag*b.imag;
    p.imag=a.real*b.imag+b.real*a.imag;
    return p;
}
//da nang hoa toan tu /
Complex operator / (Complex a, Complex b) {

     Complex p;
    p.real=(a.real*b.real+a.imag*b.imag)/(b.real*b.real+b.imag*b.imag);
    p.imag=(-a.real*b.imag+b.real*a.imag)/(b.real*b.real+b.imag*b.imag);
    return p;

}
//da nang hoa toan tu <<
ostream& operator << (ostream& out, const Complex &a) {
    out << '(' << std::setprecision(2) << a.real << (a.imag >= 0 ? '+' : '-') << std::setprecision(2) << fabs(a.imag) << 'i' << ')';
    return out;
}

int main() {
    double real_a, real_b, img_a, img_b;
    cin >> real_a >> img_a;
    cin >> real_b >> img_b;

    Complex a{real_a, img_a};
    Complex b{real_b, img_b};

    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;

    return 0;
}
