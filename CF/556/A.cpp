#include <bits/stdc++.h>
using namespace std;

int find_min(vector<int>& v) {
    int ret = v[0];
    for (int i = 1; i < v.size(); i++) {
        ret = min(ret, v[i]);
    }
    return ret;
}

int find_max(vector<int>& v) {
    int ret = v[0];
    for (int i = 1; i < v.size(); i++) {
        ret = max(ret, v[i]);
    }
    return ret;
}

int main() {
    int m, n, r;
    cin >> n >> m >> r;
    vector<int> buy(n), sell(m);
    for (int i = 0; i < n; i++) {
        cin >> buy[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> sell[i];
    }
    int buy_min = find_min(buy), sell_max = find_max(sell);
    if (buy_min >= sell_max) {
        cout << r << endl;
        return 0;
    }
    r += (r / buy_min) * (sell_max - buy_min);
    cout << r << endl;
    return 0;
}
