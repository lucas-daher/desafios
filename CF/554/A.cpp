#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> n_vec(N), m_vec(M);
    for (int i = 0; i < N; i++) {
        cin >> n_vec[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> m_vec[i];
    }
    pair<int, int> even, odd;
    even.first = even.second = odd.first = odd.second = 0;
    for (int i = 0; i < N; i++) {
        if (n_vec[i] % 2 == 0) {
            even.first++;
        } else {
            odd.first++;
        }
    }
    for (int i = 0; i < M; i++) {
        if (m_vec[i] % 2 == 0) {
            even.second++;
        } else {
            odd.second++;
        }
    }
    cout << min(even.first, odd.second) + min(even.second, odd.first) << endl;
    return 0;
}
