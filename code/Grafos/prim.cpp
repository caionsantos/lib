#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, a, b;
    long long int c;
    vector<vector<tuple<long long int, int>>> adj(n + 1);
    vector<int> na_arvore;
    vector<bool> visitado(n + 1, false);
    priority_queue<tuple<long long int, int>> minheap;
    for(int i = 0; i < m; i++){
        adj[a].push_back(tuple(-(c), b));
        adj[b].push_back(tuple(-(c), a));
    }
    minheap.push(tuple(0, 1));
    long long int custo, d;
    int o;
    custo = 0;
    while(minheap.size() > 0){
        d = get<0>(minheap.top());
        o = get<1>(minheap.top());
        minheap.pop();

        if(!visitado[o]){
            visitado[o] = true;
            na_arvore.push_back(o);
            custo += -(d);

            for(auto v : adj[o]){
                if(!visitado[get<1>(v)]){
                    minheap.push(v);
                }
            }
        }
    }

    //OBS: KRUSKALL
    // sort arestas
    // for custo u, v em arestas:
    //  if(find(u) != find(v)):
    //      join(u, v)
    //      total = total + custo
    //prim expande uma arvore, kruskall cria e vai juntando

    return 0;
}