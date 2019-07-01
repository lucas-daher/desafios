//problem: https://www.spoj.com/problems/MKTHNUM/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 100000;
vector<ll> segtree[4 * N];
vector<ll> v;

ll els(ll qbeg, ll qend, ll beg, ll end, ll pos, ll k) {
    if (end < qbeg || qend < beg) {
        return 0;
    }
    if (qbeg <= beg && qend >= end) {
        return lower_bound(segtree[pos].begin(), segtree[pos].end(), k) - segtree[pos].begin();
    }
    ll m = (beg + end)/2;
    return els(qbeg, qend, beg, m, 2 * pos, k) + els(qbeg, qend, m + 1, end, 2 * pos + 1, k);
}

void build(ll beg, ll end, ll pos) {
    if (beg == end) {
        segtree[pos].push_back(v[beg]);
    } else {
        ll m = (beg + end)/2;
        build(beg, m, 2 * pos);
        build(m + 1, end, 2 * pos + 1);
        segtree[pos].resize(segtree[2 * pos].size() + segtree[2 * pos + 1].size());
        merge(segtree[2 * pos].begin(), segtree[2 * pos].end(), segtree[2 * pos + 1].begin(), segtree[2 * pos + 1].end(), segtree[pos].begin());
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    v.resize(n);
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
    }
    build(0, n - 1, 1);
    sort(v.begin(), v.end());
    for (ll x = 0; x < m; ++x) {
        ll i, j, k;
        cin >> i >> j >> k;
        ll beg = 0, m, end = n - 1;
        while (beg  + 1 < end) {
            m = (beg + end)/2;
            ll ret = els(i - 1, j - 1, 0, n - 1, 1, v[m]);
            if (ret < k) beg = m;
            else end = m;
        }
        if (els(i - 1, j - 1, 0, n - 1, 1, v[end]) < k)
            cout << v[end] << "\n";
        else
            cout << v[beg] << "\n";
    }
    return 0;
}