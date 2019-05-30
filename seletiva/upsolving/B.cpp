#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll adj[1000000];
bool seen[1000000];
ll exps[1000000];

ll calc(ll p, ll k, ll comps) {
    if (exps[comps] != 0) return exps[comps];
    if (k == 0) return p;
    ll ret = 1;
    ll aux = 1;
    for (ll i = 0; i < comps; i++) {
        aux *= k;
        aux %= p;
    }
    for (ll i = 1; i < p; i++) {
        if (((aux * i) % p) == i) ret++;
    }
    exps[comps] = ret;
    return ret;
}

ll dfs(ll pos) {
    if (seen[pos]) return 0;
    seen[pos] = true;
    return 1 + dfs(adj[pos]);
}

int main() {
    ll p, k;
    cin >> p >> k;
    for (ll i = 1; i < p; i++) {
        ll aux = (i * k) % p;
        adj[i] = aux;
        seen[i] = false;
    }
    
    vector<ll> comps;
    for (ll i = 1; i < p; i++) {
        if (!seen[i]) {
            comps.push_back(dfs(i));
        }
    }
    ll ret = (k == 1 ? p : 1);
    for (ll i = 0; i < comps.size(); i++) {
        ret *= calc(p, k, comps[i]);
        ret %= 1000000007;
    }
    cout << ret << endl;
    return 0;
}
