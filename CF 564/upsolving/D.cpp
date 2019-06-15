#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fac(ll n) {
    if (n <= 2) return n;
    n *= fac(n - 1);
    n %= 998244353;
    return n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, a, b;
    cin >> n;
    vector<ll> grau(n + 1, 0);
    for (ll i = 0; i + 1 < n; i++) {
        cin >> a >> b;
        grau[a]++;
        grau[b]++;
    }
    ll ret = n;
    for (ll i = 1; i <= n; i++) {
        ret *= fac(grau[i]);
        ret %= 998244353;
    }
    cout << ret << "\n";
    return 0;
}
