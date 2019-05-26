#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll leafs = 0;

void calc(ll pos, unordered_map<ll, vector<ll>>& kids, vector<ll>& parents, vector<int>& nodes, vector<ll>& ord) {
    if (ord[pos] != -1) return;
    if (kids.find(pos) == kids.end()) {
        leafs++;
        ord[pos] = 1;
        return;
    }
    if (nodes[pos] == 1) {
        ll ret = -1;
        for (auto it : kids[pos]) {
            calc(it, kids, parents, nodes, ord);
            if (ret == -1 || ret > ord[it]) {
                ret = ord[it];
            }
        }
        ord[pos] = ret;
    } else {
        ll ret = 0;
        for (auto it : kids[pos]) {
            calc(it, kids, parents, nodes, ord);
            ret += ord[it];
        }
        ord[pos] = ret;
    }
}

int main() {
    ll n, aux;
    cin >> n;
    vector<int> nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> aux;
        nodes[i] = aux;
    }
    vector<ll> parents(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> aux;
        parents[i] = aux - 1;
    }
    unordered_map<ll, vector<ll>> kids;
    for (ll i = 0; i < parents.size(); i++) {
        kids[parents[i]].push_back(i + 1);
    }
    vector<ll> ord(n, -1);
    calc(0, kids, parents, nodes, ord);
    
    /*cout << endl;
    for (ll i = 0; i < ord.size(); i++) {
        cout << ord[i] << " ";
    }
    cout << endl << endl;*/
    
    ll ret = leafs + 1 - ord[0];
    cout << ret << endl;
    return 0;
}