#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void update(int no, int l, int r, int pos, int val, vector<int> &segtree){
    if((pos < l) or (r < pos)){
        return;
    }
    if(l == r){
        segtree[no] += val;
        return;
    }

    int mid = (l + r)/2;
    update(2* no, l, mid, pos, val, segtree);
    update((2* no) + 1, mid + 1, r, pos, val, segtree);
    segtree[no] = segtree[2 * no] + segtree[(2 * no)+ 1];

}

int query(int no, int l, int r, int lq, int rq, vector<int> &segtree){
    if((rq < l) or (r < lq)){
        return 0;
    }
    if((lq <= l) and (r <= rq)){
        return segtree[no];
    }

    int mid = (l + r)/2;
    int ans = query(2 * no, l, mid, lq, rq, segtree);
    ans += query((2 * no) + 1, mid + 1, r, lq, rq, segtree);

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, sal, k, j;
    char c;
    vector<int> all;
    vector<int> orig;
    vector<tuple<char, int, int>> queries;
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    int range;
    vector<int> segtree(4 * (all.size()), 0);
    for(int i = 0; i < orig.size(); i++){
        range = lower_bound(all.begin(), all.end(), orig[i]) - all.begin();
        update(1, 1, all.size(), range, 1, segtree);
    }

    return 0;
}