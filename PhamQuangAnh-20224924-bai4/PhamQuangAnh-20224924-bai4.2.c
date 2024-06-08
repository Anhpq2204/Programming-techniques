 #include <iostream>
 #include <cmath>
 #include <iomanip>
 #include <utility>
 using namespace std;
 using Point = pair<double, double>;

double area(Point a, Point b, Point c) {
    /*****************
    Pham Quang Anh 20224924
    *****************/
    double m=   sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
    double n=   sqrt((a.first-c.first)*(a.first-c.first)+(a.second-c.second)*(a.second-c.second));
    double p=   sqrt((c.first-b.first)*(c.first-b.first)+(c.second-b.second)*(c.second-b.second));
    double q=(m+n+p)/2;
    double s=sqrt(q*(q-m)*(q-n)*(q-p));
    return s;
}

