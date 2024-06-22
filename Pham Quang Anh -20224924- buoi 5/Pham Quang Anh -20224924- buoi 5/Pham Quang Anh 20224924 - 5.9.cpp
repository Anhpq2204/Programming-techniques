#include <bits/stdc++.h>
using namespace std;

struct block {
    int x, y, z;
};

int n;
block a[300];
int maxh[300];

void input(){
    cin >> n;
    if (n == 0) exit(0);
    int x, y, z;
    for (int i = 1; i <= n; i++){
        cin >> x >> y >> z;
        a[3 * i - 3] = {x, y, z};
        a[3 * i - 2] = {y, z, x};
        a[3 * i - 1] = {z, x, y};
    }
}

int dp(int i){
    if (maxh[i] != 0) return maxh[i];
    maxh[i] = a[i].z;
    for (int j = 0; j < 3 * n; j++){
        if ((a[i].x < a[j].x && a[i].y < a[j].y) ||
            (a[i].x < a[j].y && a[i].y < a[j].x)){
            maxh[i] = max(maxh[i], a[i].z + dp(j));
        }
    }
    return maxh[i];
}

int main(){
    int cnt = 1;
    while (true) {
        fill(begin(maxh), end(maxh), 0);
        input();
        int res = 0;
        for (int i = 0; i < 3 * n; i++){
            res = max(res, dp(i));
        }
        printf("Case %d: maximum height = %d\n", cnt++, res);
    }
    return 0;
}
