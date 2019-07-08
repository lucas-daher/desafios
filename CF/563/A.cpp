#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> v(2 * n);
    for (ll i = 0; i < 2 * n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll f_h = 0, s_h = 0;
    for (ll i = 0; i < 2 * n; ++i) {
        if (i < n) f_h += v[i];
        else s_h += v[i];
    }
    if (f_h == s_h) {
        cout << -1 << "\n";
    } else {
        for (ll i = 0; i < 2 * n; ++i) {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
