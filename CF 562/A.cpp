#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, s1, f1, s2, f2;
    cin >> n >> s1 >> f1 >> s2 >> f2;
    ll t1 = s1 < f1 ? f1 - s1 : n - (s1 - f1);
    ll t2 = s2 > f2 ? s2 - f2 : n - (f2 - s2);
    ll t = min(t1, t2);
    ll dis = s2 > s1 ? s2 - s1 : n - (s1 - s2);
    
    //cout << t << " " << dis << endl;
    
    if ((dis % 2 == 0 && dis <= 2 * t) ||
    ((dis + n) % 2 == 0 && (dis + n) <= 2 * t)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
