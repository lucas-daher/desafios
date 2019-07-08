#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    cin >> a >> b;
    ll sz_b = b.size(), sz_a = a.size(), ones_a = 0, ones_b = 0, ret = 0;
    for (ll i = 0; i < sz_b; ++i) {
        ones_a += a[i] - '0';
        ones_b += b[i] - '0';
    }
    ones_a %= 2;
    ones_b %= 2;
    if (ones_a == ones_b) {
        ret++;
    }
    for (ll i = 0; i + sz_b < sz_a; ++i) {
        ones_a += a[i] - '0';
        ones_a += a[i + sz_b] - '0';
        ones_a %= 2;
        if (ones_a == ones_b) {
            ret++;
        }
    }
    cout << ret << "\n";
    return 0;
}
