#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

const int BASE = 1000000000;

struct BigInt {
    vector<int> d;

    BigInt(long long v = 0) {
        if (v == 0) {
            d.push_back(0);
        } else {
            while (v > 0) {
                d.push_back(v % BASE);
                v /= BASE;
            }
        }
    }
};

void trim(BigInt& a) {
    while (a.d.size() > 1 && a.d.back() == 0) {
        a.d.pop_back();
    }
}

BigInt add(const BigInt& a, const BigInt& b) {
    BigInt c;
    c.d.clear();
    int n = max(a.d.size(), b.d.size());
    int carry = 0;
    for (int i = 0; i < n || carry; i++) {
        long long sum = carry;
        if (i < (int)a.d.size()) sum += a.d[i];
        if (i < (int)b.d.size()) sum += b.d[i];
        c.d.push_back(sum % BASE);
        carry = sum / BASE;
    }
    trim(c);
    return c;
}

BigInt sub(const BigInt& a, const BigInt& b) {
    BigInt c = a;
    int borrow = 0;
    for (int i = 0; i < (int)c.d.size(); i++) {
        long long diff = c.d[i] - borrow - (i < (int)b.d.size() ? b.d[i] : 0);
        if (diff < 0) {
            diff += BASE;
            borrow = 1;
        } else {
            borrow = 0;
        }
        c.d[i] = diff;
    }
    trim(c);
    return c;
}

BigInt mulInt(const BigInt& a, int x) {
    BigInt c;
    c.d.clear();
    long long carry = 0;
    for (int i = 0; i < (int)a.d.size() || carry; i++) {
        long long cur = carry;
        if (i < (int)a.d.size()) cur += 1LL * a.d[i] * x;
        c.d.push_back(cur % BASE);
        carry = cur / BASE;
    }
    trim(c);
    return c;
}

void printBig(const BigInt& a) {
    cout << a.d.back();
    for (int i = (int)a.d.size() - 2; i >= 0; i--) {
        cout << setfill('0') << setw(9) << a.d[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int f, n, s;
    while (cin >> f >> n >> s) {
        BigInt total(1);
        for (int i = 0; i < n; i++) {
            total = mulInt(total, f);
        }

        if (s < n || s > f * n) {
            cout << "0/";
            printBig(total);
            cout << "\n";
            continue;
        }

        vector<BigInt> dp(s + 1, BigInt(0));
        dp[0] = BigInt(1);

        for (int i = 1; i <= n; i++) {
            vector<BigInt> ndp(s + 1, BigInt(0));
            BigInt win(0);
            for (int sum = 1; sum <= s; sum++) {
                win = add(win, dp[sum - 1]);
                if (sum - f - 1 >= 0) {
                    win = sub(win, dp[sum - f - 1]);
                }
                ndp[sum] = win;
            }
            dp.swap(ndp);
        }

        printBig(dp[s]);
        cout << "/";
        printBig(total);
        cout << "\n";
    }

    return 0;
}
