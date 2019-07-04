#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll m, n;
    cin >> m >> n;
    ll cand[4][2], p0[2];
    cin >> p0[0] >> p0[1];
    for (ll i = 0; i < 4; ++i) {
        cand[i][1] = 0;
        if (i < 2) cand[i][0] = p0[0];
        else cand[i][0] = p0[1];
    }
    for (ll i = 1; i < n; ++i) {
        ll c1, c2;
        cin >> c1 >> c2;
        for (ll j = 0; j < 4; ++j) {
            if (cand[j][0] != c1 && cand[j][1] != c1 &&
            cand[j][0] != c2 && cand[j][1] != c2) {
                if (cand[j][1] != 0) {
                    cand[j][0] = cand[j][1] = -1;
                } else {
                    cand[j][1] = (j % 2 == 0 ? c1 : c2);
                }
            }
        }
    }
    for (ll i = 0; i < 4; ++i) {
        if (cand[i][0] != -1) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}