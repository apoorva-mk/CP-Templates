#include<bits/stdc++.h>
using namespace std;
#define MOD 100000000

// Simply calculates the GCD of the two numbers
int gcd(int a, int b){
    if(a == 0)
        return a;

    else return gcd(b%a, a);
}

// With gcd, also returns the x, y values which satisfy ax + by = gcd
int gcdExtended(int a, int b, int &x, int &y){
    if(a == 0){
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int gcd = gcdExtended(b%a, a, x1, y1);
    x = y1 - (b/a) * x1;
    y = x1;
    return gcd; 
}

int modInverse(int a, int m){
    int x, y;
    int g = gcdExtended(a, m, x, y);

    // Inverse only exists for mutually primes
    if(g != 1)
        exit(0);

    else
    {
        // Incase the x is negative
        int inverse = (x % m + m) % m;
        return inverse;
    }
    
}
