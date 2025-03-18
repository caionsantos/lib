#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int dfs(bool &cicblock, int &cicstart, int cidade, int anterior, vector<int> &ciclo, vector<bool> &visitado, vector<vector<int>> &adj){
    if(visitado[cidade]){
        if(cicstart == 0){
            ciclo.push_back(cidade);
            cicstart = cidade;
        }
        return cidade;
    } else{
        int fim = 0;
        visitado[cidade] = true;

        for(auto i : adj[cidade]){
            if(i != anterior){
                fim = dfs(cicblock, cicstart, i, cidade, ciclo, visitado, adj);

                if(cidade == cicstart){
                    //ciclo.push_back(cidade);
                    cicblock = true;
                }

                if(fim != -1){
                    if(!cicblock){
                        ciclo.push_back(cidade);
                        return cidade;
                    }
                }
            }
        }

        return -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //def dfs(atual, anterior):
    //  if(visitado[atual]): return
    //  visitado[atual] = true
    //  for nxt in adj[atual]:
    //      if(nxt != anterior):
    //          fim = dfs(nxt, atual)
    //          if(fim != -1): ciclo.adiciona(atual)
    //          if(fim == atual OU  fim == JA_TERMINOU): retorne JA_TERMINOU
    //  
    //  retorne -1

    return 0;
}