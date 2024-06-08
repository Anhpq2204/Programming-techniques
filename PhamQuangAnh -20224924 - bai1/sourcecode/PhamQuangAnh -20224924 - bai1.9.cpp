#include <stdio.h>
#include <stdlib.h>

void allocate(int **q,int siz) //ham cap phat bo nho
{
    *q=new int[siz];
}
void freemem(int *q)// ham giai phong bo nho
{
    delete []q;
}
void input(int *q,int siz)//ham m=nhap so lieu
{
    for(int i=0;i<siz;++i)
    {
        scanf("%d",&q[i]);
    }
}
/*****************
    Pham Quang Anh 20224924
    *****************/

void process(int *q,int siz)//ham xu ly yeu cau
{
    for(int i=0;i<siz;i++)
    {
        for(int j=i;j<siz;j++)
        {
            for(int k=i;k<=j;k++)
            {
                printf("%d ",q[k]);
            }
              printf("\n");
        }

    }
}

int main()
{
    int *q;//khai bao con tro
    int n;//khai bao kich thuoc mang
    scanf("%d",&n);
    allocate(&q,n);
    input(q,n);
    process(q,n);
    freemem(q);
    return 0;


}

