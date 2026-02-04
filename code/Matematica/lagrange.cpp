const ll maxn = 1e6+5;
vector<ll> fat(maxn), invFat(maxn), pref(maxn), suff(maxn);
const ll MOD = 1e9 + 7;

ll fexp(ll a, ll b);

void init_lagrange(int n) {
    fat[0] = 1;
    for (int i = 1; i <= n; i++) fat[i] = fat[i - 1] * i % MOD;
    invFat[n] = fexp(fat[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--) invFat[i] = invFat[i + 1] * (i + 1) % MOD;
}
 
ll interpolate(vector<ll>& y, int T) {
    int k = y.size() - 1;
    if (T <= k) return y[T];
    T %= MOD;
    pref[0] = 1;
    for (int i = 0; i <= k; i++) pref[i + 1] = pref[i] * (T - i + MOD) % MOD;
    suff[k + 1] = 1;
    for (int i = k; i >= 0; i--) suff[i] = suff[i + 1] * (T - i + MOD) % MOD;
    ll ans = 0;
    for (int i = 0; i <= k; i++) {
        ll num = pref[i] * suff[i + 1] % MOD;
        ll den = invFat[i] * invFat[k - i] % MOD;
        if ((k - i) & 1) den = (MOD - den);
        ans = (ans + y[i] * num % MOD * den) % MOD;
    }
    return ans;
}