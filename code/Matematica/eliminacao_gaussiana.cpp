#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll mod;

ll fexp(ll a, ll b);

int gauss(int n, int m, vector<vector<ll>> &mat){
    int l = 0; //rank
    ll pivo;
    //col
    for(int i = 0; i < m; i++){
        pivo = -1;
        for(int j = l; j < n; j++){
            if(mat[j][i] != 0){
                pivo = j;
                break;
            }
        }
        if(pivo==-1) continue;
        swap(mat[pivo], mat[l]);
        //IGNORAR NO CASO DE MOD 2 vvvv
        ll denom = fexp(mat[l][i], mod-2);
        for(int k = 0; k < m; k++){
            if(mat[l][k] != 0){
                mat[l][k] = (mat[l][k] * denom) % mod;
            }
        }
        //IGNORAR NO CASO DE MOD 2 ^^^^

        for(int j = 0; j < n; j++){
            if(j!=l){
                ll mul = mat[j][i];
                for(int k = 0; k < m; k++){
                    mat[j][k] = (((mat[j][k] - ((mat[l][k] * mul) % mod)) % mod) + mod) % mod;
                }
            }
        }
        //CASO SEJA MOD 2
        //usar bitsets
        // for(int j = 0; j < n; j++){
        //     if(j!=l){
        //         ll mul = mat[j][i];
        //         if(mul){
        //             mat[j] ^= mat[l];
        //         }
        //     }
        // }
        l++;
    }
    //retorna rank da matriz
    return l;
}