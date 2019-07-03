#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, v[112345], f;

void complete(ll pos) {
    if (v[pos] != 0) return;
    ++f;
    ll nxt = pos;
    while (nxt <= n) {
        if (v[nxt] == 0) v[nxt] = f;
        nxt += pos;
    } 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    f = 0;
    for (ll i = 2; i <= n; ++i) {
        complete(i);
        cout << v[i] << " ";
    }
    cout << "\n";
    return 0;
}