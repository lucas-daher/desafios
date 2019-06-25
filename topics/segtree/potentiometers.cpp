//problem: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=192

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 200000;
ll segtree[4 * N], v[N];

void build(ll beg, ll end, ll pos) {
    if (beg == end) segtree[pos] = v[beg];
    else {
        ll m = (beg + end)/2;
        build(beg, m, 2 * pos);
        build(m + 1, end, 2 * pos + 1);
        segtree[pos] = segtree[2 * pos] + segtree[2 * pos + 1];
    }
}

void update(ll target, ll val, ll beg, ll end, ll pos) {
    if (beg > target || end < target) return;
    if (beg == end) {
        segtree[pos] = val;
        return;
    }
    ll m = (beg + end)/2;
    update(target, val, beg, m, 2 * pos);
    update(target, val, m + 1, end, 2 * pos + 1);
    segtree[pos] = segtree[2 * pos] + segtree[2 * pos + 1];
}

ll sum(ll qbeg, ll qend, ll beg, ll end, ll pos) {
    if (end < qbeg || qend < beg) return 0;
    if (qbeg <= beg && qend >= end) return segtree[pos];
    ll m = (beg + end)/2;
    return sum(qbeg, qend, beg, m, 2 * pos) + sum(qbeg, qend, m + 1, end, 2 * pos + 1);
}

void solve(ll n) {
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    build(0, n - 1, 1);
    string s;
    ll a, b;
    cin >> s;
    while (s != "END") {
        if (s == "S") {
            cin >> a >> b;
            update(a - 1, b, 0, n - 1, 1);
        } else {
            cin >> a >> b;
            cout << sum(a - 1, b - 1, 0, n - 1, 1) << "\n";
        }
        cin >> s;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i = 1, n;
    cin >> n;
    while (n != 0) {
        cout << "Case " << i << ":\n";
        solve(n);
        cin >> n;
        ++i;
        if (n) cout << "\n";
    }
    return 0;
}