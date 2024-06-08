#include <stdio.h>

void print(int n) {
    printf("n=%d\n", n);
}

int mul3plus1(int n) {  //ham nhan 3 cong 1
    return n * 3 + 1;
}

int div2(int n) { //hang chia 2
    return n / 2;
}

// khai báo các tham số cho các con trỏ hàm odd, even và output
void simulate(int n,int (*odd)(int),int (*even)(int),void (*output)(int))  {
    (*output)(n);
    if (n == 1) return;
    if (n % 2 == 0) {
        n = (*even)(n);
    } else {
        n = (*odd)(n);
    }
    simulate(n, odd, even, output);
}

int main() {
    //khai bao cac con tro ham
    int (*odd)(int) = NULL;
    int (*even)(int) = NULL;

    /*****************
    Pham Quang Anh 20224924
    *****************/
    odd=mul3plus1;
    even=div2;


    int n;
    scanf("%d", &n);
    simulate(n, odd, even, print);//truyen cac con tro ham vao ham

    return 0;
}
