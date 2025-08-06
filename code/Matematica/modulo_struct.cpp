#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

const ll mod = 1e9 + 7;

struct mint{
    ll val;
    mint(){
        this->val = 0;
    }
    mint(ll val){
        this->val = ((val % mod) + mod) % mod;
    }

    mint operator+(mint v){
        return ((((val + v.val) % mod) + mod) % mod);
    }
    mint operator-(mint v){
        return ((((val - v.val) % mod) + mod) % mod);
    }
    mint operator*(mint v){
        return ((((val * v.val) % mod) + mod) % mod);
    }
    friend ostream& operator<<(ostream& os, const mint& m) {
        return os << m.val;
    }

    friend istream& operator>>(istream& is, mint& m) {
        ll x;
        is >> x;
        m = mint(x);
        return is;
    }
};