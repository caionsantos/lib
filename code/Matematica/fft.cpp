#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

using cd = complex<double>; // ou long double
const double pi = acos(-1);

void fft(vector<cd> &c, bool invert=false){
    int n = c.size();

    for(int i = 1, j = 0; i < n; i++){
        ll bit = n >> 1ll;
        for(; j&bit; bit >>=1ll){
            j^=bit;
        }
        j^=bit;

        if(i < j) swap(c[i], c[j]);
    }

    for(int len = 2; len<=n; len <<=1){
        double ang = 2*pi/len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));

        for(int i = 0; i < n; i+= len){
            cd w(1);

            for(int j = 0; j < len/2; j++){
                cd u = c[i+j];
                cd v = c[i+j+len/2]*w;
            
                c[i+j] = u+v;
                c[i+j+len/2] = u-v;

                w*=wlen;
            }
        }
    }

    if(invert){
        for(auto &x : c) x /= n;
    }
}

vector<ll> mul(vector<ll> &a, vector<ll> &b){
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());

    ll n = 1;
    while(n < (a.size()+b.size())) n<<=1ll;
    
    fa.resize(n);fb.resize(n);

    fft(fa, false); fft(fb, false);

    for(int i = 0; i < n; i++) fa[i] *= fb[i];

    fft(fa, true);

    vector<ll> ans(n);
    for(int i = 0; i < n; i++) ans[i] = round(fa[i].real());

    return ans;
}