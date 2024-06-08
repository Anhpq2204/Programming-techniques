#include<iostream>
#include<ctype.h>
#include<stdlib.h>
#include<cstring>
using namespace std;
/* Pham Quang Anh 20224924*/

struct bigNum {
    char sign;
    char num[101];
};
//ham nhap du lieu dau vao
void input(bigNum &a, bigNum &b){
    string h,k; //hai xau de nhan 2 so dau vao
    cin >> h>>k;
    a.sign = h[0];
    b.sign = k[0];
    int len = h.length() - 1;
    int len1 =k.length() - 1;
    for (int i = 0; i < len; i++){
        a.num[101-len+i] = h[i+1];  //sao chep so tu h vao a
    }
    for (int i = 0; i < len1; i++){
        b.num[101-len1+i] = k[i+1];  //sao chep so tu k vao b
    }
    for (int i = 0; i < 101-len; i++){
        a.num[i] = '0';             //gan phan con lai la 0
    }
    for (int i = 0; i < 101-len1; i++){
        b.num[i] = '0';                //gan phan con lai la 0
    }
}
//ham thuc hien phep cong
void cong(char* d, const char *a,const char *b){
    int s=0; // s la bien de luu tong tinh ca bien nho
    int c = 0; // c la bien de lưu số nhớ trong TH s>=10
    for(int i=100; i>=0; i--){ //thuc hien phep cong tu phai qua trai
        s = a[i] - '0' + b[i] - '0' + c;
        c = s / 10;
        d[i] = s % 10 + '0';
    }
}

//ham thuc hien phep tru
void tru(char* d, const char *a, const char* b){
    int c = 0; // số để nhớ khi đã mượn
    for (int i = 100; i >= 0; i--){ //thuc hien phep tru tu phai qua trai
        if (a[i] >= b[i] + c)
        {
            d[i] = a[i] -b[i]- c + '0';
            c = 0;
        }
        else {
            d[i] = a[i] - b[i] - c + '0'+10;//mượn thêm số từ hàng trên để trừ
            c = 1;
        }
    }
}

//ham thuc hien phep nhan
void nhan(char* d, const char *a, const char *b){ //thuc hien phep a*b bang cach tinh a+a+....+a voi b dau cong
    for(int i = 0; i < 101; i++){
        d[i] = '0';         //chuan hoa so chua ket qua ve 0
    }
    char tmp[101]; //mang trung gian de luu ket qua khi thuc hien cac phep cong
    for (int i = 100; i >= 0; i--){
        int k;
        for (k = 0; k < i; k++)
        {
            tmp[100-k] = '0';
        }
        int c = 0, s = 0;
        for (int j = 100; j >= 0; j--)
        {
            s = (a[i] - '0') * (b[j] - '0') + c;
            tmp[k] = (s % 10) + '0';
            c = s / 10;
            k--;
            if(k < 0) break;
        }

        cong(d,tmp,d); //cong ket qua vao mang d sau 1 phep cong
    }
}

//da nang hoa toan tu +
bigNum operator + (bigNum a, bigNum b){
    bigNum res;

    if (a.sign == '1' && b.sign == '1'){   //cong hai so duong
        cong(res.num, a.num, b.num);
        return res;
    }
    else if (a.sign == '1' && b.sign == '0')
    {
        if (strcmp(a.num, b.num))
        {
            res.sign = '1';  // so sanh tri tuyet doi cua a va b va lay dau theo so co gia tri tuyet doi lon hon
            tru(res.num, a.num, b.num);
            return res;
        }
        else
        {
            res.sign = '0';
            tru(res.num, b.num, a.num);
            return res;
        }
    }
    else if (a.sign == '0' && b.sign == '1')
    {// so sanh tri tuyet doi cua a va b va lay dau theo so co gia tri tuyet doi lon hon
        if (strcmp(a.num, b.num)){
            res.sign = '0';
            tru(res.num, a.num, b.num);
            return res;
        }
        else
        {
            res.sign = '1';
            tru(res.num, b.num, a.num);
            return res;
        }
    }
    else
    {               //cong 2 so am
        res.sign = '0';
        cong(res.num, a.num, b.num);  //cong hai so cong dau duoc ket qua cung dau voi hai so do
        return res;
    }
}
//da nang hoa toan tu -
bigNum operator - (bigNum a, bigNum b){
    bigNum res;
    if (a.sign == '1' && b.sign == '0')
    { // so am tru so duong
        b.sign = '1';
        res = a + b;
        return res;
    }
    else if (a.sign == '1' && b.sign == '1')
    { //tru 2 so am
        b.sign = '0';
        res = a + b;
        return res;
    }
    else if (a.sign == '0' && b.sign == '1')
    { //so duong tru so am
        b.sign = '0';
        res = a + b;
        return res;
    }
    else
    {
        b.sign = '1';
        res = a + b;
        return res;
    }
}
//da nang hoa toan tu *
bigNum operator * (bigNum a, bigNum b){
    bigNum res;
    if (a.sign == '1' && b.sign == '1')
    {     //nhan 2 so duong
        res.sign = '1';
        nhan(res.num, a.num, b.num);
        return res;
    }
    else if (a.sign == '1' && b.sign == '0')
    {  //nhan so khac dau
        res.sign = '0';
        nhan(res.num, a.num, b.num);
        return res;
    }
    else if (a.sign == '0' && b.sign == '1')
    {  //nhan so khac dau
        res.sign = '0';
        nhan(res.num, a.num, b.num);
        return res;
    }
    else
    {                        //nhan so cung dau
        res.sign = '1';
        nhan(res.num, a.num, b.num);
        return res;
    }
}
//ham xuat du lieu dau ra
void output(bigNum res){
    cout << res.sign;
    for (int i = 0; i < 101; i++){
        if(res.num[i]=='0')
            {continue;}
        cout << res.num[i];
    }
}

int main(){
    bigNum a, b;
    input(a,b);
    bigNum p, q;
    p.sign = '1';
    q.sign = '1';
    for (int i = 0; i < 100; i++){
        p.num[i] = '0';
        q.num[i] = '0';
    }
    p.num[100] = '3';
    q.num[100] = '4';
    bigNum res = a*b - p * a + q * b;
    output(res);
}
