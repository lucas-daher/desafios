#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll d[100000], low[100000], f[100000], cnt;
bool bridges[100000];

void dfs_rec(const vector<vector<long long> >& adj, vector<vector<long long> >& dfs, long long curr, long long par) {
    if (d[curr] != 0) return;
    d[curr] = ++cnt;
    low[curr] = curr;
    for (ll s : adj[curr]) {
        if (d[s] == 0) {
            dfs[curr].push_back(s);
            dfs[s].push_back(curr);
            dfs_rec(adj, dfs, s, curr);
            if (d[s] > d[curr]) {
                if (d[low[s]] < d[low[curr]])
                    low[curr] = low[s];
            }
        }
        if (s != par) {
            if (d[s] < d[low[curr]])
                low[curr] = s;
        }
    }
    f[curr] = ++cnt;
}

void find_bridges(const vector<vector<long long> >& dfs, long long curr) {
    for (ll s : dfs[curr]) {
        if (d[s] > d[curr]) {
            if (low[s] > d[curr]) {
               bridges[s] = true;
           }
           find_bridges(dfs, s);
        }
    }
}

bool check(const vector<vector<ll>>& dfs, ll a, ll b, ll v1, ll v2) {
    if (d[v2] < d[v1]) {
        swap(v1, v2);
    }
    
    //cout << "pre check " << v1 << " " << v2 << endl;
    
    if (dfs[v2][0] != v1 || !bridges[v2]) {
        return false;
    }
    //cout << "pass\n";
    if (d[a] > d[b]) {
        swap(a, b);
    }
    if (f[a] > f[b]) {
        return (d[a] <= d[v1] && d[v2] <= d[b] && f[a] >= f[v1] && f[v2] >= f[b]);
    }
    //cout << "ds = " << d[v1] << " " << d[v2] << " " << d[a] << " " << d[b] << "\n";
    //cout << "fs = " << f[v1] << " " << f[v2] << " " << f[a] << " " << f[b] << "\n";
    return ((d[v2] <= d[a] && f[v2] >= f[a] && f[v2] < d[b]) ||
            (d[v2] <= d[b] && f[v2] >= f[b] && d[v2] > f[a]));
}

bool check_v(const vector<vector<ll>>& dfs, ll a, ll b, ll v) {
    if (d[a] > d[b]) {
        swap(a, b);
    }
    if (f[a] < d[b]) {
        if (anc(v, a) && d[low[a]] >= d[v] && !anc(low[a], b))
            return true;
        if (anc(v, b) && d[low[b]] >= d[v] && !anc(low[b], a))
            return true;
        if (anc(v, a) && anc(v, b)) {
            
        }
    }
    ll aux;
    while (f[a] < d[b]) {
        aux = (low[a] == a ? dfs[a][0] : low[a]);
        if (aux == v) return true;
        a = aux;
    }
    while (d[a] < d[b]) {
        aux = (low[b] == b ? dfs[b][0] : low[b]);
        if (aux == v && d[a] < d[b]) return true;
        b = aux;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll v, e, s, t, q;
    cin >> v >> e;
    vector<vector<ll>> adj(v), dfs(v);
    for (ll i = 0; i < e; i++) {
        cin >> s >> t;
        --s; --t;
        adj[s].push_back(t);
        adj[t].push_back(s);
    }
    
    dfs_rec(adj, dfs, 0, 0);
    find_bridges(dfs, 0);
    
    cin >> q;
    ll type, a, b, v1, v2;
    for (ll i = 0; i < q; i++) {
        cin >> type;
        if (type == 1) {
            cin >> a >> b >> v1 >> v2;
            --a; --b; --v1; --v2;
            cout << (check(dfs, a, b, v1, v2) ? "ne\n" : "da\n");
        } else {
            cin >> a >> b >> v1;
            --a; --b; --v1;
            cout << (check_v(dfs, a, b, v1) ? "ne\n" : "da\n");
        }
    }
    return 0;
}
