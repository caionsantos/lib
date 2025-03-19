#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void build(int no, int l, int r, vector<long long int> &segtree, vector<long long int> &orig){
    if(l == r){
        segtree[no] = orig[l];
        return;
    }

    int mid = (l + r)/2;
    build(2 * no, l, mid, segtree, orig);
    build((2 * no) + 1, mid + 1, r, segtree, orig);
    segtree[no] = segtree[2 * no] + segtree[(2 * no) + 1];
}

void update(int no, int l, int r, int pos, long long int val, vector<long long int> &segtree){
    if((pos < l) or (r < pos)){
        return;
    }
    if(l == r){
        segtree[no] = val;
        return;
    }

    int mid = (l + r)/2;
    update(2* no, l, mid, pos, val, segtree);
    update((2* no) + 1, mid + 1, r, pos, val, segtree);
    segtree[no] = segtree[2 * no] + segtree[(2 * no)+ 1];

}

long long int query(int no, int l, int r, int lq, int rq, vector<long long int> &segtree){
    if((rq < l) or (r < lq)){
        return 0;
    }
    if((lq <= l) and (r <= rq)){
        return segtree[no];
    }

    int mid = (l + r)/2;
    long long int ans = query(2 * no, l, mid, lq, rq, segtree);
    ans += query((2 * no) + 1, mid + 1, r, lq, rq, segtree);

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    vector<long long int> segtree(4 * n);
    //ADICIONAR X EM L E -X EM R+1 EH IGUAL A ADICIONAR X EM [L, R]
    //SEGTREE PARA ACHAR MENORES:
    // for(int i = 0; i < n; i++){
    //     range = upper_bound(mansort.begin(), mansort.end(), man[i]) - mansort.begin();
    //     dir[i] = query(1, 1, n, range, n, segtree);
    //     update(1, 1, n, range, 1, segtree);
    // }

    return 0;
}
