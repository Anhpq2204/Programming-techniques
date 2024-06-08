#include <stdio.h>

//# Viết hàm get_value

int get_value(int x,int a=2,int b=1, int c=0) //ham voi 4 tham so duoc khoi tao ngam dinh
{
    return (a*x*x+b*x+c);
}

int main(){
    int x;
    scanf("%d", &x);

    int a = 2; //# giá trị mặc định của a
    int b = 1; //# giá trị mặc định của b
    int c = 0; //# giá trị mặc định của c

    //# Nhập 3 số nguyên a, b, c từ bàn phím
    /*****************
    Pham Quang Anh 20224924
    *****************/
    scanf("%d %d %d",&a,&b,&c);

    printf("a=2, b=1, c=0: %d\n", get_value(x));  // thuc hien ham khi khuyet a b c
    printf("a=%d, b=1, c=0: %d\n", a, get_value(x, a)); // thuc hien ham khi khuyet b c
    printf("a=%d, b=%d, c=0: %d\n", a, b, get_value(x, a, b));// thuc hien ham khi khuyet c
    printf("a=%d, b=%d, c=%d: %d\n", a, b, c, get_value(x, a, b, c));// thuc hien ham khi co day du cac tham so

    return 0;
}
