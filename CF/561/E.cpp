#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll m, n;
    cin >> m >> n;
    vector<vector<ll>> v(m);
    for (ll i = 0; i < m; i++) {
        ll aux;
        cin >> aux;
        v[i] = vector<ll>(aux);
        for (ll j = 0; j < aux; j++) {
            cin >> v[i][j];
        }
    }
    unordered_set<ll> ref;
    ll count;
    for (ll i = 0; i < m; i++) {
        ref.clear();
        for (ll j = 0; j < v[i].size(); j++) {
            ref.insert(v[i][j]);
        }
        for (ll j = i + 1; j < m; j++) {
            count = 0;
            for (ll k = 0; k < v[j].size(); k++) {
                if (ref.find(v[j][k]) != ref.end()) {
                   count++;
                }
            }
            if (count == 0) {
                cout << "impossible" << endl;
                return 0;
            }
        }
    }
    cout << "possible" << endl;
    return 0;
}