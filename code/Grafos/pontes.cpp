#include <bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

int t = 0;
vector<ll> pontes;

void dfs(int v, int p, vector<vector<tuple<ll, int>>> &adj, vector<bool> &vis, vector<int> &in, vector<int> &low){
    vis[v] = true;
    t++;
    in[v] = t;
    low[v] = t;

    bool skip = false;
    for(auto [id, u] : adj[v]){
        if(u==p && !skip){
            skip = true;
        } else{
            if(vis[u]){
                low[v] = min(low[v], in[u]);
            } else{
                dfs(u, v, adj, vis, in, low);
                low[v] = min(low[v], low[u]);
                if(low[u] > in[v]){
                    pontes.push_back(id);
                }
            }
        }
    }
}