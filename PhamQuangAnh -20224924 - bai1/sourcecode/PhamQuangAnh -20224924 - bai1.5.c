double* maximum(double* a, int size){
    double *max;// khai bao con tro tro den vi tri gia tri max
    max = a;//cho con tro max tro den phan tu dau tien cua mang
    if (a==NULL) return NULL;//neu mang rong tra ve NULL

    /*****************
    Pham Quang Anh 20224924
    *****************/
    for(int i=0;i<size;i++)
    {
        if(*(a+i)>*max){max=a+i;}//neu co phan tu > max gan dia chi phan tu do cho max
    }

    return max;
}
