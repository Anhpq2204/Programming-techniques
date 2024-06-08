#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int val1, val2;
    cin >> val1 >> val2;
    vector< vector<int> > a = {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };

    //# sắp xếp các vector trong a theo tổng các phần tử giảm dần
    /*****************
    Pham Quang Anh 20224924
    *****************/

    sort(a.begin(),a.end(),[](vector<int> c,vector<int> d){
        int sum1=0,sum2=0;
        for(int &i:c)
        {
            sum1+=i;
        }
         for(int &j:d)
        {
            sum2+=j;
        }
        return sum1>sum2;
    });  //su dung ham nac danh nhu 1 tham so cua ham sort

    for (const auto &v : a) {  //in ra kq
        for (int it : v) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
