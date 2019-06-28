//problem: https://br.spoj.com/problems/BANFARAO/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 100000;
ll segtree[4 * N][4][2], v[N];

ll** freq(ll qbeg, ll qend, ll beg, ll end, ll pos) {
    ll** ret = (ll**) malloc(4 * sizeof(ll*));
    for (ll i = 0; i < 4; i++) {
        ret[i] = (ll*) malloc(2 * sizeof(ll));
        ret[i][0] = ret[i][1] = -11234;
    }
    if (end < qbeg || qend < beg) {
        return ret;
    }
    if (qbeg <= beg && qend >= end) {
        for (ll i = 0; i < 4; i++) {
           ret[i][0] = segtree[pos][i][0];
           ret[i][1] = segtree[pos][i][1];
        }
        return ret;
    }
    ll m = (beg + end)/2;
    ret = freq(qbeg, qend, beg, m, 2 * pos);
    ll** rChild = freq(qbeg, qend, m + 1, end, 2 * pos + 1);
    pair<ll, ll> aux;
    aux.first = ret[2][0] + rChild[0][0];
    aux.second = ret[2][1] + rChild[0][1];
    if (aux.first > ret[1][0] || (aux.first == ret[1][0] && aux.second > ret[1][1])) {
        ret[1][0] = aux.first;
        ret[1][1] = aux.second;
    }
    if (rChild[1][0] > ret[1][0] || (rChild[1][0] == ret[1][0] && rChild[1][1] > ret[1][1])) {
        ret[1][0] = rChild[1][0];
        ret[1][1] = rChild[1][1];
    }
    if (ret[3][0] + rChild[0][0] > ret[0][0] ||
    (ret[3][0] + rChild[0][0] == ret[0][0] && ret[3][1] + rChild[0][1] > ret[0][1])) {
        ret[0][0] = ret[3][0] + rChild[0][0];
        ret[0][1] = ret[3][1] + rChild[0][1];
    }
    if (rChild[3][0] + ret[2][0] > rChild[2][0] ||
    (rChild[3][0] + ret[2][0] == rChild[2][0] && rChild[3][1] + ret[2][1] > rChild[2][1])) {
        ret[2][0] = rChild[3][0] + ret[2][0];
        ret[2][1] = rChild[3][1] + ret[2][1];
    } else {
        ret[2][0] = rChild[2][0];
        ret[2][1] = rChild[2][1];
    }
    ret[3][0] += rChild[3][0];
    ret[3][1] += rChild[3][1];
    return ret;
}

void build(ll beg, ll end, ll pos) {
    if (beg == end) {
        segtree[pos][0][1] = segtree[pos][1][1] = segtree[pos][2][1] = segtree[pos][3][1] = 1;
        segtree[pos][0][0] = segtree[pos][1][0] = segtree[pos][2][0] = segtree[pos][3][0] = v[beg];
    } else {
        ll m = (beg + end)/2;
        build(beg, m, 2 * pos);
        build(m + 1, end, 2 * pos + 1);
        for (ll i = 0; i < 4; ++i) {
            segtree[pos][i][0] = segtree[2 * pos][i][0];
            segtree[pos][i][1] = segtree[2 * pos][i][1];
        }
        pair<ll, ll> aux;
        aux.first = segtree[pos][2][0] + segtree[2 * pos + 1][0][0];
        aux.second = segtree[pos][2][1] + segtree[2 * pos + 1][0][1];
        if (aux.first > segtree[pos][1][0] || (aux.first == segtree[pos][1][0] && aux.second > segtree[pos][1][1])) {
            segtree[pos][1][0] = aux.first;
            segtree[pos][1][1] = aux.second;
        }
        if (segtree[2 * pos + 1][1][0] > segtree[pos][1][0] || (segtree[2 * pos + 1][1][0] == segtree[pos][1][0] && segtree[2 * pos + 1][1][1] > segtree[pos][1][1])) {
            segtree[pos][1][0] = segtree[2 * pos + 1][1][0];
            segtree[pos][1][1] = segtree[2 * pos + 1][1][1];
        }
        if (segtree[pos][3][0] + segtree[2 * pos + 1][0][0] > segtree[pos][0][0] ||
        (segtree[pos][3][0] + segtree[2 * pos + 1][0][0] == segtree[pos][0][0] && segtree[pos][3][1] + segtree[2 * pos + 1][0][1] > segtree[pos][0][1])) {
            segtree[pos][0][0] = segtree[pos][3][0] + segtree[2 * pos + 1][0][0];
            segtree[pos][0][1] = segtree[pos][3][1] + segtree[2 * pos + 1][0][1];
        }
        if (segtree[2 * pos + 1][3][0] + segtree[pos][2][0] > segtree[2 * pos + 1][2][0] ||
        (segtree[2 * pos + 1][3][0] + segtree[pos][2][0] == segtree[2 * pos + 1][2][0] && segtree[2 * pos + 1][3][1] + segtree[pos][2][1] > segtree[2 * pos + 1][2][1])) {
            segtree[pos][2][0] = segtree[2 * pos + 1][3][0] + segtree[pos][2][0];
            segtree[pos][2][1] = segtree[2 * pos + 1][3][1] + segtree[pos][2][1];
        } else {
            segtree[pos][2][0] = segtree[2 * pos + 1][2][0];
            segtree[pos][2][1] = segtree[2 * pos + 1][2][1];
        }
        segtree[pos][3][0] += segtree[2 * pos + 1][3][0];
        segtree[pos][3][1] += segtree[2 * pos + 1][3][1];
    }
}

void solve() {
    ll n, q, a, b;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cin >> q;
    build(0, n - 1, 1);
    for (ll i = 0; i < q; ++i) {
        cin >> a >> b;
        ll** ret = freq(a - 1, b - 1, 0, n - 1, 1);
        cout << ret[1][0] << " " << ret[1][1] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    for (ll i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}
