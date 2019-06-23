#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll find(vector<ll>& v, ll pos, ll next) {
    if (pos == 0 || pos == v.size()) return -1;
    if (v[pos] == 0) return find(v, pos + next, next);
    return pos;
}

vector<ll> calc_sum(const vector<ll>& v, ll sp) {
    ll sz = max(sp, v.size() - sp) + 1;
    vector<ll> ret(sz, 0);
    for (ll j = v.size() - 1, i = 0; j >= sp; j--, i++) {
        ret[i] += v[j];
    }
    for (ll j = sp - 1, i = 0; j >= 0; j--, i++) {
        ret[i] += v[j];
        if (ret[i] >= 10) {
            ret[i] %= 10;
            ret[i + 1]++;
        }
    }
    if (ret[ret.size() - 1] == 0) ret.pop_back();
    reverse(ret.begin(), ret.end());
    return move(ret);
}

vector<ll> find_min(vector<ll> l, vector<ll> r) {
    if (l.size() < r.size()) return move(l);
    if (l.size() > r.size()) return move(r);
    for (ll i = 0; i < l.size(); i++) {
        if (l[i] < r[i]) return move(l);
        if (l[i] > r[i]) return move(r);
    }
    return move(l);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll s;
    cin >> s;
    vector<ll> num(s), ret;
    char aux;
    for (ll i = 0; i < s; i++) {
        cin >> aux;
        num[i] = aux - '0';
    }
    ll cand1, cand2;
    cand1 = find(num, s/2, -1);
    cand2 = find(num, (s + 1)/2, 1);
    if (cand1 == -1) {
        ret = calc_sum(num, cand2);
    } else if (cand2 == -1){
        ret = calc_sum(num, cand1);
    }
    else if (cand1 == cand2) {
        ret = calc_sum(num, cand1);
    } else if (cand1 < s - cand2) {
        ret = calc_sum(num, cand2);
    } else if (cand1 > s - cand2) {
        ret = calc_sum(num, cand1);
    } else {
        ret = find_min(calc_sum(num, cand1), calc_sum(num, cand2));
    }
    for (ll i = 0; i < ret.size(); i++) {
        cout << ret[i];
    }
    cout << "\n";
    return 0;
}