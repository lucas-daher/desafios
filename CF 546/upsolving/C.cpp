#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<multiset<ll>> a(m + n), b(m + n);
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            ll el;
            cin >> el;
            a[i + j].insert(el);
        }
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            ll el;
            cin >> el;
            b[i + j].insert(el);
        }
    }
    for (ll i = 0; i + 1 < m + n; ++i) {
        if (a[i] != b[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
