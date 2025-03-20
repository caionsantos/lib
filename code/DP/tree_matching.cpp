#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void tmaux(int n, int p, vector<vector<long long int>> &dp, vector<vector<int>> &adj){
    long long int sum1 = 0;
    long long int sum2 = 0;

    for(auto v : adj[n]){
        if(v != p){
            tmaux(v, n, dp, adj);
            sum1 += max(dp[0][v], dp[1][v]);
        }
    }
    dp[0][n] = sum1;

    for(auto v : adj[n]){
        if(v != p){
            sum2 = max(sum2, (1 + dp[0][v] + dp[0][n] - max(dp[0][v], dp[1][v])));
        }
    }
    dp[1][n] = sum2;
}

long long int tmatch(int n, vector<vector<long long int>> &dp, vector<vector<int>> &adj){
    tmaux(n, -1, dp, adj);
    return max(dp[0][1], dp[1][1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}