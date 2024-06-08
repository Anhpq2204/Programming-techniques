#include<bits/stdc++.h>
#include<sstream>
using namespace std;
/* Phạm Quang Anh 20224924*/
void output(vector<pair<int,int>> d){
    for(int i=0; i<d.size(); i++){
        cout << d[i].first << " " << d[i].second << endl;
    }
}

int main(){
    for(int i = 1; i <= 4; i++) {
        cout << "Test case " << i << ":" << endl;
        string input;  //xau de nhap du lieu cho tung dong
        vector<pair<int,int>> d;   // vector chua cac cap so
        cout << "Input: " << endl;
        while (getline(cin, input)) {
            if (input == "") {
                break;
            }
            int key, value;
            stringstream ss(input); //su dung de chua du lieu nhap vao tu xau
            while (ss >> key >> value) { //nhap du lieu tu xau
                d.push_back(make_pair(key, value));
            }
        }

        sort(d.begin(), d.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second != b.second) {
                return a.second > b.second;
            }
            return a.first > b.first;
        });

        cout << "Output: " << endl;
        output(d);
        cout << endl;
    }
    return 0;
}
