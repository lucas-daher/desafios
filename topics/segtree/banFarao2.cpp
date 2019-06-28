//problem: https://br.spoj.com/problems/BANFARAO/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 100000;
pair<ll, ll> segtree[4 * N][4], q[4 * N][4];
ll v[N];

pair<ll, ll>* freq(ll qbeg, ll qend, ll beg, ll end, ll pos) {
    pair<ll, ll>* ret = q[pos];
    for (ll i = 0; i < 4; i++) {
        ret[i].first = ret[i].second = -11234;
    }
    if (end < qbeg || qend < beg) {
        return ret;
    }
    if (qbeg <= beg && qend >= end) {
        for (ll i = 0; i < 4; i++) {
           ret[i].first = segtree[pos][i].first;
           ret[i].second = segtree[pos][i].second;
        }
        return ret;
    }
    ll m = (beg + end)/2;
    pair<ll, ll>* lChild = freq(qbeg, qend, beg, m, 2 * pos);
    pair<ll, ll>* rChild = freq(qbeg, qend, m + 1, end, 2 * pos + 1);
    pair<ll, ll> aux;
    aux.first = lChild[2].first + rChild[0].first;
    aux.second = lChild[2].second + rChild[0].second;
    if (aux.first > lChild[1].first || (aux.first == lChild[1].first && aux.second > lChild[1].second)) {
        ret[1].first = aux.first;
        ret[1].second = aux.second;
    } else {
        ret[1].first = lChild[1].first;
        ret[1].second = lChild[1].second;
    }
    if (rChild[1].first > ret[1].first || (rChild[1].first == ret[1].first && rChild[1].second > ret[1].second)) {
        ret[1].first = rChild[1].first;
        ret[1].second = rChild[1].second;
    }
    if (lChild[3].first + rChild[0].first > lChild[0].first ||
    (lChild[3].first + rChild[0].first == lChild[0].first && lChild[3].second + rChild[0].second > lChild[0].second)) {
        ret[0].first = lChild[3].first + rChild[0].first;
        ret[0].second = lChild[3].second + rChild[0].second;
    } else {
        ret[0].first = lChild[0].first;
        ret[0].second = lChild[0].second;
    }
    if (rChild[3].first + lChild[2].first > rChild[2].first ||
    (rChild[3].first + lChild[2].first == rChild[2].first && rChild[3].second + lChild[2].second > rChild[2].second)) {
        ret[2].first = rChild[3].first + lChild[2].first;
        ret[2].second = rChild[3].second + lChild[2].second;
    } else {
        ret[2].first = rChild[2].first;
        ret[2].second = rChild[2].second;
    }
    ret[3].first = lChild[3].first + rChild[3].first;
    ret[3].second = lChild[3].first + rChild[3].second;
    return ret;
}

void build(ll beg, ll end, ll pos) {
    if (beg == end) {
        segtree[pos][0].second = segtree[pos][1].second = segtree[pos][2].second = segtree[pos][3].second = 1;
        segtree[pos][0].first = segtree[pos][1].first = segtree[pos][2].first = segtree[pos][3].first = v[beg];
    } else {
        ll m = (beg + end)/2;
        build(beg, m, 2 * pos);
        build(m + 1, end, 2 * pos + 1);
        for (ll i = 0; i < 4; ++i) {
            segtree[pos][i].first = segtree[2 * pos][i].first;
            segtree[pos][i].second = segtree[2 * pos][i].second;
        }
        pair<ll, ll> aux;
        aux.first = segtree[pos][2].first + segtree[2 * pos + 1][0].first;
        aux.second = segtree[pos][2].second + segtree[2 * pos + 1][0].second;
        if (aux.first > segtree[pos][1].first || (aux.first == segtree[pos][1].first && aux.second > segtree[pos][1].second)) {
            segtree[pos][1].first = aux.first;
            segtree[pos][1].second = aux.second;
        }
        if (segtree[2 * pos + 1][1].first > segtree[pos][1].first || (segtree[2 * pos + 1][1].first == segtree[pos][1].first && segtree[2 * pos + 1][1].second > segtree[pos][1].second)) {
            segtree[pos][1].first = segtree[2 * pos + 1][1].first;
            segtree[pos][1].second = segtree[2 * pos + 1][1].second;
        }
        if (segtree[pos][3].first + segtree[2 * pos + 1][0].first > segtree[pos][0].first ||
        (segtree[pos][3].first + segtree[2 * pos + 1][0].first == segtree[pos][0].first && segtree[pos][3].second + segtree[2 * pos + 1][0].second > segtree[pos][0].second)) {
            segtree[pos][0].first = segtree[pos][3].first + segtree[2 * pos + 1][0].first;
            segtree[pos][0].second = segtree[pos][3].second + segtree[2 * pos + 1][0].second;
        }
        if (segtree[2 * pos + 1][3].first + segtree[pos][2].first > segtree[2 * pos + 1][2].first ||
        (segtree[2 * pos + 1][3].first + segtree[pos][2].first == segtree[2 * pos + 1][2].first && segtree[2 * pos + 1][3].second + segtree[pos][2].second > segtree[2 * pos + 1][2].second)) {
            segtree[pos][2].first = segtree[2 * pos + 1][3].first + segtree[pos][2].first;
            segtree[pos][2].second = segtree[2 * pos + 1][3].second + segtree[pos][2].second;
        } else {
            segtree[pos][2].first = segtree[2 * pos + 1][2].first;
            segtree[pos][2].second = segtree[2 * pos + 1][2].second;
        }
        segtree[pos][3].first += segtree[2 * pos + 1][3].first;
        segtree[pos][3].second += segtree[2 * pos + 1][3].second;
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
        pair<ll, ll>* ret = freq(a - 1, b - 1, 0, n - 1, 1);
        cout << ret[1].first << " " << ret[1].second << "\n";
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
