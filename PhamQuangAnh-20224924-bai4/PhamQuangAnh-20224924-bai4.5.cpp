void dfs(vector< list<int> > adj) {
    stack<int> S;
    vector<bool> visited(adj.size());
    S.push(1); // Bắt đầu từ đỉnh số 1
    
    /*****************
    Pham Quang Anh 20224924
    *****************/
    while(!S.empty())
    {
           
            auto g=S.top();
            S.pop();
            if(!visited[g])
            
            {
                visited[g]=true;
                cout<<g<<endl;
                for(auto it=adj[g].rbegin();it!=adj[g].rend();++it)
            {
                S.push(*it);
            }
            
            }
        
    }
    
    
}