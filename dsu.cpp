#include<bits/stdc++.h>
using namespace std;
#define MOD 100000000

void make_set(int v){
    parent[v] = v;  
}

// Find representative with path compression
int find_set(int v){
    if(parent[v] == v)
        return v;
    return parent[v] = find_set(parent[v]);
}

// Union by size
void make_set(itt v){
    parent[v] = v;
    size[v] = 1;
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if (a != b){
        if (size[a] < size[b]){
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}

// Union by rank ,ie, depth
void make_set(int v){
    parent[v] = v;
    rank[v] = 0;
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if (a != b){
        if(rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if(rank[a] == rank[b])
            rank[a]++;
    }
}
