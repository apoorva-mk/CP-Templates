#include<bits/stdc++.h>
using namespace std;
#define MOD 100000000

// Segment tree implementation for sum of segments
// each segment is lx rx which has sum of elements [lx, rx) (rx not included)
// Also, the segment indices are lx, rx and the segment over which sum I want is l, r
struct segtree {
    vector <long long int> sums;
    int size;
    
    // Segment tree initialisation
    void init(int n) {
        size = 1;
        while (size < n)
            size *= 2;
        // size *= 2;
        sums.assign(size * 2, 0);

    }
    
    // Fast build - like heapify of arrays
    void build(vector <int> &a, int lx,int rx,int x) {
        if (rx - lx == 1) {
            if (lx < (int)a.size()) {
                sums[x] = a[lx];
            }
            return;
        }
        else {
            int m = (lx + rx) / 2;
            build(a, lx, m, 2 * x + 1);
            build(a, m, rx, 2 * x + 2);
            sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
        }     
    }
    
    void build(vector <int> &a) {
        build(a, 0, size, 0);
    }
    
    // To set a value in the array 
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx  == 1) {
            sums[x] = v;
            return;
        }
        else {
            int m = (lx + rx) / 2;
            if (i < m) {
                set(i, v, 2 * x + 1, lx, m);
            }
            else {
                set(i, v, 2 * x + 2, m, rx);
            }
        }
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
        return;
    }
    
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }
    
    // To calculate the sum of elements over a segment
    long long calc(int lx, int rx, int x, int l, int r) {
        if (lx >= r || rx <= l)
            return 0;
        else if (l <= lx && r >= rx)
            return sums[x];
        int m = (lx + rx) / 2;
        long long sum_left = calc(lx, m, 2 * x + 1, l, r);
        long long sum_right = calc(m, rx, 2 * x + 2, l, r);
        return (sum_left + sum_right); 
    }
    
    long long calc(int l, int r) {
        return calc(0, size, 0, l, r);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    segtree st;
    st.init(n);
    vector <int> a(n, 0);
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        a[i] = v;
    }
    st.build(a);
    for (int i = 0; i < m; i++) {
        int op;
        cin >> op;
        if (op == 2) {
            int l, r;
            cin >> l >> r;
            cout << st.calc(l, r) << "\n";
        }
        else {
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        }
    }

}
