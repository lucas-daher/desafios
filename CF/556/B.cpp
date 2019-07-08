#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> positions(int i, int j) {
    vector<pair<int, int>> ret;
    ret.push_back({i, j});
    ret.push_back({i + 1, j});
    ret.push_back({i + 1, j - 1});
    ret.push_back({i + 1, j + 1});
    ret.push_back({i + 2, j});
    return ret;
}

bool add(vector<vector<char>>& board, int i, int j) {
    if (j == 0 || j + 1 >= board.size()) return false;
    if (i + 2 >= board.size()) return false;
    auto pos = positions(i, j);
    for (auto it : pos) {
        if (board[it.first][it.second] == '#') return false;
        board[it.first][it.second] = '#';
    }
    return true;
}

bool complete(vector<vector<char>>& board, int i_0) {
    for (int i = i_0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[i][j] == '.') {
                if (add(board, i, j)) {
                    return complete(board, i);
                } else {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> board(n, vector<char>(n));
    string aux;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        for (int j = 0; j < n; j++) {
            board[i][j] = aux[j];
        }
    }
    if (complete(board, 0)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}