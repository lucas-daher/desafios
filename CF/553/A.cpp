#include <bits/stdc++.h>
using namespace std;

int dist(char i, char j) {
    int x = max(i - 'A', j - 'A'), y = min(i - 'A', j - 'A');
    
    return min(x - y, (25 - x) + y + 1);
}

int main() {
    int N, aux, ret = 1000;
    cin >> N;
    string s, gen = "ACTG";
    cin >> s;
    for (int i = 0; i < N - 3; i++) {
        aux = dist(s[i], gen[0]) + dist(s[i + 1], gen[1]) + dist(s[i + 2], gen[2]) + dist(s[i + 3], gen[3]);
        ret = min(ret, aux);
    }
    cout << ret << endl;
    return 0;
}
