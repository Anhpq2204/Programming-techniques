
int counteven(int* arr, int size){
    int count = 0;//khoi tao bien dem =0

    /*****************
    Pham Quang Anh 20224924
    *****************/
    for(int i=0;i<size;i++)
    {
        if(*(arr+i)%2==0){ count++;}//neu phan tu la so chan tang bien count len 1
    }

    return count;
}
