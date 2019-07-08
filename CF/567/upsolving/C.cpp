#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[1000][1000][3], sz[1000][1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll l, c, ret = 0;
    cin >> l >> c;
    vector<vector<char>> m(l, vector<char>(c));
    for (ll i = 0; i < l; ++i) {
        for (ll j = 0; j < c; ++j) {
            cin >> m[i][j];
        }
    }
    for (ll i = 0; i < c; ++i) {
        dp[0][i][0] = 1;
        dp[0][i][1] = -1;
        dp[0][i][2] = -1;
        if (i > 0 && m[0][i - 1] == m[0][i]) {
            sz[0][i] = 1 + sz[0][i - 1];
        } else {
            sz[0][i] = 1;
        }
    }
    for (ll i = 1; i < l; ++i) {
        for (ll j = 0; j < c; ++j) {
            if (j > 0 && m[i][j - 1] == m[i][j]) {
                sz[i][j] = 1 + sz[i][j - 1];
            } else {
                sz[i][j] = 1;
            }
            if (m[i][j] == m[i - 1][j]) {
                dp[i][j][0] = dp[i - 1][j][0] + 1;
                dp[i][j][1] = (dp[i - 1][j][1] == -1 ? -1 : dp[i - 1][j][1] + 1);
                dp[i][j][2] = (dp[i - 1][j][2] == -1 ? -1 : dp[i - 1][j][2] + 1);
            } else {
                dp[i][j][0] = 1;
                dp[i][j][1] = 1;
                dp[i][j][2] = (dp[i - 1][j][1] == -1 ? -1 : 1);
            }
            if (dp[i][j][2] != -1) {
                if (dp[i][j][2] == dp[i - dp[i][j][2]][j][1]
                    && dp[i - dp[i][j][2]][j][1] <= dp[i - (dp[i][j][2] + dp[i - dp[i][j][2]][j][1])][j][0]) {
                    ll curr = sz[i][j];
                    for (ll k = 0; k < 3 * dp[i][j][2]; ++k) {
                        curr = min(curr, sz[i - k][j]);
                    }
                    ret += curr;
                }
            }
        }
    }
    cout << ret << "\n";
    return 0;
}
