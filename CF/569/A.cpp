#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, ret;
    cin >> n;
    ret = (2 * n * n) - (2 * n - 1);
    cout << ret << "\n";
    return 0;
}
