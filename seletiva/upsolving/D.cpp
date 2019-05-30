#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 300001;

vector<ll> adj[N];
unordered_set<ll> visited;
ll longest_path[N];

ll p[N], w[N];

void init() {
	for (int i = 0; i < N; i++)
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

ll longest_rec(ll node, ll& ret) {
    if (visited.find(node) != visited.end()) return 0;
    visited.insert(node);
    pair<ll, ll> h = {0, 0};
    for (ll vis : adj[node]) {
        ll aux = longest_rec(vis, ret);
        if (aux >= h.first) {
            h.second = h.first;
            h.first = aux;
        } else if (aux >= h.second) {
            h.second = aux;
        }
    }
    ret = max(ret, 1 + h.first + h.second);
    return h.first + 1;
}

ll longest(ll node) {
    ll ret = 0;
    longest_rec(node, ret);
    return ret - 1;
}

void connect(ll n1, ll n2) {
    ll cc1 = find(n1), cc2 = find(n2);
    if (cc1 != cc2) {
        ll lp1 = longest_path[cc1], lp2 = longest_path[cc2];
        ll lp = max(lp1, lp2);
        lp = max(lp, (lp1 + 1)/2 + (lp2 + 1)/2 + 1);
        join(n1, n2);
        longest_path[find(n1)] = lp;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, q;
    cin >> n >> m >> q;
    init();
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        join(a, b);
    }
    for (ll i = 1; i <= n; i++) {
        if (visited.find(i) == visited.end()) {
            ll aux = find(i);
            longest_path[aux] = longest(i);
        }
    }
    for (ll i = 0; i < q; i++) {
        ll a, b;
        cin >> a;
        if (a == 1) {
            cin >> a;
            ll aux = find(a);
            cout << longest_path[aux] << "\n";
        } else {
            cin >> a >> b;
            connect(a, b);
        }
    }
    return 0;
}
