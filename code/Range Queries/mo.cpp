#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;


const int BLOCK_SZ = 450;
//O(n^2/b + q*b)
struct Query{
    int l, r, idx;
    Query(int li, int ri, int i){
        l = li; r = ri; idx = i;
    }

    bool operator<(Query q) const{
        if((l/BLOCK_SZ) != (q.l/BLOCK_SZ)) return l < q.l;
        if((l/BLOCK_SZ)&1)return r > q.r;
        return r < q.r;
    }
};

vector<ll> orig;
vector<ll> cnt;
ll sum = 0;
//exemplo elementos distintos
void inline add(int idx){
    cnt[orig[idx]]++;
    if(cnt[orig[idx]] == 1){
        sum++;
    }
}

void inline remove(int idx){
    cnt[orig[idx]]--;
    if(cnt[orig[idx]] == 0){
        sum--;
    }
}

ll ans(){
    return sum;
}

void MO(vector<Query> &q, vector<ll> &out){
    int L = 0, R = 0;
    sort(q.begin(), q.end());
    add(0);
    //queries 0 indexadas
    for(auto [l, r, idx] : q){
        while(l < L) add(--L);

        while(r > R) add(++R);

        while(l > L) remove(L++);

        while(r < R) remove(R--);

        out[idx] = ans();
    }
}