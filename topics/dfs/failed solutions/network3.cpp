#include <vector>
#include <iostream>
using namespace std;

long long d[100001], low[100001], f[100001], cnt;

const long long N = 1000000;
long long comps, p[N], w[N];

void init() {
	for (long long i = 0; i < N; i++)
		w[p[i] = i] = 1;
}

long long find(long long x) {
	return p[x] = (x == p[x] ? x : find(p[x]));
}

void join(long long a, long long b) {
	if ((a = find(a)) == (b = find(b))) return;
	comps--;
	if (w[a] < w[b]) swap(a, b);
	w[a] += w[b];
	p[b] = a;
}

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
void find_bridges(const vector<vector<long long> >& dfs, long long curr) {
    for (long long i = 0; i < dfs[curr].size(); i++) {
        long long s = dfs[curr][i];
        if (d[s] > d[curr]) {
            if (low[s] < d[curr]) {
               join(s, curr);
           }
           find_bridges(dfs, s);
        }
    }
}

void solve(long long n, long long m) {
    init();
    comps = n;
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
    find_bridges(dfs, 1);
    cin >> a;
    for (long long i = 0; i < a; i++) {
        cin >> b >> c;
        join(b, c);
        cout << comps - 1 << "\n";
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