#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define sll __uint128_t
using namespace std;

ull fexp(ull a, ull b, ull mod){
    ull ans = 1;
    while(b != 0){
        if(b & 1){
            ans = ((sll)ans * a) % mod;
        }
        a = ((sll)a * a) % mod;
        b >>= 1;
    }
    return ans;
}

bool check_composite(ull n, ull a, ull d, int s) {
    ull x = fexp(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (sll)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

//identifica primo ate 1e16
bool MillerRabin(ull n) {
    if (n < 2)
        return false;

    int r = 0;
    ull d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}