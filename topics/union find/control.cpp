//problem: https://open.kattis.com/problems/control

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 500000;
ll p[N], w[N];
ll comps[N];

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
    init();
    ll r, ret = 0;
    cin >> r;
    for (ll i = 0; i < r; i++) {
        ll s;
        cin >> s;
        vector<ll> ings(s);
        unordered_map<ll, ll> un_q;
        for (ll j = 0; j < s; j++) {
            cin >> ings[j];
            ll a = find(ings[j]);
            if (un_q.find(a) == un_q.end()) {
                un_q[a] = 0;
            } else {
                un_q[a]++;
            }
        }
        bool insert = true;
        for (const auto& it : un_q) {
            if (comps[it.first] != it.second) insert = false;
        }
        if (insert) {
            ret++;
            ll a = find(ings[0]);
            for (ll j = 1; j < s; j++) {
                ll b = find(ings[j]);
                if (a != b) {
                    ll sz = comps[a] + comps[b] + 1;
                    join(a, b);
                    a = find(ings[0]);
                    comps[a] = sz;
                }
            }
        }
    }
    cout << ret << "\n";
    return 0;
}
