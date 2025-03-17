#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int lim;
    vector<bool> isprime;
    isprime[0] = false;
    isprime[1] = false;
    vector<int> primes;
    //crivo base, acha primos
    for(int i = 2; i < lim; i++){
        if(isprime[i]){
            primes.push_back(i);
            for(int j = i*2; j < lim; j++){
                isprime[j] = false;
            } 
        }
    }

    //crivo da soma dos divisores no intervalo
    vector<int> sumdivisor;
    for(int i = 1; i < lim; i++){
        for(int j = i; j < lim; j+= i){
            sumdivisor[j] += i;
        }
    }

    //crivo da quantidade de divisore dos números no intervalo
    vector<int> numdivisors;
    for(int i = 1; i < lim; i++){
        for(int j = i; j < lim; j+= i){
            numdivisors[j]++;
        }
    }

    return 0;
}