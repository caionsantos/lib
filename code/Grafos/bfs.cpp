#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    string s;
    tuple<int, int, int> start;
    char c;
    vector<vector<char>> mapa(n);
    queue<tuple<int, int, int>> fila;
    vector<vector<bool>> visitado(n, vector<bool>(m, false));

    visitado[get<0>(start)][get<1>(start)] = true;
    fila.push(start);
    tuple<int, int> end;
    int x, y, camada, dist;
    dist = 0;
    while(fila.size() > 0){
        y = get<0>(fila.front());
        x = get<1>(fila.front());
        camada = get<2>(fila.front());
        fila.pop();

        if(mapa[y][x] == 'B'){
            dist =  camada;
            end = tuple(y, x);
            break;
        }

        if((y + 1 < n)){
            if(!visitado[y + 1][x]){
                visitado[y + 1][x] = true;
                fila.push(tuple(y + 1, x, camada + 1));
            }
        }

        if((y - 1 >= 0)){
            if(!visitado[y - 1][x]){
                visitado[y - 1][x] = true;
                fila.push(tuple(y - 1, x, camada + 1));
            }
        }

        if((x + 1 < m)){
            if(!visitado[y][x + 1]){
                visitado[y][x + 1] = true;
                fila.push(tuple(y, x + 1, camada + 1));
            }
        }

        if((x - 1 >= 0)){
            if(!visitado[y][x - 1]){
                visitado[y][x - 1] = true;
                fila.push(tuple(y, x - 1, camada + 1));
            }
        }

    }
    //DIAMETRO DA ARVORE:
    // ACHAR PONTO U MAIS DISTANTE DE INICIAL
    // ACHAR PONTO V MAIS DISTANTE DE U
    // DIAMETRO SERA U, V

    //LEMBRAR DE MULTISOURCE

    return 0;
}