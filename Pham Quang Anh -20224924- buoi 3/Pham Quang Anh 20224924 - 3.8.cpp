#include <bits/stdc++.h>
using namespace std;

struct state{
    int i, j, k;//i: so luong cac qua can
    //j: trang thai cua qua can
    //k: tinh tong cac qua can hien co
    state(int _i = 0, int _j = 0, int _k=0): i(_i), j(_j), k(_k){}
};

int main() {
    int n, M;
    cin >> n >> M;
    int m[n+1];
    for (int i = 1; i <= n; ++i) cin >> m[i];
    int x[n+1];//luu trang thai cua qua can : giu nguyen,them ,bot
    stack<state> s;
    //# sum of selected weights
    int sum = 0;
    s.push(state(1, -1, -m[1]));
    s.push(state(1, 0, 0));
    s.push(state(1, 1, m[1]));
    while (!s.empty()){
        state top = s.top();
        if (top.i >= n){
            if (top.k == M){
                for (int i = 1; i <= n; ++i){
                    if (x[i] == -1) cout << '-' << m[i];
                    if (x[i] == 1) cout << '+' << m[i];
                }
                cout << "=" << M;
                exit(0);
            }
            s.pop();
            continue;
        }

        //# Khử đệ quy
        s.pop();
        x[top.i]=top.j;//lay trang thai cua qua can thu i
        s.push(state(top.i+1, -1, top.k-m[top.i+1])); //3 trang thai ung voi giu nguyen,them,bot cac qua can
        s.push(state(top.i+1, 0,top.k));
        s.push(state(top.i+1, 1,top.k+m[top.i+1]));
    }
    cout << -1;

    return 0;
}

