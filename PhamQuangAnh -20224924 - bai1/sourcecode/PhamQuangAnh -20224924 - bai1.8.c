#include<stdio.h>


void allocate_mem(int ***mt, int m, int n){
    //#Allocate memory for the matrix

    /*****************
    Pham Quang Anh 20224924
    *****************/
    //cap phat bo nho cho 1 mang gom m con tro
    *mt= new int *[m];
             for (int i=0; i< m; ++i) {
             *(*mt+i) = new int [n]; //cap phat bo nho cho cac phan tu cua mang
             }
              }


void input(int **mt, int m, int n){
    //#Input elements of the matrix

    /*****************
    Pham Quang Anh 20224924
    *****************/
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&mt[i][j]);//nhap vao cac phan tu cua mang
        }
    }
}

void output(int **mt, int m, int n){
    //# Print all elements of the matrix

    /*****************
    Pham Quang Anh 20224924
    *****************/
      for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("mt[%d][%d] = ",i,j);//in ra mt[i][j] theo yeu cau
        }

    }
       for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",mt[i][j]);// in ra gia tri cua mt[i][j]
        }
        printf("\n");

    }

}

int process(int **mt, int m, int n){
    int tong = 0;
    //# Calculate the sum of all even elements in the matrix
    /*****************
    Pham Quang Anh 20224924
    *****************/
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mt[i][j]%2==0)
            { tong+=mt[i][j];}//tinh tong cua cac phan tu la so chan
        }
    }

    return tong;// tra ve tong nhan duoc
}

void free_mem(int **mt, int m, int n){
    //# Free memory

    /*****************
    Pham Quang Anh 20224924
    *****************/
    for(int i=0;i<m;i++)
     {delete [] mt[i]; } // giai phong bo nho cho tung hang
     delete [] mt;// giai phong bo nho cho mang cac con tro

}

int main(){
    int m, n, **mt;
    printf("Enter m, n = ");
    scanf("%d%d", &m, &n);
    allocate_mem(&mt, m, n);
    input(mt, m, n);
    output(mt, m, n);
    printf("The sum of all even elements is %d", process(mt, m, n));
    free_mem(mt, m, n);
    return 0;
}
