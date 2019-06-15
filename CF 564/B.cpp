#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> ret(n);
    ll a = 1, b = 1;
    for (ll i = 0; i < n; i++) {
        ret[i].first = a;
        ret[i].second = b;
        if (a == b) {
            a++;
        } else {
            b++;
        }
    }
    cout << ret[n - 1].first << "\n";
    for (ll i = 0; i < n; i++) {
        cout << ret[i].first << " "<< ret[i].second << "\n";
    }
    return 0;
}