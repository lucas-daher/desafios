#include <bits/stdc++.h>
using namespace std;

int main() {
    long long B, G;
    cin >> B >> G;
    vector<long long> vB(B), vG(G);
    for (int i = 0; i < B; i++) {
        cin >> vB[i];
    }
    for (int i = 0; i < G; i++) {
        cin >> vG[i];
    }
    sort(vB.begin(), vB.end());
    sort(vG.begin(), vG.end());
    if (vB[B - 1] > vG[0]) {
        cout << -1 << endl;
        return 0;
    }
    long long ret = 0;
    for (int i = 0; i < B; i++) {
        ret += vB[i] * G;
    }
    int currB = B - 1, dist = 0;
    for (int i = G - 1; i >= 0 && vG[i] > vB[B - 1]; i--) {
        if (dist == G - 1) {
            currB--;
            dist = 0;
        }
        if (currB == -1) {
            cout << -1 << endl;
            return 0;
        }
        ret += (vG[i] - vB[currB]);
        dist++;
    }
    cout << ret << endl;
    return 0;
}