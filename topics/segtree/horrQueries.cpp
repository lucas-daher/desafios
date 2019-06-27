//problem: www.spoj.com/problems/HORRIBLE/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 100000;
ll segtree[4 * N], lazy[4 * N];

void zero() {
    for (ll i = 0; i < 4 * N; i++) {
        segtree[i] = lazy[i] = 0;
    }
}

void propagate(ll beg, ll end, ll pos) {
    segtree[pos] += lazy[pos] * (end  + 1 - beg);
    if (beg != end) {
        lazy[2 * pos] += lazy[pos];
        lazy[2 * pos + 1] += lazy[pos];
    }
    lazy[pos] = 0;
}

void update(ll qbeg, ll qend, ll beg, ll end, ll pos, ll add) {
    if (end < qbeg || qend < beg) return;
    if (qbeg <= beg && qend >= end) {
        lazy[pos] += add;
        return;
    }
    ll m = (beg + end)/2;
    update(qbeg, qend, beg, m, 2 * pos, add);
    update(qbeg, qend, m + 1, end, 2 * pos + 1, add);
    propagate(beg, end, pos);
    propagate(beg, m, 2 * pos);
    propagate(m + 1, end, 2 * pos + 1);
    segtree[pos] = segtree[2 * pos] + segtree[2 * pos + 1];
}

ll sum(ll qbeg, ll qend, ll beg, ll end, ll pos) {
    if (end < qbeg || qend < beg) return 0;
    propagate(beg, end, pos);
    if (qbeg <= beg && qend >= end) {
        return segtree[pos];
    }
    ll m = (beg + end)/2;
    return sum(qbeg, qend, beg, m, 2 * pos) + sum(qbeg, qend, m + 1, end, 2 * pos + 1);
}

void solve() {
    ll n, c;
    cin >> n >> c;
    zero();
    ll q, x, y, z;
    for (ll i = 0; i < c; ++i) {
        cin >> q;
        if (q == 0) {
            cin >> x >> y >> z;
            update(x - 1, y - 1, 0, n - 1, 1, z);
        } else {
            cin >> x >> y;
            cout << sum(x - 1, y - 1, 0, n - 1, 1) << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        solve();
    }
    return 0;
}