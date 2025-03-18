#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    vector<long long int> distancias(n + 1, LLONG_MAX);
    vector<vector<tuple<long long int, int>>> adj(n + 1);
    distancias[1] = 0;
    priority_queue<tuple<long long int, int>> minheap;
    minheap.push(tuple(0, 1));
    long long int d, c;
    int a, b, o;
    for(int i = 0; i < m; i++){
        cin >> a;
        cin >> b;
        cin >> c;

        adj[a].push_back(tuple(c, b));
    }
    while(minheap.size() > 0){
        d = -(get<0>(minheap.top()));
        o = get<1>(minheap.top());
        minheap.pop();

        if(d <= distancias[o]){
            for(auto v : adj[o]){
                if(distancias[get<1>(v)] > distancias[o] + get<0>(v)){
                    distancias[get<1>(v)] = distancias[o] + get<0>(v);
                    minheap.push(tuple(-(distancias[get<1>(v)]), get<1>(v)));
                }
            }
        }
    }
    // LEMBRE DE GRAPH MODELLING
    // ADICIONAR ESTADOS COMO EM DP

    return 0;
}