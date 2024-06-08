#include<bits/stdc++.h>
using namespace std;
int x[10000]; //luu trang thai lam viec cua cac ngay
int lam = 0; //bit chi so ngay lam
int n, k1, k2;
bool check(int  a, int  i){ //kiem tra xem co thoa man yeu cau bai toan hay khong
    if(a==1) return true;
    else {
        if(!i)
        { //neu hom truoc nghi thi hom sau khong duoc nghi
            if(x[a-1] == 0) {return false;}
            else
            {
                if(lam<k1) {return false;}
            }
        }
        else
        {
            if(x[a-1] == 0)
            {
                if(n-a+1 < k1) return false;
            }
        else
            {
                if(lam >=k2) return false;
            }
        }

        return true;
    }
}

void solve(){
    for(int i=1; i<=n; i++)
        cout << x[i];
    cout << endl;
}

void TRY(int  a){
    for(int  i=0; i<=1; i++){
        if(check(a,i)){
            x[a] = i; // ngay thu a lam viec hoac khong lam viec
            int songay = lam; //bien trung gian luu cac ngay lm viec trc
            if(i)
            {
                if(x[a-1] == 1) lam++;
                else lam = 1;
            }
            else
            {
                lam = 0;
            }
            if(a==n) solve();
            else TRY(a+1);
            lam = songay;
        }
    }
}

int main(){
    cin >> n >> k1 >> k2;
    TRY(1);
    return 0;
}
