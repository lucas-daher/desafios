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
    ll z = 0, o = 0;
    for (ll i = 0; i < s.size(); ++i) {
        if (s[i] == '0') ++z;
        else ++o;
    }
    if (z != o) {
        cout << 1 << "\n";
        cout << s << "\n";
    } else {
        cout << 2 << "\n";
        cout << s[0] << " ";
        for (ll i = 1; i < s.size(); ++i) cout << s[i];
        cout << "\n";
    }
    return 0;
}
