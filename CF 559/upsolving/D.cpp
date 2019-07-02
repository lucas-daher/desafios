#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll rows, cols;
    cin >> rows >> cols;
    for (ll i = 1; i <= rows/2; ++i) {
        ll j = 1, x = rows + 1 - i, y = cols;
        while (y > 0) {
            cout << i << " " << j << "\n";
            cout << x << " " << y << "\n";
            ++j;
            --y;
        }
    }
    if ((rows + 1)/2 > rows/2) {
        ll i = (rows + 1)/2, j = 1, k = cols;
        while (j < k) {
            cout << i << " " << j << "\n";
            cout << i << " " << k << "\n";
            ++j;
            --k;
        }
        if (j == k) {
            cout << i << " " << j << "\n";
        }
    }
    return 0;
}
