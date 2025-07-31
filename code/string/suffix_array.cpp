#include <bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

struct SA{
    int sz;
    vector<ll> suffarr, endrank, lcp;
    SA(int s){
        sz = s;
        suffarr = vector<ll>(sz+1); //espaço p/ sentinela vai ser apagado
        endrank = vector<ll>(sz);
        lcp = vector<ll>(sz);
    }
    void suffarray(vector<ll> &s){
        //ajuste a sentinela se necessario
        s.push_back(0);
        const ll n = s.size();
        vector<ll> rank(n), temp(n);
        vector<pair<ll, ll>> etc(n);
        for(int i = 0; i < n; i++){
            etc[i] = {s[i], i};
        }
        sort(etc.begin(), etc.end());
        for(int i = 0; i < n; i++){
            suffarr[i] = etc[i].second;
        }
        rank[suffarr[0]] = 0;
        for(int i = 1; i < n; i++){
            rank[suffarr[i]] = rank[suffarr[i-1]] + (etc[i].first != etc[i-1].first);
        }

        for(int k = 1; k < n; k *= 2){
            int classes = rank[suffarr[n-1]] + 1;
            vector<ll> cnt(classes, 0);
            for(int i = 0; i < n; i++) cnt[rank[i]]++;

            vector<ll> pos(classes, 0);
            for(int i = 1; i < classes; i++) pos[i] = pos[i-1] + cnt[i-1];

            for(int i = 0; i < n; i++){
                int j = suffarr[i] - k;
                if(j < 0) j+=n;
                temp[pos[rank[j]]++] = j;
            }
            suffarr = temp;

            temp[suffarr[0]] = 0;
            for(int i = 1; i < n; i++){
                pair<ll, ll> prev = {rank[suffarr[i-1]], rank[(suffarr[i-1] + k) % n]};
                pair<ll, ll> curr = {rank[suffarr[i]], rank[(suffarr[i] + k) % n]};
            
                temp[suffarr[i]] = temp[suffarr[i-1]] + (curr != prev);
            }
            rank = temp;
        }
        s.pop_back();
        suffarr.erase(suffarr.begin());
        return;
    }

    //lcp[i] = lcp de i-1 e i; lcp[0] deve ser ignorado
    void lcpv(vector<ll> &s){
        s.push_back(0);
        int n = suffarr.size();

        for(int i = 0; i < n; i++){
            endrank[suffarr[i]] = i;
        }
        ll k = 0;
        
        for(int i = 0; i < n; i++){
            if(endrank[i] == 0) lcp[0] = 0;
            else{
                ll j = suffarr[endrank[i] - 1];
                while(s[i+k] == s[j+k]) k++;
                lcp[endrank[i]] = k;
                if(k > 0) k--;
            }
        }
        s.pop_back();
        return;
    }

    //retorna tamanho do lcp entre sufixos da posicao i e j
    //so pra mostrar que eh uma query de minimo no lcp
    //ao inves disso use seg
    ll get_lcp(int i, int j){
        int l = endrank[i];
        int r = endrank[j];
        if(l > r) swap(l, r);
        if(i==j) return (sz - suffarr[l]);
        
        ll ans = lcp[l+1];
        for(int k = l+2; k <= r; k++){
            ans = min(lcp[k], ans);
        }
        return ans;
    }
};