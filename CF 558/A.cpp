#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    cout << min(n - m, max(m, 1)) << endl;
    return 0;
}
