#include <stdio.h>

void rotate(int &x, int &y, int &z) {
    /*****************
    Pham Quang Anh 20224924
    *****************/
    int c;//khai bao bien trung gian
    //thuc hien hoan doi cac bien
    c=y;
    y=z;
    z=x;
    x=c;
}

int main() {
    int x, y, z;

    //# Nhập 3 số nguyên
    /*****************
    Pham Quang Anh 20224924
    *****************/
    scanf("%d %d %d",&x,&y,&z);

    printf("Before: %d, %d, %d\n", x, y, z);
    rotate(x, y, z);//hoan doi cac so nguyen
    printf("After: %d, %d, %d\n", x, y, z);

    return 0;
}
