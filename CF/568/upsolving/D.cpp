#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; ++i) {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(v.begin(), v.end());
    if (v.size() < 3) {
        cout << 1 << "\n";
        return 0;
    }
    ll dif[3], ret[3];
    dif[0] = v[1].first - v[0].first;
    dif[1] = v[2].first - v[0].first;
    dif[2] = v[2].first - v[1].first;
    ret[0] = ((dif[2] == dif[0]) ? -2 : v[2].second);
    ret[1] = v[1].second;
    ret[2] = v[0].second;
    for (ll i = 3; i < n; ++i) {
        for (ll j = 0; j < 3; ++j) {
            ll prev = (ret[j] == v[i - 1].second ? i - 2 : i - 1);
            if (v[i].first - v[prev].first != dif[j]) {
                if (ret[j] == -2) ret[j] = v[i].second;
                else ret[j] = -1;
            }
        }
    }
    for (ll i = 0; i < 3; ++i) {
        if (ret[i] > -1) {
            cout << ret[i] << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}
