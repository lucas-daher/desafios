#include <bits/stdc++.h>
using namespace std;
using ll = long long;

float dist(pair<float, float> p1, pair<float, float> p2) {
    float ret = 0;
    ret += pow((p2.first - p1.first), 2);
    ret += pow((p2.second - p1.second), 2);
    ret = sqrt(ret);
    return ret;
}

int main() {
    ll n;
    float r;
    cin >> n >> r;
    vector<pair<float, float>> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    float ret = 2 * 3.141592 * r;
    for (ll i = 0; i < n; i++) {
        ret += dist(v[i], v[(i + 1) % n]);
    }
    printf("%.2f\n", ret);
    return 0;
}
