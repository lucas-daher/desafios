//problem: https://open.kattis.com/problems/almostunionfind

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 1000000;
ll p[N], w[N], els[N], sum[N];

void init(ll sz) {
	for (ll i = 1; i <= sz; i++) {
		p[i] = p[i + sz] = i + sz;
		w[i + sz] = 1;
		els[i + sz] = 1;
		sum[i + sz] = i;
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
	sum[a] += sum[b];
	els[a] += els[b];
}

void move(ll a, ll b) {
    ll root_a = find(a);
    b = find(b);
    if (root_a != b) {
        w[root_a]--;
        w[b]++;
        els[root_a]--;
        sum[root_a] -= a;
        els[b]++;
        sum[b] += a;
        p[a] = b;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b;
    while (cin >> a >> b) {
        init(a);
        for (ll i = 0; i < b; i++) {
            ll c, d, e;
            cin >> c;
            if (c == 1) {
                cin >> d >> e;
                join(d, e);
            } else if (c == 2) {
                cin >> d >> e;
                move(d, e);
            } else {
                cin >> d;
                d = find(d);
                cout << els[d] << " " << sum[d] << "\n";
            }
        }
    }
    return 0;
}