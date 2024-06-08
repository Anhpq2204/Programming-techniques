#include <iostream>

using namespace std;

/*****************
    Pham Quang Anh 20224924
    *****************/

void allocate(int ***q,int n)//ham cap phat bo nho
{
    *q= new int*[n];
    for(int i=0;i<n;++i)
    {
        //**(q+i)=new int[n];
        *(*q+i) = new int [n];
    }
}
void freemem(int **q,int r)
{    for(int i=0;i<r;i++)
{
    delete []q[i];
}
    delete []q;
}
void input(int **q,int n )
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;j++)
        {
           cin>>q[i][j];
        }

    }
}
void tong(int **a,int **b,int **c,int n)
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }

}
void tich(int **a,int **b,int **c,int n)
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        { int sum=0;
            for(int u=0;u<n;u++)
            {
                sum+=a[i][u]*b[u][j];
            }
            c[i][j]=sum;
        }

    }
     for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }


}
 /*****************
    Pham Quang Anh 20224924
    *****************/



int main()
{
    int **a,**b,**c;
    int n;
    scanf("%d",&n);
    allocate(&a,n);
    allocate(&b,n);
    allocate(&c,n);
    input(a,n);
    input(b,n);
    tong(a,b,c,n);
    tich(a,b,c,n);
    freemem(a,n);
    freemem(b,n);
    freemem(c,n);
    return 0;


}
