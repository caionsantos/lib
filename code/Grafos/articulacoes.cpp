#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int t = 0;
vector<int> artics;
//cuidado com repetidos
//inicializar in e low c -1

void dfs(int v, int p, vector<vector<ll>> &adj, vector<bool> &vis, vector<int> &in, vector<int> &low){
    vis[v] = true;
    t++;
    in[v] = t;
    low[v] = t;

    int child = 0;
    for(auto u : adj[v]){
        if(u==p){
            continue;
        }
        if(vis[u]){
            low[v] = min(low[v], in[u]);
        } else{
            dfs(u, v, adj, vis, in, low);
            low[v] = min(low[v], low[u]);
            if(low[u] >= in[v] && p!=-1){
                artics.push_back(v);
            }
            child++;
        }
    }
    if(p==-1 && child > 1){
        artics.push_back(v);
    }
}