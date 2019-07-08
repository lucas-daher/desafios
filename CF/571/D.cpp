#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<double> v(n);
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
        sum += floor(v[i]);
    }
    for (ll i = 0; i < n; ++i) {
        if (sum < 0 && v[i] > floor(v[i])) {
            cout << floor(v[i] + 1) << "\n";
            sum++;
        } else {
            cout << floor(v[i]) << "\n";
        }
    }
    return 0;
}