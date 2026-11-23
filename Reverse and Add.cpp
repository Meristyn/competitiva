#include <iostream>

using namespace std;

unsigned long long reverseNum(unsigned long long n) {
    unsigned long long r = 0;
    while (n > 0) {
        r = r * 10 + n % 10;
        n /= 10;
    }
    return r;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        unsigned long long n;
        cin >> n;
        int steps = 0;
        do {
            n += reverseNum(n);
            steps++;
        } while (n != reverseNum(n));
        cout << steps << " " << n << "\n";
    }
    return 0;
}
