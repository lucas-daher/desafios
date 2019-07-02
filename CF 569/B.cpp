#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, maxi = 0, maxi_pos;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
        if (v[i] >= 0) v[i] = -v[i] - 1;
        if (i == 0 || - v[i] - 1 > maxi) {
            maxi = - v[i] - 1;
            maxi_pos = i;
        }
    }
    if (n % 2 == 1) {
        v[maxi_pos] = -v[maxi_pos] - 1;
    }
    for (ll i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }
    cout << "\n";
    return 0;
}