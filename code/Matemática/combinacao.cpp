#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const long long int mod = 1000000007;

long long int comb(long long int n, long long int i){
    long long int denom = 1;
    long long int num = 1;

    for(int j = 0; j < i; j++){
        num *= (n - j);
        num /= (j + 1);
    }
    //COMBINACAO ITERATIVA
    return num;
}

long long int fexp(long long int a, long long int b);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n, m;
    vector<long long int> fatn(2000100);
    fatn[0] = 1;
    for(long long int i = 1; i < fatn.size(); i++){
        fatn[i] = (fatn[i - 1] * i) % mod;
    }
    //combinacao = (n!/(i!*(n-i)))
    //combinacao com repeticao C(n, i) = C(n + i - 1, i); 
    long long int aa = ((fatn[m] * fatn[n - 1])) % mod;
    long long int bb = fexp(aa, mod - 2);
    long long int combrep = (fatn[n + m - 1] * bb) % mod;

    long long int comb = ((fatn[n])/(fatn[n-m] * fatn[m]));
    //para operacoes com modulo eh preciso ao inves de dividir, multiplicar
    //pelo inverso modular (n ^ mod-2)

    return 0;
}