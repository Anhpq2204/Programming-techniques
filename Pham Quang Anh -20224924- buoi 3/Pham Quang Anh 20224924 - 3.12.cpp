#include <bits/stdc++.h>
using namespace std;

int sl_dinh, sl_canh_cau, sl_canh;
int dd[100], ma_tran_ke[100][100];
int so_luong_ket_qua = 0;
int so_luong_canh_hien_tai = 0;

// Ham kiem tra dinh da tham chua
int daTham(int diem, int buoc_ht) {
    for (int i = 1; i < buoc_ht; i++)
        if (diem == dd[i]) return 1;
    return 0;
}

// Ham de quy tim duong di
void thu(int buoc_ht) {
    for (int i = 1; i <= sl_dinh; i++) {
        if (!ma_tran_ke[dd[buoc_ht - 1]][i]) continue;
        if (daTham(i, buoc_ht)) continue;

        dd[buoc_ht] = i;
        so_luong_canh_hien_tai++;

        if (so_luong_canh_hien_tai == sl_canh_cau) {
            so_luong_ket_qua++;
        } else {
            thu(buoc_ht + 1);
        }

        so_luong_canh_hien_tai--;
        dd[buoc_ht] = 0;
    }
}

int main() {
    vector<pair<int, int>> canh;
    cin >> sl_dinh >> sl_canh_cau >> sl_canh;

    // Khoi tao ma tran ke
    for (int i = 1; i <= sl_dinh; i++) {
        for (int j = 1; j <= sl_dinh; j++) {
            ma_tran_ke[i][j] = 0;
        }
    }

    // Doc cac canh
    for (int i = 0; i < sl_canh; i++) {
        int d1, d2;
        cin >> d1 >> d2;
        canh.push_back(make_pair(d1, d2));
    }

    // Cap nhat ma tran ke
    for (int t = 0; t < sl_canh; t++) {
        ma_tran_ke[canh[t].first][canh[t].second] = 1;
        ma_tran_ke[canh[t].second][canh[t].first] = 1;
    }

    // Thu tung dinh bat dau
    for (int t = 1; t <= sl_dinh; t++) {
        dd[1] = t;
        so_luong_canh_hien_tai = 0;
        thu(2);
    }

    cout << endl << so_luong_ket_qua / 2;
    return 0;
}
