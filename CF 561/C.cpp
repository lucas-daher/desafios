#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll bs(const vector<ll>& v, ll target, ll begin, ll end) {
    if (begin == end) {
        return begin;
    }
    ll mid = (end + begin + 1)/2;
    if (v[mid] > target) {
        return bs(v, target, begin, mid - 1);
    }
    return bs(v, target, mid, end);
}

int main() {
    ll n;
    cin >> n;
    vector<ll> numbs(n);
    for (ll i = 0; i < n; i++) {
        cin >> numbs[i];
        numbs[i] = abs(numbs[i]);
    }
    sort(numbs.begin(), numbs.end());
    ll ret = 0;
    for (ll i = 0; i < n; i++) {
        ll aux = bs(numbs, 2 * numbs[i], i, n - 1);
        ret += aux - i;
    }
    cout << ret << endl;
    return 0;
}