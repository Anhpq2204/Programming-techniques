#include <bits/stdc++.h>
using namespace std;


long kc[10000][10000], dd[10000], sl_dd;
long dd_ht[10000], dd_tu[10000], cp_ht, cp_tu, cp_min = 1e9;

// Ham khoi tao cac gia tri ban dau
void kt(){
    dd_ht[0] = dd[0];
    dd_ht[sl_dd] = dd[sl_dd];
    cp_ht = 0;
    cp_tu = 1e9;
}

// Ham kiem tra dia diem da tham chua
int check(int dd_kt, int buoc_ht){
    for (int i = 1; i <= buoc_ht; i++)
        if (dd_kt == dd_ht[i]) return 0;
    return 1;
}

// Ham tim duong di toi uu bang de quy
void solve(int buoc_ht){
    for (int chi_so_dd_tt = 1; chi_so_dd_tt < sl_dd; chi_so_dd_tt++){
        if (!kc[dd_ht[buoc_ht-1]][dd[chi_so_dd_tt]]) continue;
        if (!check(dd[chi_so_dd_tt], buoc_ht)) continue;
        if ((buoc_ht + 1 == sl_dd)) {
            if (!kc[dd[chi_so_dd_tt]][dd[sl_dd]]) continue;
        }

        dd_ht[buoc_ht] = dd[chi_so_dd_tt];
        cp_ht += kc[dd_ht[buoc_ht-1]][dd[chi_so_dd_tt]];
        if (buoc_ht + 1 == sl_dd){
            if (cp_ht + kc[dd[chi_so_dd_tt]][dd[sl_dd]] < cp_tu){
                cp_tu = cp_ht + kc[dd[chi_so_dd_tt]][dd[sl_dd]];
            }
        } else {
            if (cp_ht + cp_min * (sl_dd - buoc_ht - 1) < cp_tu)
                solve(buoc_ht + 1);
        }
        cp_ht -= kc[dd_ht[buoc_ht-1]][dd[chi_so_dd_tt]];
        dd_ht[buoc_ht] = 0;
    }
}

// Ham in chi phi toi uu
void in() {
    if (cp_tu == INT_MAX) cp_tu = 0;
    cout << cp_tu << endl;
}

int main() {
    int sl_dinh, sl_td;
    cin >> sl_dinh >> sl_td;
    string td[sl_td + 1];

    // Doc ma tran khoang cach
    for (int i = 1; i <= sl_dinh; i++)
        for (int j = 1; j <= sl_dinh; j++){
            cin >> kc[i][j];
            if (kc[i][j] != 0)
                cp_min = (cp_min > kc[i][j]) ? kc[i][j] : cp_min;
        }
    cin.ignore();

    // Doc cac tuyen duong
    for (int j = 0; j <= sl_td; j++) {
        getline(cin, td[j]);
    }

    // Xu ly tung tuyen duong
    for (int j = 1; j <= sl_td; j++){
        stringstream ss(td[j]);
        vector<int> duongDi;
        while (!ss.eof()){
            int dd_them;
            ss >> dd_them;
            duongDi.push_back(dd_them);
        }
        sl_dd = duongDi.size() - 1;
        for (int i = 0; i <= sl_dd; i++){
            dd[i] = duongDi[i];
        }
        kt();
        solve(1);
        in();
    }
    return 0;
}
