
#include <stdio.h>
#include <math.h>

float get_hypotenuse(float x, float y) { //ham tinh canh huyen
    /*****************
    Pham Quang Anh 20224924
    *****************/
    return sqrt(x*x+y*y);
}

int main(){
    float x, y; //khai bao x,y
    scanf("%f%f", &x, &y);//nhap vao 2 canh goc vuong

    float z = get_hypotenuse(x, y);//tinh canh huyen
    printf("z = %.2f\n", z);//tinh canh huyen

    return 0;
}
