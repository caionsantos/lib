#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, a, b;
    long long int c;
    vector<vector<long long int>> distancias(n + 1, vector<long long int>(n + 1, LLONG_MAX));
    for(int i = 0; i < m; i++){
        cin >> a;
        cin >> b;
        cin >> c;
        // lembrar arestas duplas
        distancias[a][b] = min(c, distancias[a][b]);
        distancias[b][a] = min(c, distancias[b][a]);
    }

    for(int k = 1; k <= n; k++){
        for(int u = 1; u <= n; u++){
            for(int v = 1; v <= n; v++){
                if((distancias[u][k] != LLONG_MAX) and (distancias[k][v] != LLONG_MAX)){
                    distancias[u][v] = min(distancias[u][v], (distancias[u][k] + distancias[k][v]));
                }
            }
        }
    }
    // analisar quantidade, serve pra poucos vértices e saber distância entre todas



    return 0;
}