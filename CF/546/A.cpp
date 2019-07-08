#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;
    ll read;
    cin >> read;
    ll l = 0, r = n - 1;
    while (l < r) {
        ll mid = (l + r)/2;
        if (v[mid].second < read) l = mid + 1;
        else r = mid;
    }
    cout << n - l << "\n";
    return 0;
}
