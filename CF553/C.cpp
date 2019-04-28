#include <bits/stdc++.h>
using namespace std;

int bits_par(long long i) {
    int first_bit = 60;
    while (i >> first_bit == 0) --first_bit;
    return (first_bit + 1) % 2;
}

long long translate(long long i) {
    int first_bit = 60;
    while (i >> first_bit == 0) --first_bit;
    ++first_bit;
    long long ret = - (first_bit % 2), aux = i;
    first_bit -= 2;
    while (first_bit >= 0) {
        aux -= (pow(2, first_bit + 1) - 1);
        aux += pow(2, first_bit) - 1;
        first_bit -= 2;
    }
    ret += 2 * aux;
    ret %= 1000000007;
    return ret;
}

long long calc(long long i, long long& odd, long long& even) {
    if (bits_par(i) == 0) {
        if (even == -1) {
            even = translate(i);
        } else {
            even += 2;
            even %= 1000000007;
        }
        return even;
    } else {
        if (odd == -1) {
            odd = translate(i);
        } else {
            odd += 2;
            odd %= 1000000007;
        }
        return odd;
    }
}

int main() {
    long long l, r, ret = 0;
    cin >> l >> r;
    long long odd = -1, even = -1;
    for (long long i = l; i <= r; i++) {
        ret += calc(i, odd, even);
        ret %= 1000000007;
    }
    cout << ret << endl;
    return 0;
}
