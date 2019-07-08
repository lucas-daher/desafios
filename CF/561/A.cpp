#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> names(26, 0);
    string name;
    for (int i = 0; i < n; i++) {
        cin >> name;
        names[name[0] - 'a']++;
    }
    int ret = 0;
    for (int i = 0; i < 26; i++) {
        int aux = (names[i] / 2);
        ret += aux * (aux - 1)/2;
        aux += names[i] % 2;
        ret += aux * (aux - 1)/2;
    }
    cout << ret << endl;
    return 0;
}
