#include <bits/stdc++.h>
using namespace std;

int find(long n) {
    int bit = 20;
    while (n >> bit == 0) bit--;
    while ((n >> bit) % 2 == 1 && bit >= 0) bit--;
    return bit;
}

int main() {
    long n, zero, q = 0, aux;
    cin >> n;
    vector<long> ret;
    zero = find(n);
    while (zero != -1) {
        aux = pow(2, zero + 1) - 1;
        n = n ^ aux;
        ret.push_back(zero + 1);
        q++;
        if (find(n) == -1) {
            cout << q << endl;
            for (int i = 0; i < ret.size(); i++) {
                cout << ret[i] << " ";
            }
            if (ret.size() > 0) cout << endl;
            return 0;
        }
        n++;
        q++;
        zero = find(n);
    }
    cout << q << endl;
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }
    if (ret.size() > 0) cout << endl;
    return 0;
}