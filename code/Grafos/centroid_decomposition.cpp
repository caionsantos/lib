#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

ll dfs(int u, int p, vector<vector<ll>> &adj, vector<ll> &subtree, vector<bool> &rem){
    subtree[u] = 1;
    for(auto v : adj[u]){
        if(v==p) continue;
        if(rem[v]) continue;
        subtree[u] += dfs(v, u, adj, subtree, rem);
    }
    return subtree[u];
}

ll centroid(int v, int p, vector<vector<ll>> &adj, vector<ll> &subtree, vector<bool> &rem, int n){
    for(auto u : adj[v]){
        if(u==p)continue;
        if(rem[u]) continue;
        if(2*subtree[u] > n){
            return centroid(u, v, adj, subtree, rem, n);
        }
    }
    return v;
}

vector<ll> subtree;

void decomp(int v, int p, vector<vector<ll>> &adj, vector<bool> &rem){
    dfs(v, -1, adj, subtree, rem);
    int cen = centroid(v, -1, adj, subtree, rem, subtree[v]);
    
    rem[cen] = true;

    for(auto u : adj[cen]){
        if(!rem[u]){
            decomp(u, -1, adj, rem);
        }
    }
}