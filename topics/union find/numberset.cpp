//problem: https://open.kattis.com/problems/numbersetshard

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 1000001;
ll p[N], w[N];
bool not_prime[1000000];
ll joins;

void init() {
	for (ll i = 0; i < N; i++)
		w[p[i] = i] = 1;
}

ll find(ll x) {
	return p[x] = (x == p[x] ? x : find(p[x]));
}

void join(ll a, ll b) {
	if ((a = find(a)) == (b = find(b))) return;
	joins++;
	if (w[a] < w[b]) swap(a, b);
	w[a] += w[b];
	p[b] = a;
}

void solve(ll t) {
    init();
    joins = 0;
    ll l, r, p;
    cin >> l >> r >> p;
    for (ll i = p; i < 1000000; i++) {
        if (!not_prime[i]) {
            ll base = l/i;
            base += (l % i > 0) ? 1 : 0;
            base *= i;
            ll curr = base;
            while (curr <= r) {
                join(base - l, curr - l);
                curr += i;
            }
        }
    }
    cout << "Case #" << t << ": " << r + 1 - (l + joins) << "\n";
}
void calc_primes() {
    for (ll i = 2; i < 1000000; i++) {
        if(!not_prime[i]) {
            ll curr = 2 * i;
            while (curr < 1000000) {
                not_prime[curr] = true;
                curr += i;
            }
        }
    }
}
int main() {
    ll t;
    cin >> t;
    calc_primes();
    for (ll i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}