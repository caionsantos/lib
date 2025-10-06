#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

struct Segtree{
    vector<ll> segtree;
    int n;
    const ll MISS = 0;
    //nao afetar resultado
    Segtree(vector<ll> &orig){
        segtree.resize(4* (orig.size()));
        n = orig.size();
        build(1, 0, n-1, orig);
    }
    Segtree(int n){
        segtree.resize(4*n);
        this->n = n;
    }

    ll combine(ll left, ll right){
        return left + right;
    }

    //build(0, 0, n-1)
    void build(int no, int l, int r, vector<ll> &orig){
        if(l == r){
            segtree[no] = orig[l];
            return;
        }

        int mid = (l + r)/2;
        build(2 * no, l, mid, orig);
        build((2 * no) + 1, mid + 1, r, orig);
        segtree[no] = combine(segtree[2 * no], segtree[(2 * no) + 1]);
    }

    //update(1, 1, n)
    void update(int no, int l, int r, int pos, ll val){
        if((pos < l) or (r < pos)){
            return;
        }
        if(l == r){
            segtree[no] = val;
            return;
        }

        int mid = (l + r)/2;
        update(2* no, l, mid, pos, val);
        update((2* no) + 1, mid + 1, r, pos, val);
        segtree[no] = combine(segtree[2 * no], segtree[(2 * no) + 1]);

    }

    //query(1, 1, n)
    ll query(int no, int l, int r, int lq, int rq){
        if((rq < l) or (r < lq)){
            return MISS;
        }
        if((lq <= l) and (r <= rq)){
            return segtree[no];
        }

        int mid = (l + r)/2;
        ll ans = combine(query(2 * no, l, mid, lq, rq), query((2 * no) + 1, mid + 1, r, lq, rq));

        return ans;
    }

};

//ADICIONAR X EM L E -X EM R+1 EH IGUAL A ADICIONAR X EM [L, R]
//SEGTREE PARA ACHAR MENORES:
// for(int i = 0; i < n; i++){
//     range = upper_bound(mansort.begin(), mansort.end(), man[i]) - mansort.begin();
//     dir[i] = query(1, 1, n, range, n, segtree);
//     update(1, 1, n, range, 1, segtree);
// }

//SegEuler -> usar updates ao inves do build (ou mapear vetor a[euler_in[i]] - > orig[i]
// query em euler_in[i], euler_out[i]
// update em euler_in[i]