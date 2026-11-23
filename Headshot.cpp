#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    while (cin >> s) {
        int n = s.size();
        int zeros = 0;
        int zz = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                zeros++;
                if (s[(i + 1) % n] == '0') {
                    zz++;
                }
            }
        }

        long long shoot = 1LL * zz * n;
        long long rotate = 1LL * zeros * zeros;

        if (shoot > rotate) {
            cout << "SHOOT\n";
        } else if (shoot < rotate) {
            cout << "ROTATE\n";
        } else {
            cout << "EQUAL\n";
        }
    }
    return 0;
}
