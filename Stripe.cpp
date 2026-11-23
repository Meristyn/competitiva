#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

const int BASE = 1000000000;

void mulInt(vector<int>& a, int x) {
    long long carry = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        long long cur = 1LL * a[i] * x + carry;
        a[i] = cur % BASE;
        carry = cur / BASE;
    }
    while (carry > 0) {
        a.push_back(carry % BASE);
        carry /= BASE;
    }
}

void divInt(vector<int>& a, int x) {
    long long rem = 0;
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        long long cur = rem * BASE + a[i];
        a[i] = cur / x;
        rem = cur % x;
    }
    while (a.size() > 1 && a.back() == 0) {
        a.pop_back();
    }
}

void printBig(const vector<int>& a) {
    cout << a.back();
    for (int i = (int)a.size() - 2; i >= 0; i--) {
        cout << setfill('0') << setw(9) << a[i];
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int sum = 0;
        for (int i = 0; i < k; i++) {
            int len;
            cin >> len;
            sum += len;
        }

        int white = n - sum;
        int m = white + 1;
        if (white < 0 || k > m) {
            cout << "0\n";
            continue;
        }

        int r = min(k, m - k);
        vector<int> ans(1, 1);
        for (int i = 1; i <= r; i++) {
            mulInt(ans, m - r + i);
            divInt(ans, i);
        }
        printBig(ans);
    }
    return 0;
}
