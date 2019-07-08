#include <bits/stdc++.h>
using namespace std;

int update(int curr, int cand) {
    if (curr == -1) return cand;
    return min(curr, cand);
}

int main() {
    int n, m, h, aux;
    cin >> n >> m >> h;
    vector<vector<int>> ret(n, vector<int>(m, -1));
    for (int i = 0; i < m; i++) {
        cin >> aux;
        for (int j = 0; j < n; j++) {
            ret[j][i] = update(ret[j][i], aux);
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> aux;
        for (int j = 0; j < m; j++) {
            ret[i][j] = update(ret[i][j], aux);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> aux;
            ret[i][j] = aux == 0 ? 0 : ret[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    } 
    return 0;
}