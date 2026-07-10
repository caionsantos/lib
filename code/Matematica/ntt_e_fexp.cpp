#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const ll mod = 998244353;

ll fexp(ll a, ll b){
    ll ans = 1;
    while(b != 0){
        if(b & 1){
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

//pegar g do ntt para um modulo primo p
ll get_primitive_root(ll p) {
    vector<ll> fatores;
    ll phi = p - 1;
    ll n = phi;
    
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            fatores.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        fatores.push_back(n);
    }

    for (ll res = 2; res <= p; ++res) {
        bool ok = true;
        
        for (ll fator : fatores) {
            //g^((p-1)/q) tem que ser diferente de 1 para todo q dos fatores
            if (fexp(res, phi / fator) == 1) {
                ok = false;
                break;
            }
        }
        
        if (ok) {
            return res;
        }
    }
    return -1;
}

const ll G=3;

//g->primitive root (rodar antes)
void ntt(vector<ll> &a, bool invert) {
    int n = a.size();
    
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    
    for (int len = 2; len <= n; len <<= 1) {
        ll wlen = fexp(G, (mod - 1) / len);
        
        if (invert) wlen = fexp(wlen, mod-2);
        
        for (int i = 0; i < n; i += len) {
            ll w = 1;
            for (int j = 0; j < len / 2; j++) {
                ll u = a[i + j];
                ll v = (a[i + j + len / 2] * w) % mod;
                
                a[i + j] = (u + v < mod ? u + v : u + v - mod);
                a[i + j + len / 2] = (u - v >= 0 ? u - v : u - v + mod);
                
                w = (w * wlen) % mod;
            }
        }
    }
    
    if (invert) {
        ll n_inv = fexp(n, mod-2);
        for (ll &x : a) x = (x * n_inv) % mod;
    }
}

vector<ll> mul(vector<ll> const& a, vector<ll> const& b) {
    vector<ll> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    
    fa.resize(n); 
    fb.resize(n);
    
    ntt(fa, false); 
    ntt(fb, false);
    
    for (int i = 0; i < n; i++) 
        fa[i] = (fa[i] * fb[i]) % mod;
        
    ntt(fa, true);

    while (fa.size() > 1 && fa.back() == 0) fa.pop_back();
    
    return fa;
}

vector<ll> polyfexp(vector<ll> &base, ll exp) {
    vector<ll> res = {1}; 
    
    while (exp != 0) {
        if (exp & 1) {
            res = mul(res, base);
        }
        base = mul(base, base);
        exp >>= 1;
    }
    
    return res;
}