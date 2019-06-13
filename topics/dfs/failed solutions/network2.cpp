#include <vector>
#include <iostream>
using namespace std;

long long d[100001], low[100001], f[100001], cnt;

void dfs_rec(const vector<vector<long long> >& adj, vector<vector<long long> >& dfs, long long curr, long long par) {
    if (d[curr] != -1) return;
    d[curr] = cnt++;
    low[curr] = d[curr];
    for (long long i = 0; i < adj[curr].size(); i++) {
        long long s = adj[curr][i];
        if (d[s] == -1) {
            dfs_rec(adj, dfs, s, curr);
            dfs[curr].push_back(s);
            dfs[s].push_back(curr);
            if (d[s] > d[curr]) {
                low[curr] = min(low[curr], low[s]);
            }
            low[curr] = min(low[curr], d[s]);
        }
        if (s != par) {
            low[curr] = min(low[curr], d[s]);
        }
    }
    f[curr] = cnt++;
}
void find_bridges(const vector<vector<long long> >& dfs, vector<bool>& bridges, long long& size, long long curr) {
    for (long long i = 0; i < dfs[curr].size(); i++) {
        long long s = dfs[curr][i];
        if (d[s] > d[curr]) {
            if (low[s] > d[curr] && !bridges[s]) {
               bridges[s] = true;
               size++;
           }
           find_bridges(dfs, bridges, size, s);
        }
    }
}

bool kill_down(const vector<vector<long long> >& dfs, vector<bool>& bridges, long long& size, long long curr, long long target) {
    if (!(d[curr] <= d[target] && f[curr] >= f[target])) return false;
    for (long long i = 0; i < dfs[curr].size(); i++) {
        long long s = dfs[curr][i];
        if (d[s] > d[curr] && kill_down(dfs, bridges, size, s, target) && bridges[s]) {
            bridges[s] = false;
            size--;
        }
    }
    return true;
}

bool kill_up(const vector<vector<long long> >& dfs, vector<bool>& bridges, long long& size, long long beg, long long curr, long long target) {
    if (!(d[curr] <= d[beg] && f[curr] >= f[beg])) return false;
    if (d[curr] <= d[target] && f[curr] >= f[target]) {
        kill_down(dfs, bridges, size, curr, target);
        return true;
    }
    for (long long i = 0; i < dfs[curr].size(); i++) {
        long long s = dfs[curr][i];
        if (d[s] < d[curr] && kill_up(dfs, bridges, size, beg, s, target) && bridges[curr]) {
            bridges[curr] = false;
            size--;
        }
    }
    return true;
}

void solve(long long n, long long m) {
    vector<vector<long long> > adj(n + 1), dfs(n + 1);
    long long a, b, c;
    for (long long i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (long long i = 0; i <= n; i++) {
        d[i] = -1;
    }
    cnt = 0;
    dfs_rec(adj, dfs, 1, 0);
    vector<bool> bridges(n + 1, false);
    long long bridges_size = 0;
    find_bridges(dfs, bridges, bridges_size, 1);
    cin >> a;
    for (long long i = 0; i < a; i++) {
        cin >> b >> c;
        if (d[b] > d[c]) {
            swap(b, c);
        }
        if (f[b] > f[c]) {
            kill_down(dfs, bridges, bridges_size, b, c);
        } else {
            kill_up(dfs, bridges, bridges_size, b, b, c);
        }
        cout << bridges_size << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m, t = 1;
    while (1) {
        cin >> n >> m;
        if (n || m) {
            cout << "Case " << t++ << ":\n";
            solve(n, m);
        } else {
            return 0;
        }
    }
}