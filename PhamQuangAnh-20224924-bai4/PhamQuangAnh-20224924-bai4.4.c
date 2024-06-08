#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print_vector(const vector<int> &a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}


void delete_even(vector<int> &a) {
    /*****************
    Pham Quang Anh 20224924
    *****************/
   vector<int> c;
   for(auto it=a.begin();it!=a.end();++it)
   {
       if(*it%2)
       {
           c.push_back(*it);
       }
   }
   a.clear();
     for(auto it=c.begin();it!=c.end();++it)
   {
       
           a.push_back(*it);
       
   }
   
}

void sort_decrease(vector<int> &a) {
    /*****************
    Pham Quang Anh 20224924
    *****************/
    sort(a.begin(),a.end(),greater<int>());
}

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
    /*****************
    Pham Quang Anh 20224924
    *****************/
    vector<int> res(a.size()+b.size());

    merge (a.begin(),a.end(),b.begin(),b.end(),res.begin());
    sort(res.begin(),res.end(),greater<int>());
  
    return res;
}

int main() {
    int m, n, u;
    std::vector<int> a, b;
    
    std::cin >> m >> n;
    for(int i = 0; i < m; i++){
        std:: cin >> u;
        a.push_back(u);
    }
    for(int i = 0; i < n; i++){
        std:: cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}