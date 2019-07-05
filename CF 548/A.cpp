#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ret = 0;
    for (ll i = 0; i < n; ++i) {
        if ((s[i] - '0') % 2 == 0) {
            ret += i + 1;
        }
    }
    cout << ret << "\n";
    return 0;
}
