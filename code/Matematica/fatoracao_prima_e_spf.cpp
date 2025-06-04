#include <bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll maxn;
    //SHORTEST PRIME FACTOR
    vector<ll> spf(maxn+1, 0);
    ll curr;
    for(ll i = 2; i <= maxn; i++){
        if(spf[i] == 0){
            spf[i] = i;
            curr = i*i;
            while(curr <= maxn){
                if(spf[curr] == 0){
                    spf[curr] = i;
                }
                curr += i;
            }
        }
    }

    //FATORACAO MELHORADA COM SPF -> nlogn
    ll v;
    vector<map<ll, int>> fat(maxn+1);
    for(int i = 2; i <= maxn; i++){
        v = i;
        while(v > 1){
            porfavor[i][spf[v]]++;
            v = v/spf[v];
        }
    }
    
    //FATORACAO PRIMA PADRAO -> n * sqrt(n)
    int n;
    vector<int> primos;
    map<int, int> freq;
    for(int i = 2; i*i <= n; i++){
        int cnt = 0;
        while(n % i == 0){
            n /= i;
            cnt++;
        }
        if(cnt > 0){
            freq[i] += cnt;
            primos.push_back(i);
        }
    }
    if(n > 1){
        primos.push_back(n);
        freq[n]++;
    }

    return 0;
}
