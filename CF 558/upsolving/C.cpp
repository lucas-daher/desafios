#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll find_gcd(ll a, ll b, ll c) {
    ll ret = __gcd(a, __gcd(b, c));
    return ret != 0 ? ret : 1;
}

void v_print(vector<vector<ll>> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> poles(n);
    for (int i = 0; i < n; i++) {
        cin >> poles[i].first >> poles[i].second;
    }
    vector<vector<ll>> wires;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll a = poles[i].second - poles[j].second,
               b = poles[i].first - poles[j].first,
               c = poles[i].second * poles[j].first - poles[j].second * poles[i].first;
            ll d = find_gcd(a, b, c);
            d = ((a > 0 && d < 0) || (a < 0 && d > 0)) ? -d : d;
            wires.push_back({a/d, b/d, c/d});
        }
    }
    
    //v_print(wires);
    
    sort(wires.begin(), wires.end());
    wires.erase(unique(wires.begin(), wires.end()), wires.end());
    
    //v_print(wires);
    
    ll aux1 = wires.size(), aux2 = wires.size() - 1;
    ll ret = aux1 * aux2 /2LL;
    for (ll i = 0; i < wires.size();) {
        ll j = i + 1, paralels = 1;
        while (j < wires.size() &&
               wires[j][0] == wires[i][0] &&
               wires[j][1] == wires[i][1]) {
                j++;
                paralels++;
               }
        ret -= paralels * (paralels - 1) / 2;
        i = j;
    }
    cout << ret << endl;
    return 0;
}
