#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, c, q, aux;
    cin >> n >> c >> q;
    vector<pair<ll, ll>> qs(q), host(c);
    for (ll i = 0; i < c; ++i) {
        host[i].first = 0;
        host[i].second = i + 1;
    }
    for (ll i = 0; i < n; ++i) {
        cin >> aux;
        ++(host[aux - 1].first);
    }
    for (ll i = 0; i < q; ++i) {
        cin >> aux;
        qs[i].first = aux;
        qs[i].second = i;
    }
    sort(host.begin(), host.end());
    sort(qs.begin(), qs.end(), [](const pair<ll, ll>& lhs, const pair<ll, ll>& rhs)->bool {return lhs.first < rhs.first;});
    set<ll> update;
    for (ll i = 0; i < c && host[i].first == host[0].first; ++i) {
        update.insert(host[i].second);
    }
    ll next_q = 0;
    aux = update.size();
    while (next_q < q) {
        if (aux < c) {
            
            //cout << "cp aux = " << aux << "n = " << n << endl;
            
            auto beg = update.begin();
            ll curr = n + 1, dif;
            while (next_q < q && qs[next_q].first <= n + aux) {
                dif = qs[next_q].first - curr;
                advance(beg, dif);
                curr = qs[next_q].first;
                qs[next_q].first = *beg;
                ++next_q;
            }
            /*
            if (qs[next_q].first <= n + aux) {
                ll i = 1;
                for (auto el : update) {
                    while (qs[next_q].first == n + i) {
                    
                        //cout << qs[next_q].first << " " << el << " f1\n";
                    
                        qs[next_q].first = el;
                        ++next_q;
                    }
                    ++i;
                }
            }
            */
            ++(host[aux - 1].first);
            n += aux;
            while (aux < c && host[aux].first == host[aux - 1].first) {
                update.insert(host[aux].second);
                aux++;
            }
        } else {
            while (next_q < q) {
            
                //cout << qs[next_q].first;
                
                qs[next_q].first = ((qs[next_q].first - n) % c);
                if (qs[next_q].first == 0) qs[next_q].first = c;
                
                //cout << " " << qs[next_q].first << " f2\n";
                
                next_q++;
            }
        }
    }
    sort(qs.begin(), qs.end(), [](const pair<ll, ll>& lhs, const pair<ll, ll>& rhs)->bool {return lhs.second < rhs.second;});
    for (ll i = 0; i < q; ++i) {
        cout << qs[i].first << '\n';
    }
    return 0;
}


/*
100 99 4
89 96 26 16 28 26 96 14 46 92 76 66 93 65 45 7 89 6 95 53 34 59 15 75 8 25 20 99 41 90 51 14 94 23 68 25 58 81 50 85 87 53 27 67 64 30 55 77 7 30 10 32 38 1 67 94 44 16 49 38 63 76 81 47 55 92 67 25 61 96 2 52 33 69 4 64 24 29 88 70 45 76 83 79 22 87 5 62 11 30 17 82 77 48 73 88 96 35 96 82
106
198
109
190
*/