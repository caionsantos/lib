#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    const long long int mod = 1000000009;
    const long long int mod2 = 1000000007;
    const long long int mod3 = 999999937;
    string s;
    cin >> s;
    const long long int k = 277;
    const long long int l = 149;
    const long long int p = 37;
    vector<long long int> pot(s.size() + 1);
    vector<long long int> pot2(s.size() + 1);
    pot[0] = 1;
    pot2[0] = 1;
    for(int p = 1; p <= s.size(); p++){
        pot[p] = (pot[p - 1] * k) % mod;
        pot2[p] = (pot2[p - 1] * l) % mod2;
    }
    vector<long long int> hashupto1(s.size());
    vector<long long int> hashupto2(s.size());
    hashupto1[0] = s[0];
    hashupto2[0] = s[0];
    for(int i = 1; i < s.size(); i++){
        hashupto1[i] = ((hashupto1[i - 1] * k) % mod) + s[i];
        hashupto1[i] = hashupto1[i] % mod;
        hashupto2[i] = ((hashupto2[i - 1] * l) % mod2) + s[i];
        hashupto2[i] = hashupto2[i] % mod2;
    }
    //hash(l..r) = pref(r) - (pref(l - 1) * (k^(r-l+1))) % MOD
    //aa = hashupto1[i + (pref.size() - 1)] - ((hashupto1[i - 1] * pot[pref.size()]) % mod);
    //aa = aa % mod;
    //bb = hashupto2[i + (pref.size() - 1)] - ((hashupto2[i - 1] * pot2[pref.size()]) % mod2);
    //bb = bb % mod2;


    return 0;
}

