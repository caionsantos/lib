#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

//dp das moedas
long long int coinsum(vector<long long int> &dp, vector<long long int> &moedas, long long int w){
    if(w == 0){
        return 0;
    }
    if(dp[w] != -1){
        return dp[w];
    }

    long long int ans = INT_MAX;
    for(int i = 0; i < moedas.size(); i++){
        if(w - moedas[i] >= 0){
            ans = min(ans, coinsum(dp, moedas, w - moedas[i]) + 1);
        }
    }
    dp[w] = ans;
    return dp[w];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}