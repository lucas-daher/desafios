//problem: https://www.urionlinejudge.com.br/judge/en/problems/view/2658

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 100000;
ll segtree[4 * N][9], lazy[4 * N];

void propagate(ll beg, ll end, ll pos) {
    ll aux[9];
    for (ll i = 0; i < 9; ++i) {
        aux[(i + lazy[pos]) % 9] = segtree[pos][i];
    }
    for (ll i = 0; i < 9; ++i) {
        segtree[pos][i] = aux[i];
    }
    if (beg != end) {
        lazy[2 * pos] = (lazy[2 * pos] + lazy[pos]) % 9;
        lazy[2 * pos + 1] = (lazy[2 * pos + 1] + lazy[pos]) % 9;
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
    propagate(beg, end, pos);
    update(qbeg, qend, beg, m, 2 * pos, add);
    update(qbeg, qend, m + 1, end, 2 * pos + 1, add);
    propagate(beg, m, 2 * pos);
    propagate(m + 1, end, 2 * pos + 1);
    for (ll i = 0; i < 9; ++i) {
        segtree[pos][i] = segtree[2 * pos + 1][i] + segtree[2 * pos][i];
    }
}

ll* freq(ll qbeg, ll qend, ll beg, ll end, ll pos) {
    ll* v = (ll*) malloc(9 * sizeof(ll));
    for (ll i = 0; i < 9; ++i) {
        v[i] = 0;
    }
    if (end < qbeg || qend < beg) {
        return v;
    }
    propagate(beg, end, pos);
    if (qbeg <= beg && qend >= end) {
        return segtree[pos];
    }
    ll m = (beg + end)/2;
    ll* aux = freq(qbeg, qend, beg, m, 2 * pos);
    for (ll i = 0; i < 9; ++i) {
        v[i] += aux[i];
    }
    aux = freq(qbeg, qend, m + 1, end, 2 * pos + 1);
    for (ll i = 0; i < 9; ++i) {
        v[i] += aux[i];
    }
    return v;
}

void print_all(ll beg, ll end, ll pos) {
    propagate(beg, end, pos);
    if (beg == end) {
        for (ll i = 0; i < 9; ++i) {
            if (segtree[pos][i] == 1) {
                cout << i << "\n";
                return;
            }
        }
    } else {
        ll m = (beg + end)/2;
        print_all(beg, m, 2 * pos);
        print_all(m + 1, end, 2 * pos + 1);
    }
}

void build(ll beg, ll end, ll pos) {
    segtree[pos][1] = end + 1 - beg;
    if (beg != end) {
        ll m = (beg + end)/2;
        build(beg, m, 2 * pos);
        build(m + 1, end, 2 * pos + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
    ll a, b;
    ll* v;
    build(0, n - 1, 1);
    for (ll i = 0; i < q; ++i) {
        cin >> a >> b;
        v = freq(a, b, 0, n - 1, 1);
        ll maxi = 0;
        for (ll i = 1; i < 9; i++) {
            maxi = (v[i] >= v[maxi] ? i : maxi);
        }
        update(a, b, 0, n - 1, 1, maxi);
    }
    print_all(0, n - 1, 1);
    return 0;
}