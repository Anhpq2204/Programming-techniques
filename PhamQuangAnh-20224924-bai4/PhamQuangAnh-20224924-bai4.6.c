void bfs(vector< list<int> > adj) {
    queue<int> Q;
    vector<bool> visited(adj.size());
    Q.push(1); // Bắt đầu từ đỉnh số 1
    /*****************
    Pham Quang Anh 20224924
    *****************/
    while(!Q.empty())
    {
            auto g=Q.front();
            Q.pop();
            if(visited[g]==false)
            {
                visited[g]=true;
                cout<<g<<endl;
                for(auto it=adj[g].begin();it!=adj[g].end();++it)
            {   
                if(visited[*it]==false)
                { 
                Q.push(*it);
                }
            }
            
            }
    }
}