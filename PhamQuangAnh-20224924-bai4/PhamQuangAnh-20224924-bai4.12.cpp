#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> vt; // Mang luu tru gia tri dau vao
vector<long long> L;  // Mang trai luu tru gia tri ben trai gan nhat nho hon gia tri dang xet
vector<long long> R;  // Mang phai luu tru gia tri ben phai gan nhat nho hon gia tri dang xet

void input() { // Ham nhap du lieu
    cin >> n;
    vt.push_back(-1); // Dat linh canh o 2 dau mang
    for (long long i = 0; i < n; i++) {
        long long t;
        cin >> t;
        vt.push_back(t);
    }
    vt.push_back(-1); // Dat linh canh o 2 dau mang
}

void slove() { // Ham giai quyet
    while (true) {
        input();
        if (n == 0) return;

        stack<long long> st; // Stack de thuc hien thuat toan ghi ra cac gia tri L, R
        L.resize(n + 2);
        R.resize(n + 2);

        // Tinh mang L
        for (long long i = 1; i <= n + 1; i++) {
            while (!st.empty() && vt[i] < vt[st.top()]) {
                L[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        // Tinh mang R
        for (long long i = n; i >= 0; i--) {
            while (!st.empty() && vt[i] < vt[st.top()]) {
                R[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        long long maxh = 0; // Gia tri lon nhat cua hinh chu nhat

        // Tinh gia tri lon nhat cua hinh chu nhat
        for (long long i = 1; i <= n; i++) {
            long long h = (L[i] - R[i] - 1) * vt[i];
            if (h > maxh) maxh = h;
        }

        cout << maxh << endl;
        break;

        // Xoa mang truoc khi bat dau vong lap moi
        vt.erase(vt.begin(), vt.end());
        L.erase(L.begin(), L.end());
        R.erase(R.begin(), R.end());
    }
}

int main() {
    solve();
    return 0;
}
