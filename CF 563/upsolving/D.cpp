#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x, up_b;
    vector<ll> ret;
    cin >> n >> x;
    up_b = pow(2, n);
    unordered_set<ll> av;
    for (ll i = 1; i < up_b; ++i) av.insert(i);
    av.erase(x);
    while (av.size() > 0) {
        ll el = *(av.begin());
        ret.push_back(el);
        av.erase(el);
        av.erase(el ^ x);
    }
    cout << ret.size() << "\n";
    if (ret.size() > 0)
        cout << ret[0] << " ";
    for (ll i = 1; i < ret.size(); ++i) {
        cout << (ret[i] ^ ret[i - 1]) << " ";
    }
    if (ret.size() > 0)
        cout << "\n";
    return 0;
}
