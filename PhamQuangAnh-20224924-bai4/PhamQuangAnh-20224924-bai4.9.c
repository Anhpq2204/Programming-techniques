vector<int> dijkstra(const vector<vector<pair<int, int>>>& adj) {
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;

   
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});  

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

    
        if (d > dist[u]) {
            continue;
        }


        for (const auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int w = neighbor.second;
            int new_dist = d + w;

          
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }

    return dist;
}
