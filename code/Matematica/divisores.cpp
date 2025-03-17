#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    vector<int> divs;
    for(int i = 1; (i * i)<=n; i++){
        if(n % i == 0){
            divs.push_back(i);
            if(i != n/i){
                divs.push_back(n/i);
            }
        }
    }

    return 0;
}