#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

const int BASE = 1000000000;

vector<int> add(const vector<int>& a, const vector<int>& b) {
    vector<int> c;
    int n = max(a.size(), b.size());
    int carry = 0;
    for (int i = 0; i < n || carry; i++) {
        long long sum = carry;
        if (i < (int)a.size()) sum += a[i];
        if (i < (int)b.size()) sum += b[i];
        c.push_back(sum % BASE);
        carry = sum / BASE;
    }
    return c;
}

void printBig(const vector<int>& a) {
    cout << a.back();
    for (int i = (int)a.size() - 2; i >= 0; i--) {
        cout << setfill('0') << setw(9) << a[i];
    }
    cout << "\n";
}

int main() {
    vector<vector<int>> fib(1001);
    fib[0] = {1};
    fib[1] = {2};
    for (int i = 2; i <= 1000; i++) {
        fib[i] = add(fib[i - 1], fib[i - 2]);
    }

    int n;
    while (cin >> n) {
        printBig(fib[n]);
    }

    return 0;
}
