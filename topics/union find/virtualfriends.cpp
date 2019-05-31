//problem: https://open.kattis.com/problems/virtualfriends

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 1000000;
ll p[N], w[N], sz[N];

void init() {
	for (ll i = 0; i < N; i++) {
		w[p[i] = i] = 1;
		sz[i] = 1;
    }
}

ll find(ll x) {
	return p[x] = (x == p[x] ? x : find(p[x]));
}

void join(ll a, ll b) {
	if ((a = find(a)) == (b = find(b))) return;
	if (w[a] < w[b]) swap(a, b);
	w[a] += w[b];
	p[b] = a;
	sz[a] += sz[b];
}

ll dec(unordered_map<string, ll>& mp, ll& next, string s) {
    if (mp.find(s) == mp.end()) {
        mp[s] = next++;
    }
    return mp[s];
}

void solve() {
    init();
    ll F, next = 0;
    unordered_map<string, ll> mp;
    cin >> F;
    for (ll i = 0; i < F; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        ll x = dec(mp, next, s1), y = dec(mp, next, s2);
        join(x, y);
        cout << sz[find(x)] << '\n';
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