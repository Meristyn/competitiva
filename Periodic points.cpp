#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> Matrix;

Matrix mul(const Matrix& A, const Matrix& B, int mod) {
    int m = A.size();
    Matrix C(m, vector<int>(m, 0));
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < m; k++) {
            if (A[i][k] == 0) continue;
            long long aik = A[i][k];
            for (int j = 0; j < m; j++) {
                C[i][j] = (C[i][j] + aik * B[k][j]) % mod;
            }
        }
    }
    return C;
}

Matrix power(Matrix A, int n, int mod) {
    int m = A.size();
    Matrix R(m, vector<int>(m, 0));
    for (int i = 0; i < m; i++) R[i][i] = 1 % mod;
    while (n > 0) {
        if (n & 1) R = mul(R, A, mod);
        A = mul(A, A, mod);
        n >>= 1;
    }
    return R;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    while (cin >> m && m != 0) {
        vector<int> f(m + 1);
        for (int i = 0; i <= m; i++) {
            cin >> f[i];
        }
        int n, mod;
        cin >> n >> mod;

        bool inf = false;
        for (int i = 0; i < m; i++) {
            int cur = i;
            int sgn = 1;
            bool ok = true;
            for (int step = 0; step < n; step++) {
                int diff = f[cur + 1] - f[cur];
                if (abs(diff) != 1) {
                    ok = false;
                    break;
                }
                if (diff == 1) {
                    cur = f[cur];
                } else {
                    cur = f[cur] - 1;
                    sgn = -sgn;
                }
            }
            if (ok && cur == i && sgn == 1) {
                inf = true;
                break;
            }
        }

        if (inf) {
            cout << "Infinity\n";
            continue;
        }

        Matrix A(m, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            int lo = min(f[i], f[i + 1]);
            int hi = max(f[i], f[i + 1]);
            for (int j = lo; j < hi; j++) {
                A[i][j] = 1;
            }
        }

        Matrix P = power(A, n, mod);
        long long ans = 0;
        for (int i = 0; i < m; i++) {
            ans = (ans + P[i][i]) % mod;
        }

        for (int p = 0; p <= m; p++) {
            int x = p;
            for (int step = 0; step < n; step++) {
                x = f[x];
            }
            if (x == p) ans++;

            if (p < m) {
                int pos = p, dir = 1;
                bool alive = true;
                for (int step = 0; step < n; step++) {
                    if (dir == 1) {
                        if (f[pos + 1] > f[pos]) {
                            pos = f[pos];
                            dir = 1;
                        } else if (f[pos + 1] < f[pos]) {
                            pos = f[pos];
                            dir = -1;
                        } else {
                            alive = false;
                            break;
                        }
                    } else {
                        if (f[pos - 1] < f[pos]) {
                            pos = f[pos];
                            dir = -1;
                        } else if (f[pos - 1] > f[pos]) {
                            pos = f[pos];
                            dir = 1;
                        } else {
                            alive = false;
                            break;
                        }
                    }
                }
                if (alive && pos == p && dir == 1) ans--;
            }

            if (p > 0) {
                int pos = p, dir = -1;
                bool alive = true;
                for (int step = 0; step < n; step++) {
                    if (dir == 1) {
                        if (f[pos + 1] > f[pos]) {
                            pos = f[pos];
                            dir = 1;
                        } else if (f[pos + 1] < f[pos]) {
                            pos = f[pos];
                            dir = -1;
                        } else {
                            alive = false;
                            break;
                        }
                    } else {
                        if (f[pos - 1] < f[pos]) {
                            pos = f[pos];
                            dir = -1;
                        } else if (f[pos - 1] > f[pos]) {
                            pos = f[pos];
                            dir = 1;
                        } else {
                            alive = false;
                            break;
                        }
                    }
                }
                if (alive && pos == p && dir == -1) ans--;
            }
        }

        ans = (ans % mod + mod) % mod;
        cout << ans << "\n";
    }

    return 0;
}
