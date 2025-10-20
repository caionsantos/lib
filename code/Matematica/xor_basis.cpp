#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

constexpr ll maxn = 500;

vector<ll> rep(64, -1);
vector<bitset<maxn>> indx(64, -1);
//guardar combinacao de indices que gera rep
//reconstrucao do valor = xor dos indx que passa no basis
int pivos = 0;
int bad = 0;
void basis(ll x){
    for(int i = 63; i >= 0; i--){
        if(x&(1LL<<i)){
            if(rep[i] == -1){
                rep[i] = x;
                pivos++;
                //linearmente independente
                return; 
            }
            x ^= rep[i];
        }
    }
    bad++;
    //linearmente dependente (redundante)
    //duplica criacoes dos subsets
}

//coloca na forma escada
//necessario para garantir a criacao dos menores valores
//baseados na ordem dos subsets
void escada(){
    for(int i = 0; i < 64; i++){
        if(rep[i] != -1){
            for(int j = 0; j < i; j++){
                if(rep[j] != -1 && (rep[i]&(1LL<<j))){
                    rep[i] ^= rep[j];
                }
            }
        }
    }
}