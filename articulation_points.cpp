// Finding cut points 
vector <int> findCutPoints(int v, vector <vector<int> >& adj_list, vector <bool>& visited, vector <int>& tin, vector <int> low, int p, int& timer, vector <int>& cutpoints) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;
    for (auto adj : adj_list[v]) {
        if (adj == p)
            continue;
        if (visited[adj])
            low[v] = min(low[v], tin[adj]);
        else {
            findCutPoints(adj, adj_list, visited, tin, low, v, timer, cutpoints);
            low[v] = min(low[v], low[adj]);
            if (low[adj] >= tin[v] && p != -1)
                cutpoints.push_back(v);
            ++children;
        }
    }
    if (p == -1 && children > 1)
        cutpoints.push_back(v);
}
