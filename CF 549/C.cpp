#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    for (pair<ll, ll>& el : v) cin >> el.first >> el.second;
    set<ll> del;
    for (ll i = 0; i < n; ++i) {
        if (v[i].second == 1) {
            del.insert(i + 1);
        }
    }
    for (ll i = 0; i < n; ++i) {
        if (v[i].second == 0) {
            del.erase(v[i].first);
        }
    }
    if (del.size() == 0) {
        cout << -1 << "\n";
    } else {
        for (auto it : del) {
            cout << it << " ";
        }
        cout << "\n";
    }
    return 0;
}