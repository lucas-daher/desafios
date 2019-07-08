#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; ++i) cin >> v[i];
    ll ret = n - 2;
    while (v[ret] == v[ret + 1]) ret--;
    cout << ret + 1 << "\n";
    return 0;
}
