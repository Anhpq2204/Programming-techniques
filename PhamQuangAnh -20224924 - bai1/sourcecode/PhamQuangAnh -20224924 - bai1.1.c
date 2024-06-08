# include <stdio.h>
#include<stdlib.h>
int main(){
    int x, y, z;// khai bao 3 bien x,y,z
    int* ptr;//khai bao con tro ptr
    printf("Enter three integers: ");
    scanf("%d %d %d", &x, &y, &z);
    printf("\nThe three integers are:\n");
    ptr = &x;// gan dia chi bien x cho con tro ptr
    printf("x = %d\n", *ptr);
       /*****************
    Pham Quang Anh 20224924
    *****************/
    int* ptr1,*ptr2;//khai bao 2 con tro ptr1 va ptr2
    ptr1=&y;//gan dia chi bien y cho con tro ptr
    printf("y = %d\n",*ptr1);
    ptr2=&z;//gan dia chi bien z cho con tro ptr
    printf("z = %d\n",*ptr2);
    return 0;
}

