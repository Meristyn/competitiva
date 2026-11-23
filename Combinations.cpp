#include <iostream>
#include <algorithm>

using namespace std;

long long gcdLL(long long a, long long b) {
    while (b != 0) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

long long comb(int n, int m) {
    int k = min(m, n - m);
    long long res = 1;
    for (int i = 1; i <= k; i++) {
        long long num = n - k + i;
        long long den = i;
        long long g = gcdLL(num, den);
        num /= g;
        den /= g;
        g = gcdLL(res, den);
        res /= g;
        den /= g;
        res *= num;
    }
    return res;
}

int main() {
    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        cout << n << " things taken " << m << " at a time is " << comb(n, m) << " exactly.\n";
    }
    return 0;
}
