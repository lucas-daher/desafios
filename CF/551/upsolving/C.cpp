#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calc_max(string& s) {
    ll ret = s.size()/2;
    for (ll i = 0; i < s.size(); i++) {
        if (s[i] == '(') ret--;
    }
    return ret;
}

ll open_max;
ll man_open;

string rec(string& s, ll pos, ll open, ll close) {
    if (pos == s.size()) {
        return open == close ? s : ":("; 
    }
    if (open <= close && pos != 0) {
        return ":(";
    }
    if (s[pos] == '(') {
        return rec(s, pos + 1LL, open + 1LL, close);
    }
    if (s[pos] == ')') {
        return rec(s, pos + 1LL, open, close + 1LL);
    }
    if (man_open < open_max) {
        s[pos] = '(';
        man_open++;
        return rec(s, pos + 1, open + 1, close);
    }
    s[pos] = ')';
    return rec(s, pos + 1, open, close + 1);
}

int main() {
    ll n;
    cin >> n;
    string s = "";
    cin >> s;
    open_max = calc_max(s);
    string ret = rec(s, 0, 0, 0);
    cout << ret << endl;
    return 0;
}
