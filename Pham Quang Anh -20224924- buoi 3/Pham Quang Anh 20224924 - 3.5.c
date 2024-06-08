#include <iostream>
using namespace std;

int binom(int n, int k) {
    if (k > n) return 0;
    if (k == 0) return 1;
    return binom(n-1, k) + binom(n-1, k-1);
}
int binomp[1000][1000];
int binom2(int n, int k){

    //# Khử đệ quy
    /*****************
    Pham Quang Anh 20224924
    *****************/
    if (k > n)
    {   binomp[n][k]=0;
        return 0;
    }
    if (k == 0||k==n)
    {   binomp[n][k]=1;
        return 1;
    }
    if(binomp[n][k]==-1)
    {  int ans=binom2(n-1,k)+binom2(n-1,k-1);
       binomp[n][k]=ans;
       return binomp[n][k];}
       else{return binomp[n][k];}


}

int main() {
    int m;
    cin >> m;
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom(n, k));
        printf("\n");
    }
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=m;j++)
        {
            binomp[i][j]=-1;
        }
    }
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom2(n, k));
        printf("\n");
    }
    return 0;
}

