#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

struct HLD{
    int n;
    vector<vector<int>> adj;
    vector<int> pai, depth, topo, heavy, pos;
    int curr = 1; 
    Segtree seg;
    HLD(int n) : seg(n){
        this->n = n;
        adj.resize(n+1);
        pai.resize(n+1);
        depth.resize(n+1);
        topo.resize(n+1);
        heavy.resize(n+1, -1);
        pos.resize(n+1);
    }

    void add(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int find_heavy(int v, int p, int d){
        int sz = 1;
        int mx = 0;
        pai[v] = p;
        depth[v] = d;

        for(auto u : adj[v]){
            if(u==p)continue;

            int sub = find_heavy(u, v, d+1);
            sz += sub;
            if(sub > mx){
                mx = sub;
                heavy[v] = u;
            }
        }

        return sz;
    }

    void chains(int v, int p, int ini){
        topo[v] = ini;
        pos[v] = curr++;

        if(heavy[v]!= -1){
            chains(heavy[v], v, ini);
        }

        for(auto u : adj[v]){
            if(u==p)continue;
            if(u==heavy[v]) continue;

            chains(u, v, u);
        }
    }

    void update(int v, ll val){
        seg.update(1, 1, n, pos[v], val);
    }

    ll query_path(int a, int b){
        ll res = 0;
        
        while(topo[a] != topo[b]){
            if(depth[topo[a]] < depth[topo[b]]){
                swap(a, b);
            }
            res += seg.query(1, 1, n, pos[topo[a]], pos[a]);
            a = pai[topo[a]];
        }
    
        if(depth[a] > depth[b]) swap(a, b);
    
        res += seg.query(1, 1, n, pos[a], pos[b]);

        return res;
    }

    void init(){
        find_heavy(1, -1, 0);
        chains(1, -1, 1);
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;

    vector<ll> val(n+1);
    HLD hv(n);
    for(int i = 1; i <= n; i++){
        cin >> val[i];
    }

    ll c, a, b;
    for(int i = 1; i < n; i++){
        cin >> a >> b;
        a++; b++;
        hv.add(a, b);
    }

    hv.init();
    for(int i = 1; i <= n; i++){
        hv.update(i, val[i]);
    }

    while(q--){
        cin >> c >> a >> b;
        if(c==1){
            a++; b++;
            cout << hv.query_path(a, b) << endl;
        } else{
            a++;
            hv.update(a, b);
        }
    }

    return 0;
}