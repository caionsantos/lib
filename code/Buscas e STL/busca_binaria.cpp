#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p;
    int l = 0;
    int r = n - 1;
    int mid;
    bool pos;
    int maximpossivel = 0;
    vector<int> sortado;
    while(r >= l){
        mid = l + (r - l)/2;
        pos = true;

        //CHECAGEM

        if(!pos){
            l = mid + 1;
            maximpossivel = max(maximpossivel, mid);
        } else{
            r = mid - 1;
        }
    }
    upper_bound(sortado.begin(), sortado.end(), p); //PRIMEIRO ELEMENTO >= P
    lower_bound(sortado.begin(), sortado.end(), p); //PRIMEIRO ELEMENTO > P
    //subtrair .begin() retorna indice
    //subtrair upper do lower retorna quantidade

    return 0;
}
