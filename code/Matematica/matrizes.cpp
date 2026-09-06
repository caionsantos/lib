#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

vector<vector<ll>> mult(vector<vector<ll>> &a, vector<vector<ll>> &b, ll MOD){
    vector<vector<ll>> res(a.size(), vector<ll>(b[0].size()));
 
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b[0].size(); j++){
            for(int k = 0; k < a[0].size(); k++){
                res[i][j] += (a[i][k] * b[k][j]) % MOD;
                res[i][j] = res[i][j] % MOD;
            }
        }
    }
 
    return res;
}

//muito mais rapido
vector<vector<ll>> mult2(vector<vector<ll>> &a, vector<vector<ll>> &b, ll MOD){
    vector<vector<ll>> res(a.size(), vector<ll>(b[0].size()));

    for(int i = 0; i < a.size(); i++){
        vector<unsigned __int128> temp(b[0].size(), 0); 
        
        for(int k = 0; k < a[0].size(); k++){
            if(a[i][k] == 0) continue;
            for(int j = 0; j < b[0].size(); j++){
                temp[j] += (unsigned __int128)a[i][k] * b[k][j];
            }
        }
        
        for(int j = 0; j < b[0].size(); j++){
            res[i][j] = (ll)(temp[j] % MOD);
        }
    }

    return res;
}

vector<vector<ll>> fexp(vector<vector<ll>> &a, ll e, ll MOD){
    vector<vector<ll>> ans(a.size(), vector<ll>(a.size(), 0));
    for(int i = 0; i < a.size(); i++)ans[i][i] = 1;

    while(e){
        if(e & 1){
            ans = mult(ans, a, MOD);
        }
        a = mult(a, a, MOD);
        e >>= 1;
    }

    return ans;
}
