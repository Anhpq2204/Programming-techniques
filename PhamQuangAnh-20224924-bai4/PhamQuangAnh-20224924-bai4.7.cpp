template<class T>
set<T> set_union(const set<T> &a, const set<T> &b) {
    /*****************
    Pham Quang Anh 20224924
    *****************/
    set<T> q;
    for(auto it: a)
    {
        q.insert(it);
    }
       for(auto it: b)
    {
        q.insert(it);
    }
    return q;
    
    
}

template<class T>
set<T> set_intersection(const set<T> &a, const set<T> &b) {
    /*****************
    Pham Quang Anh 20224924
    *****************/
    set<T> q;
    for(auto it: a)
    {
        if(b.count(it)!=0)
        {
            q.insert(it);
        }
        
    }
    
    return q;
}