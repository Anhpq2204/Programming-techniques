#include <iostream>
using namespace std;

int *a;
int n, tmp;

int main(){
    cout<<"Enter the number of elements: ";
    cin>>n;

    //#Allocate memory

    /*****************
    Pham Quang Anh 20224924
    *****************/
    //cap phat bo nho cho mang
    a= new int[n];

    for(int i = 0; i < n; i++)
        cin>>*(a+i);//nhap vao cac phan tu cua mang

    cout<<"The input array is: \n";
    for(int i = 0; i < n; i++)
        cout<<*(a+i)<<" ";//in ra cac phan tu cua mang
    cout<<"\n";

    //#Sort array

    /*****************
    Pham Quang Anh 20224924
    *****************/
    //sap xep mang bang bubble sort
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(*(a+i)>*(a+j))
            {
                tmp=*(a+i);
                *(a+i)=*(a+j);
                *(a+j)=tmp;
            }
        }
    }

    printf("The sorted array is: \n");
    for(int i = 0; i < n; i++)
        cout<<*(a+i)<<" ";
    cout<<"\n";
    //giai phong bo nho da cap phat cho mang
    delete [] a;
    return 0;
}
