#include <bits/stdc++.h>
using namespace std;

vector<int> complete(const vector<int>& b, const vector<int>& c, vector<int> used, unordered_map used_map) {
    int N = b.size();
    if (used.size() == 2 * b.size()) {
        vector<int> ret;
        for (int i = 0; i < used.size(); i+= 2) {
            if (used[i] < N - 1) {
                ret.push_back(b[i]);
            } else {
                ret.push_back(c(i - (N - 1)))
            }
        }
    }
    int last = used[used.size() - 1], next;
    if (last < b.size()) next = last + N - 1;
    else next = last - (N - 1);
    used.push_back(next);
    for (int i = 0; i < 2 * (N - 1); i++) {
        if (((i < N - 1 && b[i] == next) || (i >= N - 1 && c[i - (N - 1)] == next)) && used_map.find(i) == used_map.end()) {
            used_map.insert(i);
            used.push_back(i)
            auto ret = complete(b, c, used, used_map);
            if (ret.size() != 0) return ret;
            used_map.remove(i);
            used.pop_back();
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> b(N - 1), c(N - 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < N - 1; i++) {
        cin >> c[i];
    }
    bool found = false;
    int i;
    for (i = 0; i < 2 * (N - 1) && !found; i++) {
        int q = 1;
        int aux;
        if (j < N - 1) aux = b[j];
        else aux = c[j - (N - 1)];
        for (int j = i + 1; j < 2 * (N - 1); j++) {
            if (j < N - 1 && aux = b[j]) q++;
            else if (j >= N - 1 && aux = c[j - (N - 1)]) q++;
        }
        if (q % 2 == 1) found = true;
    }
    if (!found) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> used(1, i);
    vector<int> ret = complete(b, c, used);
    if (ret.size() > 0) {
        for (int j = 0; j < ret.size(); j++) cout << ret[j] << " ";
        cout << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
