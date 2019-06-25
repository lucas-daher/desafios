//problem: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3977

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
        segtree[pos] = segtree[2 * pos] * segtree[2 * pos + 1];
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
    segtree[pos] = segtree[2 * pos] * segtree[2 * pos + 1];
}

ll prod(ll qbeg, ll qend, ll beg, ll end, ll pos) {
    if (end < qbeg || qend < beg) return 1;
    if (qbeg <= beg && qend >= end) return segtree[pos];
    ll m = (beg + end)/2;
    return prod(qbeg, qend, beg, m, 2 * pos) * prod(qbeg, qend, m + 1, end, 2 * pos + 1);
}

void solve(ll n, ll k) {
    ll aux;
    for (ll i = 0; i < n; i++) {
        cin >> aux;
        if (aux > 0) aux = 1;
        else if (aux < 0) aux = -1;
        v[i] = aux;
    }
    build(0, n - 1, 1);
    ll a, b;
    char c;
    string ret = "";
    for (ll i = 0; i < k; i++) {
        cin >> c >> a >> b;
        if (c == 'C') {
            if (b > 0) b = 1;
            else if (b < 0) b = -1;
            update(a - 1, b, 0, n - 1, 1);
        } else {
            aux = prod(a - 1, b - 1, 0, n - 1, 1);
            if (aux > 0) ret += "+";
            else if (aux < 0) ret += "-";
            else ret += "0";
        }
    }
    cout << ret << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    while (cin >> n >> k) {
        solve(n, k);
    }
    return 0;
}

/*
4 6
-2 6 0 -1
C 1 10
P 1 4
C 3 7
P 2 2
C 4 -5
P 1 4
5 9
1 5 -2 4 3
P 1 2
P 1 5
C 4 -5
P 1 5
P 4 5
C 3 0
P 1 5
C 4 -5
C 4 -5
*/