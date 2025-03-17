#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long int knap(map<int, int> &custo, vector<long long int> &dp, int w){
    if(w == 0){
        return 0;
    }

    if(dp[w] != -1){
        return dp[w];
    }

    long long int ans = 0;
    for(auto i : custo){
        if((w - i.first) >= 0){
            ans = max(ans, (knap(custo, dp, (w - i.first))) + i.second);
        }
    }
    dp[w] = ans;
    return dp[w];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //mesmos principios da digit, lembre-se do kongey donk
    //estados, mudanças, dp[i][j] -> dp[i- 1][j], dp[i - 1][j + 1], dp[i - 1][j - 1]

    return 0;
}