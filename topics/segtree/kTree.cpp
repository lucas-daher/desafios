//problem: codeforces.com/problemset/problem/431/C

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a, b, c;

ll calc(vector<vector<ll>>& dp, ll x, ll y) {
    if (dp[x][y] != -1) return dp[x][y];
    ll ret = 0;
    if (y == 0) {
        for (ll i = 1; i <= x && i < c; ++i) {
            ret += calc(dp, x - i, 0);
            ret %= 1000000007;
        }
    }
    if (y == 1) {
        for (ll i = 1; i <= x && i <= b; ++i) {
            ret += calc(dp, x - i, 1);
            ret %= 1000000007;
        }
        for (ll i = c; i <= x && i <= b; ++i) {
            ret += calc(dp, x - i, 0);
            ret %= 1000000007;
        }
    }
    dp[x][y] = ret;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> c;
    vector<vector<ll>> dp(a + 1, vector<ll>(2, -1));
    dp[0][0] = 1;
    dp[0][1] = 0;
    cout << calc(dp, a, 1) << endl;
    return 0;
}