#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll v[300000];

bool solve(ll m, ll n, ll k) {
    ll prev = 0;
    for (ll i = 0; i < m; ++i) {
        if (v[i] + k < prev) return false;
        if (v[i] > prev) {
            if (v[i] + k < n || (v[i] + k) % n < prev) {
                prev = v[i];
            }
        }
        //cout << prev << " ";
    }
    //cout << endl;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll m, n;
    cin >> m >> n;
    for (ll i = 0; i < m; ++i) cin >> v[i];
    ll l = 0, r = n - 1;
    while (l < r) {
        ll mid = (l + r)/2;
        if (solve(m, n, mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
        //cout << l << " " << r << "\n";
    }
    cout << l << "\n";
    return 0;
}
