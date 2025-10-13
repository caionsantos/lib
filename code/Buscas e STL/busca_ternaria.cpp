#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll eps = 2;

ll calc(ll a);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, a, b;
    ll r, l;
    ll m1, m2, f1, f2;
    while((r-l) > eps){
        m1 = l + (r-l)/3;
        m2 = r - (r-l)/3;

        f1 = calc(m1);
        f2 = calc(m2);
    
        if(f1 < f2){
            l = m1;
        } else{
            r = m2;
        }
    }
    //SOMENTE PARA INTEIROS
    ll ans = 0;
    for(ll i = l; i <= r; i++){
        ans = max(ans, (n-i)*a + (i*b + i - ((i*(i+1))/2)));
    }
    //NO CASO DE DOUBLE AJUSTE EPS
    //OU USE ITERACOES

    return 0;
}