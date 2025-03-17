#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const long long int mod = 1000000007;

long long int fexp(long long int a, long long int b){
    long long int ans = 1;
    while(b != 0){
        if(b & 1){
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

long long int gcd(long long int a, long long int b){
    if(!b){
        return a;
    } else{
        return gcd(b, a % b);
    }
    //ja implementado em __gcd()
}

long long int lcm(long long int a, long long int b){
    return (a/(gcd(a,b) * b));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
