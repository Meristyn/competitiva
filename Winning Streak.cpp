#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    double p;
    cout << fixed << setprecision(6);

    while (cin >> n >> p && n != 0) {
        vector<double> pw(n + 1, 1.0);
        for (int i = 1; i <= n; i++) {
            pw[i] = pw[i - 1] * p;
        }

        vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0.0));
        for (int j = 0; j <= n; j++) {
            for (int i = 0; i <= n; i++) {
                if (i <= j) {
                    dp[i][j] = 1.0;
                } else if (i == j + 1) {
                    dp[i][j] = 1.0 - pw[j + 1];
                } else {
                    dp[i][j] = dp[i - 1][j] - dp[i - j - 2][j] * (1.0 - p) * pw[j + 1];
                }
            }
        }

        double ans = 0.0;
        for (int j = 1; j <= n; j++) {
            ans += j * (dp[n][j] - dp[n][j - 1]);
        }
        cout << ans << "\n";
    }

    return 0;
}
