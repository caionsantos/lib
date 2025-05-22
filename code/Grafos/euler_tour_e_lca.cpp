#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int tempo = 0;

void euler(int v, vector<vector<long long int>> &adj, vector<bool> &vis, vector<long long int> &euler_in, vector<long long int> &euler_out){
    vis[v] = true;
    tempo++;
    euler_in[v] = tempo;
    //euler tour
    for(auto u : adj[v]){
        if(!vis[u]){
            euler(u, adj, vis, euler_in, euler_out);
        }
    }
    //tempo++; -> desnecessario
    euler_out[v] = tempo;
}

int lca(int a, int b, vector<long long int> &euler_in, vector<long long int> &euler_out, vector<vector<long long int>> &pai){
    if((euler_in[a] <= euler_in[b]) and (euler_out[a] >= euler_out[b])){
        return a;
    } else if((euler_in[b] <= euler_in[a]) and (euler_out[b] >= euler_out[a])){
        return b;
    } else{
        int cursor = a;
        for(int i = 20; i >= 0; i--){
            if(!((euler_in[pai[cursor][i]] <= euler_in[b]) and (euler_out[pai[cursor][i]] >= euler_out[b]))){
                cursor = pai[cursor][i];
            }
        }
        return pai[cursor][0];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, p, a, b;
    //AJUSTAR VALOR DE ITERAÇÃO DE ACORDO COM LOGN
    cin >> n >> q;
    vector<vector<long long int>> pai(n+1, vector<long long int>(21, -1));
    vector<long long int> euler_in(n+1);
    vector<long long int> euler_out(n+1);
    vector<vector<long long int>> adj(n+1);
    vector<bool> vis(n+1, false);
    pai[1][0] = 1;
    for(int i = 2; i <= n; i++){
        cin >> p;
        pai[i][0] = p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    //precalcular pais
    for(int j = 1; j <= 20; j++){
        for(int i = 1; i <= n; i++){
            if(pai[i][j - 1] != -1){
                pai[i][j] = pai[pai[i][j-1]][j-1];
            }
        }
    }

    return 0;
}
