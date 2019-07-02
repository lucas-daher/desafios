#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll d;
    vector<ll> p(3);
    cin >> p[0] >> p[1] >> p[2] >> d;
    sort(p.begin(), p.end());
    ll ret = 0;
    if (p[1] - p[0] < d) {
        ret += d - (p[1] - p[0]);
    }
    if (p[2] - p[1] < d) {
        ret += d - (p[2] - p[1]);
    }
    cout << ret << "\n";
    return 0;
}
