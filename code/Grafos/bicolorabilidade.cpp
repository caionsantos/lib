#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool dfs(int v, vector<vector<int>> &adj, vector<bool> &visitado, vector<bool> &cor){
    visitado[v] = true;

    for(auto u : adj[v]){
        if(!visitado[u]){
            cor[u] = !cor[v];
            if(!dfs(u, adj, visitado, cor)){
                return false;
            }
        } else if(cor[u] == cor[v]){
            return false;
        }
    }
    return true;
}

void dfs2(int v, long long int dist, vector<bool> &cor, vector<bool> &visitado, vector<vector<tuple<int, long long int>>> &adj){
    visitado[v] = true;
    for(auto u : adj[v]){
        if(!visitado[get< 0>(u)]){
            if((dist + get<1>(u)) % 2 == 0){
                cor[get<0>(u)] = cor[1];
            } else{
                cor[get<0>(u)] = !cor[1];
            }
            dfs2(get<0>(u), dist + get<1>(u), cor, visitado, adj);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}