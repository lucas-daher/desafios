#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x, y, z;
    cin >> x >> y >> z;
    if (x > y + z) {
        cout << "+\n";
    } else if (y > x + z) {
        cout << "-\n";
    } else if (x == y && z == 0) {
        cout << "0\n";
    } else {
        cout << "?\n";
    }
    return 0;
}
