#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void dfs(int n, vector<vector<int>> &adj, vector<bool> &vis){
    vis[n] = true;
    for(auto i : adj[n]){
        if(!vis[i]){
            dfs(i, adj, vis);
        }
    }
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}