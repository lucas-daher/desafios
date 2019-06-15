#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> hand(n), deck(n);
    for (ll i = 0; i < n; i++) {
        cin >> hand[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> deck[i];
    }
    vector<pair<ll, ll>> sort(n + 1);
    for (ll i = 0; i < n; i++) {
        if (hand[i] != 0) {
            sort[hand[i]].first = -1;
            sort[hand[i]].second = n + 1 - hand[i];
        }
        if (deck[i] != 0) {
            if (i + 1 >= deck[i]) {
                sort[deck[i]].first = i + 1 - deck[i];
            } else {
                sort[deck[i]].first = -1;
            }
            sort[deck[i]].second = i + n + 2 - deck[i];
        }
    }
    pair<ll, ll> ret = sort[1];
    for (ll i = 2; i <= n; i++) {
        ret.second = max(ret.second, sort[i].second);
        if (ret.first != -1) {
            if (sort[i].first != ret.first && sort[i].second > ret.first) {
                ret.first = -1;
            }
        }
        if (sort[i].second >= ret.second) {
            ret.second = sort[i].second;
        }    }
    cout << (ret.first == -1 ? ret.second : ret.first) << "\n";
    return 0;
}