#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, mini;
    cin >> N;
    vector<char> operations(N);
    for (int i = 0; i < N; i++) {
        cin >> operations[i];
    }
    vector<int> stones(N);
    if (operations[0] == '-') {
        stones[0] = -1;
    } else {
        stones[0] = 1;
    }
    mini = stones[0];
    for (int i = 1; i < N; i++) {
        stones[i] = stones[i - 1];
        if (operations[i] == '-') {
            stones[i]--;
        } else {
            stones[i]++;
        }
        mini = min(mini, stones[i]);
    }
    mini < 0 ? cout << stones[N - 1] - mini : cout << stones[N - 1];
    cout << endl;
    return 0;
}
