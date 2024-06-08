#include <stdio.h>

int cube(int x) {
    //# trả về lập phương của x voi x la so nguyen
    /*****************
    Pham Quang Anh 20224924
    *****************/
    return x*x*x;
}

//# viết hàm tính lập phương của một số kiểu double

double cube(double x) {
    //# trả về lập phương của x voi x la so thuc
    /*****************
    Pham Quang Anh 20224924
    *****************/
    return x*x*x;
}

int main() {
    int n;
    double f;
    scanf("%d %lf", &n, &f);

    printf("Int: %d\n", cube(n)); //in ra gia tri cua ham khi x la so nguyen
    printf("Double: %.2lf\n", cube(f));//in ra gia tri cua ham khi x la so thuc

    return 0;
}
