#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int LOG = 20;
const int maxn = 2e5 + 10;

struct LCA{
    int up[maxn][LOG+1];
    int n;
    int tempo = -1; //trocar pra 0 pra virar 1-indexado
    vector<ll> in, out;
    vector<vector<int>> adj;
    vector<ll> dst;
    LCA(int n){
        memset(up, -1, sizeof up);
        this->n = n;
        adj.resize(n+1), in.resize(n+1), out.resize(n+1), dst.resize(n+1);
    }

    void add(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void tour(int v, int p, ll d){
        tempo++;
        in[v] = tempo;

        dst[v] = d;
        up[v][0] = p;   
        
        for(auto u : adj[v]){
            if(u!=p)tour(u, v, d+1);
        }
        out[v] = tempo;
    }

    void build(){
        for(int j = 1; j <= LOG; j++){
            for(int i = 1; i <= n; i++){
                if(up[i][j-1] != -1){
                    up[i][j] = up[up[i][j-1]][j-1];
                }
            }
        }
    }

    void init(){
        tour(1, -1, 0);
        build();
    }

    //a é ancestral de b?
    inline bool is_ancestor(int a, int b){
        return ((in[a] <= in[b]) && (out[a] >= out[b]));
    }

    int lca(int a, int b){
        if(is_ancestor(a, b)) return a;
        if(is_ancestor(b, a)) return b;

        int cursor = a;
        for(int i = LOG; i >= 0; i--){
            if(up[cursor][i] == -1) continue;
            if(!(is_ancestor(up[cursor][i], b))){
                cursor = up[cursor][i];
            }
        }

        return up[cursor][0];
    }

    ll dist(int a, int b){
        int lc = lca(a, b);

        return (dst[a] + dst[b] - (2 * dst[lc]));
    }
};
