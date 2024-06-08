#include <bits/stdc++.h>

using namespace std;

int n;
string str;
int dem = 0, kq = 0; // dem: biến đếm, kq: kết quả
map<int, int> mp; // Map lưu trữ độ chênh lệch giữa số lượng 1 và 0

void input() { // Ham nhap du lieu
    cin >> str;
    n = str.length();
}

int tinh(int b) { // Ham tinh tong cac so tu 1 den b-1
    int foo = 0;
    for (int i = 1; i < b; i++) {
        foo += i;
    }
    return foo;
}

void solve() { // Ham giai quyet
    int slg0 = 0, slg1 = 0; // slg0: so luong 0, slg1: so luong 1
    map<int, int>::iterator it;

    for (int i = 0; i < n; i++) {
        if (str[i] == '0') slg0++;
        else slg1++;

        int chenhLech = slg1 - slg0; // Do chenh lech 0 va 1
        it = mp.find(chenhLech);
        if (it != mp.end()) { // Neu do chenh lech da ton tai
            it->second += 1;
        } else {
            mp.insert({chenhLech, 1});
        }
    }

    it = mp.begin();
    while (it != mp.end()) {
        kq += tinh(it->second);
        if (it->first == 0) kq += it->second;
        it++;
    }
}

int main() {
    input();
    solve();
    cout << kq;
    return 0;
}
