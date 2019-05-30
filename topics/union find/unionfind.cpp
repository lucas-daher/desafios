//problem: https://open.kattis.com/problems/unionfind

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 1000000;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b;
    cin >> a >> b;
    init();
    for (ll i = 0; i < b; i++) {
        char q;
        ll x, y;
        cin >> q >> x >> y;
        if (q == '?') {
            cout << (find(x) == find(y) ? "yes\n" : "no\n");
        } else {
            join(x, y);
        }
    }
    return 0;
}
