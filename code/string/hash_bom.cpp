#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
using Hash = pair<ll, ll>;

struct Hasher {
    static const ll P1 = 31;
    static const ll P2 = 37;
    static const ll M1 = 1e9 + 33;
    static const ll M2 = 1e9 + 93;

    ll n;
    vector<ll> prefix_hash1, prefix_hash2;
    static vector<ll> powers1, powers2;

    static void ensure_powers(ll max_len) {
        ll current_size = powers1.size();
        if (max_len > current_size) {
            powers1.resize(max_len);
            powers2.resize(max_len);
            for (int i = current_size; i < max_len; i++) {
                powers1[i] = (powers1[i - 1] * P1) % M1;
                powers2[i] = (powers2[i - 1] * P2) % M2;
            }
        }
    }

    Hasher(const vector<ll>& s) {
        n = s.size();
        if (powers1.empty()) {
            powers1.push_back(1);
            powers2.push_back(1);
        }
        ensure_powers(n + 1);

        prefix_hash1.resize(n + 1, 0);
        prefix_hash2.resize(n + 1, 0);

        for (int i = 0; i < n; i++) {
            ll val = s[i];
            prefix_hash1[i + 1] = (prefix_hash1[i] * P1 + val) % M1;
            prefix_hash2[i + 1] = (prefix_hash2[i] * P2 + val) % M2;
        }
    }

    Hash substr_hash(int i, int j) {
        int len = j - i + 1;

        ll h1 =
            (((prefix_hash1[j + 1] - (prefix_hash1[i] * powers1[len]) % M1) %
              M1) +
             M1) %
            M1;

        ll h2 =
            (((prefix_hash2[j + 1] - (prefix_hash2[i] * powers2[len]) % M2) %
              M2) +
             M2) %
            M2;

        return {h1, h2};
    }

    Hash full_hash() {
        if (n == 0) {
            return {0, 0};
        }
        return substr_hash(0, n - 1);
    }
};

vector<ll> Hasher::powers1;
vector<ll> Hasher::powers2;