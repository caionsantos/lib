#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int find(int n, vector<int> &rep){
    if(n == rep[n]){
        return rep[n];
    } else{
        rep[n] = find(rep[n], rep);
        return rep[n];
    }
}

void join(int n, int v, vector<int> &rep, map<int, int> &size){
    n = find(n, rep);
    v = find(v, rep);

    if(n == v){
        return;
    }

    if(size[n] < size[v]){
        swap(v, n);
    }

    rep[v] = n;
    size[n] += size[v];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    map<int, int> size;
    vector<int> rep(n + 1);
    for(int i = 1; i <= n; i++){
        rep[i] = i;
        size[i]++;
    }

    return 0;
}