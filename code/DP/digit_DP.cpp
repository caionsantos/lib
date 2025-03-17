#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

//dp para numeros sem 2 digitos adjacentes iguais
long long int rec(int pos, int lastdig, bool start, bool smaller, vector<int> &num, vector<vector<vector<vector<long long int>>>> &dp){
    if(pos >= num.size()){
        return 1;
    }

    if(dp[pos][lastdig][start][smaller] != -1){
        return dp[pos][lastdig][start][smaller];
    }   

    long long int ans = 0;
    if(smaller){
        for(int i = 0; i <= 9; i++){
            if(start){
                if(i > 0){
                    ans += rec(pos + 1, i, false, smaller, num, dp);
                } else{
                    ans += rec(pos + 1, i, true, smaller, num, dp);
                }
            } else{
                if(i != lastdig){
                    ans += rec(pos + 1, i, start, smaller, num, dp);
                }
            }
        }
    } else{
        for(int i = 0; i <= num[pos]; i++){
            if(start){
                if(i > 0){
                    ans += rec(pos + 1, i, false, !(i == num[pos]), num, dp);
                } else{
                    ans += rec(pos + 1, i, true, !(i == num[pos]), num, dp);
                }
            } else{
                if(i != lastdig){
                    ans += rec(pos + 1, i, start, !(i == num[pos]), num, dp);
                }
            }
        }
    }
    dp[pos][lastdig][start][smaller] = ans;
    return dp[pos][lastdig][start][smaller];

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //digit dp: iterar pelos digitos
    //lembrar da ideia base: quando chegar na posição
    //não pode mudar o valor!!

    return 0;
}