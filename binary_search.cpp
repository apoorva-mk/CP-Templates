#include<bits/stdc++.h>
using namespace std;
#define MOD 100000000

bool binarySearch(vector<int> &a, int x,int n){ 
    bool found = false;
    int l = 0; 
    int r = n - 1;
    while (r >= l){
        int m = (l + r) / 2;
        if (a[m] == x){
            found = true;
            break;
        }
        else if (a[m] < x) {
            l = m + 1;
        }
        else { 
            r = m - 1;
        }
    }
    return found;
}

int closestToLeft(vector<int>& a, int target, int n){
    // Need to find the vertex i of maximum value such that a[i] <= x 
    // Invariants
    // a[l] <= target
    // a[r] > target 
    int l = -1; // We are assigning like this, because these are the virtual elements; -INF & + INF
    int r = n;
    // Till we have adjacent l and r
    while(r > l + 1){
        int m = (l + r) / 2;
        if(a[m] <= target)
            l = m;
        else 
            r = m;
    }
    return l;
}

int closestToRight(vector <int>& a, int target, int n){
    // To find the minimum index i such that, a[i] >= x
    // Invariant
    // a[l] < target
    // a[r] >= target
    int l = -1;
    int r = n;
    // Search till we have adjacent l and r
    while(r > l + 1) {
        int m = (l + r) / 2;
        if (a[m] < target)
            l = m;
        else
            r = m;
    } 
    return r;
}

bool shorterBinSearchCode(vector <int>& a, int target, int n){
    int l = -1;
    int r = n;
    while(r > l + 1) {
        int m = (l + r) / 2;
        if (a[m] < target)
            l = m;
        else
            r = m;
    } 
    if(r != n && a[r] == target)
        return true;
    return false;
}
