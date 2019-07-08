#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int ret = -1, time = -1;
    for (int i = 0; i < a; i++) {
        int x, y;
        cin >> x >> y;
        int curr = (max(b - x, 0)) / y;
        curr *= y;
        curr += x;
        while (curr < b) curr += y;
        if (time == -1 || curr < time) {
            ret = i + 1;
            time = curr;
        }
    }
    cout << ret << endl;
    return 0;
}
