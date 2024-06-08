template<class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b) {
    /*****************
    Pham Quang Anh 20224924
    *****************/
    map<T, double> c;


    for (const auto &it : a) {
        T element = it.first;
        double value = it.second;

        if (b.count(element) != 0) {

            c[element] = max(value, b.at(element));
        } else {

            c[element] = value;
        }
    }

 
    for (const auto &it : b) {
        T element = it.first;
        if (a.count(element) == 0) {
            c[element] = it.second;
        }
    }

    return c;
}

template<class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b) {
    /*****************
    Pham Quang Anh 20224924
    *****************/
    map<T, double> c;

 
    for (const auto &it : a) {
        T element = it.first;
        double value = it.second;

        if (b.count(element) != 0) {
        
            c[element] = min(value, b.at(element));
        }
    }

    return c;
}