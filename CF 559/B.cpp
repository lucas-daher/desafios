#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    int ret = v[0] / (N - 1);
    int curr;
    for (int i = 1; i < N; i++) {
        curr = v[i] / max(i - 0, (N - 1) - i);
        ret = min(curr, ret);
    }
    cout << ret << endl;
    return 0;
}