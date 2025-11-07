#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll inf = 1e18;

struct line{
    ll a, b;
    mutable ll end_segment;

    bool operator<(const line &l) const{
        return tie(a, b) > tie(l.a, l.b);
    }

    bool operator<(const ll x) const{
        return end_segment < x;
    }
};

struct LineContainer : multiset<line, less<>>{

    ll intersect(iterator i, iterator j){
        ll x = j->b - i->b;
        ll y = i->a - j->a;
        //usar somente x/y para doubles, ajustar inf
        return x/y - (((x^y)<0) and ((x%y) != 0));
    }

    void update(iterator i){
        if(next(i) == end()){
            i->end_segment = inf;
        } else{
            i->end_segment = intersect(i, next(i));
        }
    }

    void add(ll a, ll b){
        iterator l = insert({a, b, 0});

        if(l != begin() and (prev(l)->a == l->a)){
            erase(prev(l));
        }
        if(next(l) != end() and (next(l)->a == l->a)){
            erase(l);
            return;
        }

        if(l!=begin() and (next(l) != end())){
            iterator p = prev(l);
            iterator n = next(l);
            if(intersect(p, l) >= intersect(l, n)){
                erase(l);
                return;
            }
        }

        while(l!=begin()){
            iterator p = prev(l);
            if((p!=begin()) and (intersect(prev(p), p) >= intersect(p, l))){
                erase(p);
                continue;
            }
            break;
        }

        while(next(l) != end()){
            iterator n = next(l);
            if(next(n) != end() and (intersect(l, n) >= intersect(n, next(n)))){
                erase(n);
                continue;
            }
            break;
        }

        if(l!=begin()){
            update(prev(l));
        }
        update(l);
    }

    ll min(ll x){
        auto l = lower_bound(x);
        return l->a * x + l->b;
    }
};