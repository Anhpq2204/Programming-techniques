#include <iostream>
using namespace std;

//# viết hàm arr_sum
/*****************
Pham Quang Anh 20224924
*****************/
//dinh nghia template
template <typename T>
T arr_sum(T a[],int c, T b[],int d)
{
    double sum=0;
    for(int i=0;i<c;i++)
    {
        sum+=a[i];
    }
    for(int j=0;j<d;j++)
    {
        sum+=b[j];
    }
    return sum;
}

int main() {
    int val;
    cin >> val;

    {
        int a[] = {3, 2, 0, val};
        int b[] = {5, 6, 1, 2, 7};
        cout << arr_sum(a, 4, b, 5) << endl; //cong hai mang so nguyen
    }
    {
        double a[] = {3.0, 2, 0, val * 1.0};
        double b[] = {5, 6.1, 1, 2.3, 7};
        cout << arr_sum(a, 4, b, 5) << endl;//cong hai mang so thuc
    }

    return 0;
}
