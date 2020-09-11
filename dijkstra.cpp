vector<int> dijkstra(vector<vector<vector<int> > > adj_list, int v, int source, vector <int>& parent){
    set <pair<int, int> > q;
    vector <int> dist(v, INT_MAX);
    dist[source] = 0;
    q.insert({0, source});
    while (q.size() != 0) {
        int curr = q.begin()->second;
        q.erase(q.begin());
        if (dist[curr] == INT_MAX)
            break;
        for (auto edge : adj_list[curr]) {
            int end = edge[0];
            int weight = edge[1]; 
            if (dist[end] > dist[curr] + weight) {
                dist[end] = dist[curr] + weight;
                q.insert({dist[end], end});
                parent[end] = curr;
            }            
        }
    }
}
