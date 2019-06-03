//problem: https://open.kattis.com/problems/kastenlauf

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 102;
ll p[N], w[N];

void init() {
	for (ll i = 0; i < N; i++)
		w[p[i] = i] = 1;
}

ll find(ll x) {
	return p[x] = (x == p[x] ? x : find(p[x]));
}

void join(ll a, ll b) {
	if ((a = find(a)) == (b = find(b))) return;
	if (w[a] < w[b]) swap(a, b);
	w[a] += w[b];
	p[b] = a;
}

void solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n + 2);
    for (ll i = 0; i < n + 2; i++) {
        cin >> v[i].first >> v[i].second;
    }
    init();
    for (ll i = 0; i < n + 2; i++) {
        for (ll j = i + 1; j < n + 2; j++) {
            if (abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second) <= 1000) {
                join(i, j);
            }
        }
    }
    if (find(0) == find(n + 1)) {
        cout << "happy\n";
    } else {
        cout << "sad\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++) {
        solve();
    }
    return 0;
}