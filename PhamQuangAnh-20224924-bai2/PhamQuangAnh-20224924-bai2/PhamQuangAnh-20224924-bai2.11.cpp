#include <iostream>
using namespace std;
/*Pham Quang Anh 20224924*/
struct dathuc {
    int bac;
    long long *heso; //con tro tro den mang luu tru he so
};

void input(dathuc& a) {
    int s;
    cin >> s;
    a.bac = s;
    a.heso = new long long[s + 1];
    for (int i = 0; i < s + 1; i++) {
        cin >> a.heso[i];
    }
}

long long xuly(const dathuc& a, const dathuc& b) {
    dathuc c;
    c.bac = a.bac + b.bac;    //da thuc ket qua co bac M+N
    c.heso = new long long[c.bac + 1]();
    for (int i = 0; i <= a.bac; i++) {
        for (int j = 0; j <= b.bac; j++) {
            c.heso[i + j] += a.heso[i] * b.heso[j];  //c^(i+j)=a^i*b^j
        }
    }

    long long res = c.heso[0];
    for (int i = 1; i < c.bac + 1; i++) {
        res ^= c.heso[i];  //xor cac hhe so
    }

    delete[] c.heso;
    return res;
}

int main() {
        for(int i=0;i<5;i++)
  {
    cout << "case = " << i+1 << endl;
    cout << "input = ";
    dathuc a, b;
    input(a);
    input(b);
    long long res = xuly(a, b);
    cout << res;}
    return 0;
}
