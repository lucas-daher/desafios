#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    unordered_map<ll, ll> c_to_q, q_to_c;
    ll ret = 1;
    for (ll i = 0; i < n; i++) {
        if (c_to_q.find(v[i]) == c_to_q.end()) {
            c_to_q[v[i]] = 1;
        } else {
            c_to_q[v[i]]++;
        }
        ll q = c_to_q[v[i]];
        if (q_to_c.find(q) == q_to_c.end()) {
            q_to_c[q] = 1;
        } else {
            q_to_c[q]++;
        }
        if (q > 1) {
            ll aux = --q_to_c[q - 1];
            if (aux == 0) {
                q_to_c.erase(q - 1);
            }
        }
        if (q_to_c.size() == 2) {
            auto it = q_to_c.begin();
            pair<ll, ll> qc1, qc2;
            qc1.first = it->first;
            qc1.second = it->second;
            it++;
            qc2.first = it->first;
            qc2.second = it->second;
            if (abs(qc1.first - qc2.first) == 1) {
                if (qc1.first > qc2.first ? qc1.second == 1 : qc2.second == 1) {
                    ret = i + 1;
                }
            }
            if ((qc1.first == 1 && qc1.second == 1) ||
                (qc2.first == 1 && qc2.second == 1)) {
                ret = i + 1;
            }
        } else if (q_to_c.size() == 1) {
            auto it = q_to_c.begin();
            if (it->first == 1 || it->second == 1) {
                ret = i + 1;
            }
        }
    }
    cout << ret << endl;
    return 0;
}