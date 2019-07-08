#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b, p;
    ll num_c, emp = 0;
    cin >> a >> b >> p;
    num_c = a / p;
    num_c += b / p;
    if ((a % p) + (b % p) >= p) {
        num_c++;
        emp = p - max(a % p, b % p);
    }
    cout << num_c << " " << emp << "\n";
    return 0;
}
