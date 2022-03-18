#include<bits/stdc++.h>
using namespace std;

long long moduloMultiplication(long long a, long long b, long long mod) {
    long long res = 0; 
    a %= mod;
    while (b) {
        if (b & 1)
            res = (res + a) % mod;
        a = (2 * a) % mod;
        b >>= 1;
    }
    return res;
}


int main() {
    long long a = 3,
              b = 5,
              m = 10005412336548794;
    cout << moduloMultiplication(a, b, m);
    return 0;
}

