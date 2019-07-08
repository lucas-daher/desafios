#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calc(ll n) {
    if (n == 0) return 0;
    ll ret = 1;
    while (n != 0) {
        ret *= n % 10;
        n /= 10;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll ret = calc(n);
    ll change = 10;
    while (change <= n) {
        ll curr = n;
        curr -= (n % change);
        --curr;
        ret = max(ret, calc(curr));
        change *= 10;
    }
    cout << ret << "\n";
    return 0;
}