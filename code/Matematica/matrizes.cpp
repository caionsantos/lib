#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<vector<long long int>> mult(vector<vector<long long int>> &a, vector<vector<long long int>> &b, long long int MOD){
    vector<vector<long long int>> res(a.size(), vector<long long int>(b[0].size()));

    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b[0].size(); j++){
            res[i][j] = 0;
            for(int k = 0; k < a[0].size(); k++){
                res[i][j] += (a[i][k] * b[k][j]) % MOD;
                res[i][j] = res[i][j] % MOD;
            }
        }
    }

    return res;
}

vector<vector<long long int>> fexp(vector<vector<long long int>> &a, long long int e, long long int MOD){
    vector<vector<long long int>> ans(4, vector<long long int>(4, 0));
    ans[0][0] = 1;
    ans[1][1] = 1;
    ans[2][2] = 1;
    ans[3][3] = 1;

    while(e){
        if(e & 1){
            ans = mult(a, ans, MOD);
        }
        a = mult(a, a, MOD);
        e >>= 1;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //recorrencia em matrizes
    //matrix T * matrix (f0) = matrix (f2)
    //                  (f1)          (f1)

    return 0;
}