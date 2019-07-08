#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ones = 0, twos = 0, aux;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        if (aux == 1) ones++;
        else twos++;
    }
    vector<int> ret;
    if (twos > 0) {
        ret.push_back(2);
        twos--;
    }
    if (ones > 0) {
        ret.push_back(1);
        ones--;
    }
    while (twos > 0) {
        ret.push_back(2);
        twos--;
    }
    while (ones > 0) {
        ret.push_back(1);
        ones--;
    }
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }
    cout << endl;
    return 0;
}