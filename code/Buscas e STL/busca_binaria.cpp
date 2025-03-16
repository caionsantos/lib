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
    while(r >= l){
        mid = (l + r)/2;
        pos = true;

        //CHECAGEM

        if(!pos){
            l = mid + 1;
            maximpossivel = max(maximpossivel, mid);
        } else{
            r = mid - 1;
        }
    }

    return 0;
}