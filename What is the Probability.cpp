#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int s;
    cin >> s;
    cout << fixed << setprecision(4);

    while (s--) {
        int n, idx;
        double p;
        cin >> n >> p >> idx;

        if (p == 0.0) {
            cout << 0.0 << "\n";
        } else {
            double q = 1.0 - p;
            double ans = p * pow(q, idx - 1) / (1.0 - pow(q, n));
            cout << ans << "\n";
        }
    }

    return 0;
}
