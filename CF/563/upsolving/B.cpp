#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> v(n);
    bool od = false, ev = false;
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
        if (v[i] % 2 == 0) ev = true;
        else od = true;
    }
    if (od && ev) sort(v.begin(), v.end());
    for (ll i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }
    cout << "\n";
    return 0;
}
