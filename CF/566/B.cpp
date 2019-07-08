#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll m, n;

bool check(const vector<vector<char>>& grid, ll line, ll col, bool hor_line) {
    if (line == m) return hor_line;
    ll beg = -1, end = -1;
    for (ll i = 0; i < n; i++) {
        if (grid[line][i] == '*') {
            if (beg == -1) {
                beg = end = i;
            } else {
                if (i == end + 1) {
                    end++;
                } else {
                    return false;
                }
            }
        }
    }
    if (beg == -1 && col != -1) return check(grid, line + 1, n, hor_line);
    if (beg == end) {
        return ((beg == col || col == -1) ? check(grid, line + 1, beg, hor_line) : false);
    } else {
        if (hor_line) return false;
        if (col <= beg || col >= end) return false;
        if (line + 1 == m) return false;
        if (grid[line + 1][col] != '*') return false;
        return check(grid, line + 1, col, true);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    for (ll i = 0; i < m; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    if (check(grid, 0, -1, false)) {
        cout << "YES\n";
    } else {
        cout <<"NO\n";
    }
    return 0;
}