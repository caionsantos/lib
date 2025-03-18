#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, a, b;
    vector<int> grau_entrada(n + 1, 0);
    vector<vector<int>> requisitos(n + 1);
    for(int i = 0; i < m; i++){
        cin >> a;
        cin >> b;
        requisitos[a].push_back(b);
        grau_entrada[b] += 1;
    }

    queue<int> fila;
    for(int i = 1; i <= n; i++){
        if(grau_entrada[i] == 0){
            fila.push(i);
        }
    }

    vector<int> toposort;
    int u;
    while(fila.size() > 0){
        u = fila.front();
        fila.pop();

        toposort.push_back(u);
        for(auto v : requisitos[u]){
            grau_entrada[v]--;
            if(grau_entrada[v] == 0){
                fila.push(v);
            }
        }
    }

    if(toposort.size() == n){
        for(int i = 0; i < n; i++){
            cout << toposort[i] << " ";
        }
        cout << endl;
    } else{
        cout << "IMPOSSIBLE" << endl;
    }


    return 0;
}