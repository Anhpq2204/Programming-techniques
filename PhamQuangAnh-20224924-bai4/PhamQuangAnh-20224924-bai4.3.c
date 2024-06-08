Vector cross_product(Vector a, Vector b) {

    /*****************
    Pham Quang Anh 20224924

    *****************/
    double m= get<1>(a)*get<2>(b)-get<2>(a)*get<1>(b);
    double n= get<2>(a)*get<0>(b)-get<0>(a)*get<2>(b);
    double p= get<0>(a)*get<1>(b)-get<1>(a)*get<0>(b);
    auto res=make_tuple(m,n,p);
    return res;
}