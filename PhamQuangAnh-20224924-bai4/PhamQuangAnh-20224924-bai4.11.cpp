#include <bits/stdc++.h>

using namespace std;

struct dt { // Cau truc luu tru du lieu
    int ai; // So luong ke dich ban dau
    int ki; // So luong ke dich co the tieu diet moi luot

    dt(int ai, int ki) { // Ham khoi tao
        this->ai = ai;
        this->ki = ki;
    }
};

struct cp { // Cau truc so sanh cho priority_queue
    bool operator() (dt a, dt b) {
        int ra, rb;

        if (a.ai <= a.ki) ra = a.ai;
        else ra = a.ki;

        if (b.ai <= b.ki) rb = b.ai;
        else rb = b.ki;

        return ra < rb;
    }
};

int n, s, ke, te; // n: so luong tran, s: so luot, ke: so luong ke dich tieu diet, te: tong so ke dich
priority_queue<dt, vector<dt>, cp> Q; // Hang doi uu tien

void input() { // Ham nhap du lieu
    cin >> n >> s;
    ke = 0;
    te = 0;
    for (int i = 0; i < n; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        te += t1;
        Q.push(dt(t1, t2));
    }
}

void solve() { // Ham giai quyet
    while (!Q.empty() && s > 0) {
        dt inf = Q.top();
        Q.pop();

        if (inf.ai <= inf.ki) ke += inf.ai;
        else {
            int sl = inf.ai - inf.ki; // So luong ke dich con lai
            Q.push(dt(sl, inf.ki));
            ke += inf.ki;
        }

        s -= 1;
    }
}



int main() {
    input();
    solve();
    cout << te-ke;
    return 0;
}
