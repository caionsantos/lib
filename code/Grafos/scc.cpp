#include <bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

void dfs(int v, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &order){
    vis[v] = true;
    for(auto u : adj[v]){
        if(!vis[u]){
            dfs(u, adj, vis, order);
        }
    }
    order.push_back(v);

    return;
}

void kosaraju(vector<vector<int>> &adj, vector<int> &c, vector<vector<int>> &comps, vector<vector<int>> &dag){
    int n = adj.size();
    vector<int> order;
    vector<bool> vis(n, false);

    for(int i = 1; i < n; i++){
        if(!vis[i]){
            dfs(i, adj, vis, order);
        }
    }

    vector<vector<int>> adj_transp(n);
    for(int v = 1; v < n; v++){
        for(int u : adj[v]){
            adj_transp[u].push_back(v);
        }
    }
    vis = vector<bool>(n, false);
    reverse(order.begin(), order.end());

    for(auto v : order){
        if(!vis[v]){
            vector<int> comp;
            dfs(v, adj_transp, vis, comp);
            comps.push_back(comp);
        }
    }

    vector<bool> mark(comps.size(), false);
    for(int i = 0; i < comps.size(); i++){
        for(auto v : comps[i]){
            c[v] = i;
        }
    }

    for(int i = 1; i < n; i++){
        for(auto v : adj[i]){
            if(c[i]==c[v] || mark[c[v]]) continue;

            mark[c[v]] = true;
            dag[c[i]].push_back(c[v]);
        }
        for(auto v : adj[i]) mark[c[v]] = false;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //2SAT
    //i = x
    //i^1 = ~x
    if(!pos){
        cout << "IMPOSSIVEL" << endl;
    } else{
        vector<bool> val(m+1);
        for(int i = 1; i <= 2*m + 1; i+=2){
            val[i/2] = co[i] < co[i^1];
        }
        for(int i = 1; i <= m; i++){
            if(val[i]){
                cout << "S ";
            } else{
                cout << "N ";
            }
        }
        cout << endl;
    }

    /*
    void add_or(int u, int v){
		E[eval(~u)].push_back(eval(v));
		E[eval(~v)].push_back(eval(u));
  	}
	void add_nand(int u, int v) {
		E[eval(u)].push_back(eval(~v));
		E[eval(v)].push_back(eval(~u));
	}
	void set_true (int u){ E[eval(~u)].push_back(eval(u)); }
	void set_false(int u){ set_true(~u); }
	void add_imply(int u, int v){ E[eval(u)].push_back(eval(v)); }
	void add_and  (int u, int v){ set_true(u);  set_true(v);    }
	void add_nor  (int u, int v){ add_and(~u, ~v); }
	void add_xor  (int u, int v){ add_or(u, v); add_nand(u, v); }
	void add_xnor (int u, int v){ add_xor(u, ~v); }
    */


    return 0;
}