#include <bits/stdc++.h>
#define endl '\n'
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const long long int k = 277;
    const long long int l = 149;
    const long long int p = 37;

    const long long int mod = 1000000009;
    const long long int mod2 = 1000000007;
    const long long int mod3 = 999999937;

    int n, q;
    cin >> n;
    cin >> q;
    vector<long long int> num(n);
    vector<long long int> bnum(n);
    vector<long long int> pot(n+1);
    vector<long long int> pot2(n+1);
    vector<long long int> pot3(n+1);
    pot[0] = 1;
    pot[1] = 1;
    pot[2] = 1;
    for(int po = 1; po <= n; po++){
        pot[po] = (pot[po - 1] * k) % mod;
        pot2[p] = (pot2[po - 1] * l) % mod2;
        pot3[po] = (pot3[po - 1] * p) % mod3;
    }
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    for(int i = 0; i < n; i++){
        cin >> bnum[i];
    }
    vector<long long int> hashsuml(n+1);
    vector<long long int> hashsumk(n+1);
    vector<long long int> hashsump(n+1);
    hashsumk[0] = 0;
    hashsuml[0] = 0;
    hashsump[0] = 0;
    hashsumk[1] = (num[0] * pot[num[0]]) % mod;
    hashsuml[1] = (num[0] * pot2[num[0]]) % mod2;
    hashsump[1] = (num[0] * pot3[num[0]]) % mod3;

    vector<long long int> bhashsuml(n+1);
    vector<long long int> bhashsumk(n+1);
    vector<long long int> bhashsump(n+1);
    bhashsumk[0] = 0;
    bhashsuml[0] = 0;
    bhashsump[0] = 0;
    bhashsumk[1] = (bnum[0] * pot[bnum[0]]) % mod;
    bhashsuml[1] = (bnum[0] * pot2[bnum[0]]) % mod2;
    bhashsump[1] = (bnum[0] * pot3[bnum[0]]) % mod3;
    for(int i = 1; i < n; i++){
        hashsumk[i+1] = ((hashsumk[i] + ((num[i] * pot[num[i]]) % mod)) % mod);
        hashsuml[i+1] = ((hashsuml[i] + ((num[i] * pot2[num[i]]) % mod2)) % mod2);
        hashsump[i+1] = (hashsump[i] + ((num[i] * pot3[num[i]]) % mod3)) % mod3;
    }
    for(int i = 1; i < n; i++){
        bhashsumk[i+1] = ((bhashsumk[i] + ((bnum[i] * pot[bnum[i]]) % mod)) % mod);
        bhashsuml[i+1] = ((bhashsuml[i] + ((bnum[i] * pot2[bnum[i]]) % mod2)) % mod2);
        bhashsump[i+1] = (bhashsump[i] + ((bnum[i] * pot3[bnum[i]]) % mod3)) % mod3;
    }

    return 0;
}

