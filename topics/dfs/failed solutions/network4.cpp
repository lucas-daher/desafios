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
            dfs[curr].push_back(s);
            dfs[s].push_back(curr);
            dfs_rec(adj, dfs, s, curr);
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

void kill_bridges(const vector<vector<long long> >& dfs, vector<bool>& bridges, long long& size, long long a, long long b) {
    while (f[a] < d[b]) {
        if (bridges[a]) {
            bridges[a] = false;
            size--;
        }
        a = dfs[a][0];
    }
    while (b != a) {
        if (bridges[b]) {
            bridges[b] = false;
            size--;
        }
        b = dfs[b][0];
    }
}

void solve(long long n, long long m) {
    vector<vector<long long> > adj(n + 1), dfs(n + 1);
    long long a, b, c;
    for (long long i = 0; i < m; i++) {
        scanf("%lld%lld", &a, &b);
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
    scanf("%lld", &a);
    for (long long i = 0; i < a; i++) {
        scanf("%lld%lld", &b, &c);
        if (d[b] > d[c]) {
            swap(b, c);
        }
        kill_bridges(dfs, bridges, bridges_size, b, c);
        printf("%lld\n", bridges_size);
    }
}

int main() {
    long long n, m, t = 1;
    while (1) {
        scanf("%lld%lld", &n , &m);
        if (n || m) {
            printf("Case %lld:\n", t++);
            solve(n, m);
        } else {
            return 0;
        }
    }
}