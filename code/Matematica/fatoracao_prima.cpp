#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    vector<int> primos;
    map<int, int> freq;
    for(int i = 2; i*i <= n; i++){
        int cnt = 0;
        while(n % i == 0){
            n /= i;
            cnt++;
        }
        if(cnt > 0){
            freq[i] += cnt;
            primos.push_back(i);
        }
    }
    if(n > 1){
        primos.push_back(n);
        freq[n]++;
    }

    return 0;
}
