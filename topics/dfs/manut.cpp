\\problem: https://br.spoj.com/problems/MANUT/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll d[401], low[401], cnt;

void dfs_rec(const vector<vector<ll>>& adj, vector<vector<ll>>& dfs, ll curr) {
    if (d[curr] != -1) return;
    d[curr] = cnt++;
    low[curr] = d[curr];
    for (ll s : adj[curr]) {
        if (d[s] == -1) {
            dfs_rec(adj, dfs, s);
            dfs[curr].push_back(s);
            if (d[s] > d[curr]) {
                low[curr] = min(low[curr], low[s]);
            }
        }
        low[curr] = min(low[curr], d[s]);
    }
}

void solve(ll n, ll m) {
    vector<vector<ll>> adj(n + 1), dfs(n + 1);
    ll a, b;
    for (ll i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (ll i = 0; i <= n; i++) {
        d[i] = -1;
    }
    cnt = 0;
    dfs_rec(adj, dfs, 1);
    vector<ll> ret;
    if (dfs[1].size() >= 2) {
        ret.push_back(1);
    }
    for (ll i = 2; i <= n; i++) {
        for (ll s : dfs[i]) {
            if (low[s] >= d[i]) {
                ret.push_back(i);
                break;
            }
        }
    }
    if (ret.size() == 0) {
        cout << "nenhum\n\n";
    } else {
        for (ll el : ret) {
            cout << el << " ";
        }
        cout << "\n\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, t = 1;
    while (1) {
        cin >> n >> m;
        if (n || m) {
            cout << "Teste " << t++ << "\n";
            solve(n, m);
        } else {
            return 0;
        }
    }
}
