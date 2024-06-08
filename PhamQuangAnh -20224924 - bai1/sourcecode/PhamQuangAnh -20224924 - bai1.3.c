#include <stdio.h>
int main()
{
    int x, y, z;//khai bao 3 bien x,y,z
    int *ptr;//khai bao con tro ptr
    scanf("%d %d %d", &x, &y, &z);
    printf("Here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x, y, z);

    /*****************
    Pham Quang Anh 20224924
    *****************/
    ptr=&x;//gan dia chi bien x cho con tro ptr
    *ptr+=100;//tang gia tri cua x len 100
    ptr=&y;//gan dia chi bien y cho con tro ptr
    *ptr+=100;//tang gia tri cua y len 100
    ptr=&z;//gan dia chi bien z cho con tro ptr
    *ptr+=100;//tang gia tri cua z len 100
    printf("Once again, here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x, y, z);
    return 0;
}

