#include<bits/stdc++.h>
using namespace std;
#define MOD 100000000

// Prims algorithms
// Time complexity is O(ElogV)
// Here we push back elements in to the pq whenever is has a minimum weight only and check if it's been added to MST or not
vector<int> Prims(int src, vector <vector<pair<int, int>> >& adj_list, int vert_num) {
    vector <int> parent(vert_num, -1);
    vector <int> in_mst(vert_num, false);
    vector <int> dist(vert_num, 1e9);
    priority_queue<pair<int, int>, vector <pair<int, int> >, greater<pair<int, int>>> pq;
    pq.insert({0, src});
    dist[src] = 0;
    while (pq.size() != 0) {
        int u = pq.top().second;
        pq.pop();
        in_mst[u] = true;

        for (int i = 0; i < adj_list[u].size(); i++) {
            int v = adj_list[u][i].first;
            int weight = adj_list[u][i].second;
            if (!in_mst[v] && dist[v] > weight) {
                dist[v] = weight;
                parent[v] = u;
                pq.insert({weight, v});
            }
        }
    }
    in_mst[src] = true;
    return parent;
}
