#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//kactl
struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) {
		for (; pos < s.size(); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) {
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
};

struct FT2 {
	vector<vector<ll>> ys; vector<FT> ft;
	FT2(int limx) : ys(limx) {}
	void fakeUpdate(int x, int y) {
		for (; x < ys.size(); x |= x + 1) ys[x].push_back(y);
	}
	void init() {
		for (auto& v : ys) sort(v.begin(), v.end()), ft.emplace_back(v.size());
	}
	int ind(int x, int y) {
		return (int)(lower_bound(ys[x].begin(), ys[x].end(), y) - ys[x].begin()); }
	void update(int x, int y, ll dif) {
		for (; x < ys.size(); x |= x + 1)
			ft[x].update(ind(x, y), dif);
	}
	ll query(int x, int y) { //pontos < x e < y
		ll sum = 0;
		for (; x; x &= x - 1)
			sum += ft[x-1].query(ind(x-1, y));
		return sum;
	}
};