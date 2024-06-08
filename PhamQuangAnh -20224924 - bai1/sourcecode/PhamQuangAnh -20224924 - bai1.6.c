void reversearray(int arr[], int size){
    int l = 0, r = size - 1, tmp; //khai bao cac bien l,r la cac chi so va tmp la bien tam thoi

    /*****************
    Pham Quang Anh 20224924
    *****************/
    //dao nguoc mang bang cach dung them 1 bien tam thoi
    //su dung chi so
    for(int i=l;i<size/2;i++)
    {
        tmp=arr[i];
        arr[i]=arr[r-i];
        arr[r-i]=tmp;
    }
}

void ptr_reversearray(int *arr, int size){
    int l = 0, r = size - 1, tmp;////khai bao cac bien l,r la cac chi so va tmp la bien tam thoi

    /*****************
    Pham Quang Anh 20224924
    *****************/
    //dao nguoc mang bang cach dung them 1 bien tam thoi
    //su dung con tro
    for(int i=l;i<size/2;i++)
    {
        tmp=*(arr+i);
        *(arr+i)=*(arr+r-i);
        *(arr+r-i)=tmp;
    }

}
