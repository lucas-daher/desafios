#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll ret = 1;
    if (n % 2) {
        cout << 0 << "\n";
        return 0;
    }
    for (ll i = 0; i < n; i+= 2) {
        ret *= 2;
    }
    cout << ret << "\n";
    return 0;
}
