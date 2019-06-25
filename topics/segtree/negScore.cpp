//problem: https://www.spoj.com/problems/RPLN/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 100000;
ll segtree[4 * N], v[N];

void build(ll beg, ll end, ll pos) {
    if (beg == end) segtree[pos] = v[beg];
    else {
        ll m = (beg + end)/2;
        build(beg, m, 2 * pos);
        build(m + 1, end, 2 * pos + 1);
        segtree[pos] = min(segtree[2 * pos], segtree[2 * pos + 1]);
    }
}

ll mini(ll qbeg, ll qend, ll beg, ll end, ll pos) {
    if (end < qbeg || qend < beg) return 0;
    if (qbeg <= beg && qend >= end) return segtree[pos];
    ll m = (beg + end)/2;
    if (m < qbeg) return mini(qbeg, qend, m + 1, end, 2 * pos + 1);
    if (m + 1 > qend) return mini(qbeg, qend, beg, m, 2 * pos);
    return min(mini(qbeg, qend, beg, m, 2 * pos), mini(qbeg, qend, m + 1, end, 2 * pos + 1));
}

void solve() {
    ll n, q, a, b;
    cin >> n >> q;
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
    }
    build(0, n - 1, 1);
    for (ll i = 0; i < q; ++i) {
        cin >> a >> b;
        cout << mini(a - 1, b - 1, 0, n - 1, 1) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        cout << "Scenario #" << i << ":\n";
        solve();
    }
    return 0;
}
