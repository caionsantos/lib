#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int bits = 22;
ll dp[1ll << bits];
void sosdp(bool submask){
    memset(dp, 0, sizeof dp);

    if(submask){
        
        //dp[mask] guarda soma de dp[] de todas as SUBmasks
        for(int i = 0; i <bits; i++){
            for(ll mask = 0; mask < (1ll << bits); mask++){
                if(mask&(1ll << i)) dp[mask] += dp[mask^(1ll << i)];
            }
        }   
    
    } else{
    
        //dp[mask] guarda a soma de dp[] de todas as SUPERmasks
        for(int i = 0; i < bits; i++){
            for(ll mask = (1ll << bits) - 1; mask >= 0; mask--){
                if(!(mask & (1ll << i))) {
                    dp[mask] += dp[mask ^ (1ll << i)];
                }
            }
        }

    }
}