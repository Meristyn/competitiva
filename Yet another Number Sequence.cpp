#include <iostream>

using namespace std;

struct Mat {
    int a[2][2];
};

Mat mul(const Mat& x, const Mat& y, int mod) {
    Mat r;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            long long s = 0;
            for (int k = 0; k < 2; k++) {
                s += 1LL * x.a[i][k] * y.a[k][j];
            }
            r.a[i][j] = s % mod;
        }
    }
    return r;
}

Mat power(Mat base, long long exp, int mod) {
    Mat res = {{{1 % mod, 0}, {0, 1 % mod}}};
    while (exp > 0) {
        if (exp & 1) res = mul(res, base, mod);
        base = mul(base, base, mod);
        exp >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int a, b, m;
        long long n;
        cin >> a >> b >> n >> m;

        int mod = 1;
        for (int i = 0; i < m; i++) mod *= 10;

        if (n == 0) {
            cout << a % mod << "\n";
        } else if (n == 1) {
            cout << b % mod << "\n";
        } else {
            Mat base = {{{1, 1}, {1, 0}}};
            Mat p = power(base, n - 1, mod);
            long long ans = (1LL * p.a[0][0] * b + 1LL * p.a[0][1] * a) % mod;
            cout << ans << "\n";
        }
    }

    return 0;
}
