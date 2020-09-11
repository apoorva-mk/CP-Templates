// Finding minimum distance of all vertices from a source vertex with negative weights too. 
// Complexity of o(VE)
// Can work for directed or undirected graphs
// Edges represented as a vector with edges[0] = starting vertex, edges[1] = ending vertex, edes[2] = weight of edge
vector<int> bellmanFord (vector <vector <int>> edges,int v, int e, int source) {
    vector <int> distance (v, INT_MAX);
    distance[source] = 0;
    for (int i = 0; i < v; i++){
        for (int j = 0; j < edges.size(); j++) {
            if (distance[edges[i][0]] != INT_MAX && distance[edges[i][1]] > edges[i][2] + distance[edges[i][0]])
                distance[edges[i][1]] = edges[i][2] + distance[edges[i][0]];
        }
    }
}
