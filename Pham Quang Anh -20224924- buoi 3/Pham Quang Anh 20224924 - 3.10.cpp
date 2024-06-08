#include<bits/stdc++.h>
using namespace std;

char x[100]; // xau duoc sinh ra
char S[100]; // xau de bai cho voi n ki tu 0
int dem = 0;
int N, H;

int checkHamming(char str1[], char str2[]) { // dem so ky tu khac nhau o 2 xau
    int length = N;
    int dem = 0;
    for (int i = 0; i < length; i++) {
        if (str1[i] != str2[i]) dem++;
    }
    return dem;
}

void in() { // in ket qua
    if (checkHamming(x, S) == H) {
        for (int i = 0; i < N; i++)
            cout << x[i];
        cout << endl;
    }
}

void TRY(int a) { // ham sinh xau thoa man yeu cau
    for (int i = 0; i <= 1; i++) {
        x[a] = i + '0'; // Chuyển từ số nguyên 0 hoặc 1 sang ký tự '0' hoặc '1'
        if (a == N - 1) in();
        else
            TRY(a + 1);
    }
}

int main() {
    int T;
    cin >> T;
    while (T > 0) {
        cin >> N >> H;
        for (int i = 0; i < N; i++) {
            S[i] = '0';
        }
        S[N] = '\0'; // Đảm bảo xâu S kết thúc bằng ký tự null

        for (int i = 0; i < N; i++) {
            x[i] = '0';
        }
        x[N] = '\0'; // Đảm bảo xâu x kết thúc bằng ký tự null

        TRY(0);
        T--;
    }
    return 0;
}
