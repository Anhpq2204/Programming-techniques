#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstdio>
using namespace std;

const int LIMIT = 100;
const int NUM_INTER = 100000;
const int NUM_INPUTS = NUM_INTER * 100;
double sigmoid_slow(double x){
    return 1.0 / (1.0 + exp(-x));
}
double x[NUM_INPUTS];
//ham chuan bi dau vao
void prepare_input(){
    const int PRECISION = 1000000;
    const double RANGE = LIMIT/ 20.0;
    for(int i=0;i<NUM_INPUTS;++i){
        x[i] = RANGE * (rand() * PRECISION - rand() % PRECISION) / PRECISION;
    }
}
//#BEGIN fast code
//#khai báo biến phụ trợ cần thiết
double precal[NUM_INPUTS];
double delta = 3e-6;// khoang cach giua hai diem lien ke
double begi = -15; // tinh sigmoid voi x thuoc [-15;15]
double en = 15;


  /*****************
   Pham Quang Anh 20224924
    *****************/

//Hàm chuẩn bị dữ liệu
void precalc(){
   /*****************
   Pham Quang Anh 20224924
    *****************/
    for(long i=0; i< NUM_INPUTS;++i){
        precal[i] = sigmoid_slow(begi + i*delta);
    }

}
//#Hàm tính sigmoid(x) nhanh sigmoid_fast(x)
inline double sigmoid_fast(double x){
/*****************
   Pham Quang Anh 20224924
    *****************/
    if(x<=begi) return 0;//neu x<-15 thi sig(x)=0
    else if(x>=en) return 1;// neu x>15 thi sig(x)=1
    else{

        long vitri = (long)((x-begi)*(1000000.0/3.0)); //tinh vi tri diem ta dang can xet
        return precal[vitri];
    }

}
//#END fast code
double benchmark(double (*calc)(double), vector<double> &result){
    const int NUM_TEST = 20;
    double taken = 0;
    result = vector<double>();
    result.reserve(NUM_INTER);
    int input_id = 0;
    clock_t start = clock();
    for(int t=0;t<NUM_TEST; ++t){
        double sum = 0;
        for(int i=0;i<NUM_INTER;++i){
            double v = fabs(calc(x[input_id]));
            sum+=v;
            if(t==0) result.push_back(v);
            if((++input_id)==NUM_INPUTS) input_id = 0;
        }
    }
    clock_t finish = clock();
    taken = (double)(finish - start);
    return taken;
}

bool is_correct(const vector<double> &a, const vector<double> &b){
    const double EPS = 1e-6;
    if(a.size() != b.size()) return false;
    int n = a.size();
    for(int i=0; i< n;++i){
        if(fabs(a[i] - b[i])>EPS){
            return false;
        }
    }
    return true;
}
int main(){
    prepare_input();
    precalc();
    vector<double> a,b;
    double slow = benchmark(sigmoid_slow,a);
    double fast = benchmark(sigmoid_fast, b);
    double xval;
    scanf("%lf", &xval);
    printf("%.2f \n", sigmoid_fast(xval));
    if(is_correct(a,b) && (slow/fast> 1.3)){
        printf("Correct answer! Your code is faster at least 30%%!\n");
    }
    else{
        printf("Wrong answer or your code is not fast enough!\n");
    }
    return 0;
}
