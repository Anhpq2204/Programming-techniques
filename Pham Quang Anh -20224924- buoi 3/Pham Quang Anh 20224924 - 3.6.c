#include <iostream>
using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int gcd2(int a, int b){

    //# Khử đệ quy
    /*****************
   Pham Quang Anh 20224924
    *****************/
    int ans=0;
    while(a!=0)
    {
        if(a==b){ ans=1;}
        else{
            if(a>b){a%=b;}
            else{b%=a;}
        }
        ans=b;
    }
    return ans;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl << gcd2(a, b);
    return 0;
}

