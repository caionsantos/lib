#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int xi, yi, yf, xf, n, q;
    vector<vector<int>> prefsum(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> floresta;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            prefsum[i][j] = floresta[i - 1][j - 1] + prefsum[i - 1][j] + prefsum[i][j - 1] - prefsum[i - 1][j - 1];
        }
    }
    for(int i = 0; i < q; i++){
        cin >> yi;
        cin >> xi;
        cin >> yf;
        cin >> xf;


        cout << (prefsum[yf][xf] - prefsum[yf][xi - 1] - prefsum[yi - 1][xf] + prefsum[yi - 1][xi - 1]) << endl;
    }

    return 0;
}