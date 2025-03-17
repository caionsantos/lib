#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long int knapsack(vector<tuple<long long int, long long int>> &itens, vector<vector<long long int>> &dp, long long int w, int i){
    if(w == 0){
        return 0;
    }
    if(i >= itens.size()){
        return 0;
    }
    if(dp[w][i] != -1){
        return dp[w][i];
    }

    long long int ans = knapsack(itens, dp, w, i + 1);
    if(get<0>(itens[i]) <= w){
        ans = max(ans, (get<1>(itens[i]) + knapsack(itens, dp, (w - get<0>(itens[i])), i + 1)));
    }
    dp[w][i] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}