#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll maxi(const vector<ll>& v, ll els) {
    ll ret = v[0];
    for (ll i = 1; i < els; i++) {
        ret = max(ret, v[i]);
    }
    return ret;
}

void calc(deque<ll>& dq) {
    for(ll i = 1; i < dq.size(); ++i) {
        ll a = dq.front();
        dq.pop_front();
        ll b = dq.front();
        dq.pop_front();
        dq.push_front(max(a, b));
        dq.push_back(min(a, b));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    deque<ll> est;
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
        est.push_back(v[i]);
    }
    calc(est);
    for (ll i = 0; i < q; ++i) {
        ll op;
        cin >> op;
        if (op >= n) {
            cout << est[0] << " ";
            cout << est[1 + ((op - n) % (n - 1))] << "\n";
        } else {
            cout << maxi(v, op) << " ";
            cout << v[op] << "\n";
        }
    }
    return 0;
}