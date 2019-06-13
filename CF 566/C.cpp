#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll num_v(string s) {
    ll ret = 0;
    for (ll i = 0; i < s.size(); i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') ret++;
    }
    return ret;
}

ll last_v(string s) {
    for (ll i = s.size() - 1;; --i) {
        if (s[i] == 'a') return 0;
        if (s[i] == 'e') return 1;
        if (s[i] == 'i') return 2;
        if (s[i] == 'o') return 3;
        if (s[i] == 'u') return 4;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    unordered_map<ll, vector<string>> mp;
    string s;
    vector<pair<string, string>> fp, sp;
    for (ll i = 0; i < n; i++) {
        cin >> s;
        ll vowels = num_v(s);
        ll last = last_v(s);
        if (mp.find(vowels) == mp.end()) {
            mp[vowels] = vector<string>(5, " ");
        }
        if (mp[vowels][last] == " ") {
            mp[vowels][last] = s;
        } else {
            sp.push_back({s, mp[vowels][last]});
            mp[vowels][last] = " ";
        }
    }
    for (auto it : mp) {
        string poss = " ";
        for (string s : it.second) {
            if (s != " ") {
                if (poss == " ") {
                    poss = s;
                } else {
                    fp.push_back({poss, s});
                    poss = " ";
                }
            }
        }
    }
    while (sp.size() > fp.size()) {
        fp.push_back(sp[sp.size() - 1]);
        sp.pop_back();
    }
    cout << sp.size() << "\n";
    for (ll i = 0; i < sp.size(); i++) {
        cout << fp[i].first << " " << sp[i].first << "\n";
        cout << fp[i].second << " " << sp[i].second << "\n";
    }
    return 0;
}