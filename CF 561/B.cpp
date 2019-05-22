#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long a = 5, b = -1;
    while (a < n && n % a != 0) {
        a++;
    }
    b = n / a;
    if (a >= n || b < 5) {
        cout << -1 << endl;
        return 0;
    }
    string ret = "";
    for (int i = 0; i < n; i++) {
        ret += 'a';
    }
    vector<char> vowels = {'e', 'i', 'o', 'u'};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < a; j++) {
            ret[j * b + ((i + j) % 5)] = vowels[i];
        }
    }
    for (int i = 5; i < b; i++) {
        for (int j = 0; j < 4; j++) {
            ret[j * b + i] = vowels[j];
        }
    }
    cout << ret << endl;
    return 0;
}