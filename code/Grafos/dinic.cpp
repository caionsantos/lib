#include <bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

struct aresta{
    ll u, v, c;
    aresta(){
        u = 0;
        v = 0;
        c = 0;
    }
    aresta(ll u2, ll v2, ll c2){
        u = u2;
        v = v2;
        c = c2;
    }
};

struct Dinic{
    ll n, src, sink;
    //vetor all permite achar real e inversa facilmente
    vector<aresta> all;
    vector<vector<int>> adj;
    vector<ll> level;
    //proxima aresta disponivel
    vector<int> nxt;

    Dinic(ll n2, ll src2, ll sink2){
        n = n2;
        src = src2;
        sink = sink2;
        adj = vector<vector<int>>(n+1);
    }

    void add(ll u, ll v, ll c, bool dir){
        //no dinic sao necessarios arestas opostas de capacidade 0
        all.push_back(aresta(u, v, c));
        adj[u].push_back(all.size()-1);
        //se for nao direcionado trocar 0 por c
        ll invcap = 0;
        if(dir){
            invcap = c;
        }
        all.push_back(aresta(v, u, c));
        adj[v].push_back(all.size()-1);
    }

    //bfs para gerar o vetor lvl por meio de arestas nao saturadas
    //deve sinalizar se chegou na pia (caso contrario o algoritmo terminou)
    bool bfs(){
        level = vector<ll>(n+1, -1);
        queue<tuple<int, ll>> fila;
        level[src] = 0;
        fila.push(tuple<int, ll>(src, 0));

        while(!fila.empty()){
            int curr = get<0>(fila.front());
            ll d = get<1>(fila.front());
            fila.pop();

            for(auto e : adj[curr]){
                if((all[e].c > 0) && (level[all[e].v] == -1)){
                    level[all[e].v] = d+1;
                    fila.push(tuple<int, ll>(all[e].v, d+1));
                }
            }
        }

        return (level[sink] != -1);
    }

    
    ll dfs(int curr, ll bottleneck){
        if((curr == sink) or (bottleneck == 0)){
            return bottleneck;
        }

        //atualiza prox aresta, lembrar de resetar
        for(int &curredge = nxt[curr]; curredge < (adj[curr].size()); curredge++){
            int ar = adj[curr][curredge];
            int nv = all[ar].v;
            //apenas arestas que progridem
            if((level[nv] == (level[curr] + 1))){
                ll check = dfs(nv, min(bottleneck, all[ar].c));
                if(check > 0){
                    all[ar].c -= check;
                    //flipar o ultimo bit checa inverso
                    all[ar ^ 1].c += check;
                    return check;        
                }
            }
        }
        //blocking flow
        return 0;
    }

    ll maxflow(){
        ll flow = 0;
        while(bfs()){
            nxt = vector<int>(n+1, 0);
            while(true){
                ll check = dfs(src, 1e12);
                if(check > 0){
                    flow += check;
                } else{
                    break;
                }
            }
        }
        return flow;
    }
};