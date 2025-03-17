#include <bits/stdc++.h>
#define endl '\n'
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //2^n = (1<<n)
    int n, i, mask;
    for(int mask = 0; mask <(1<<n); mask++);
    //iterar pela mask n

    if(mask&(1<<i)); //se bit i for 1
    mask = mask|(1<<i); ///ligar bit i
    mask = mask^(1<<i); //flipar bit i 

    return 0;
}