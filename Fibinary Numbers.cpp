#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string a, b;
    bool first = true;

    while (cin >> a >> b) {
        if (!first) cout << "\n";
        first = false;

        int len = max(a.size(), b.size()) + 15;
        vector<int> d(len, 0);

        for (int i = 0; i < (int)a.size(); i++) {
            d[i] += a[a.size() - 1 - i] - '0';
        }
        for (int i = 0; i < (int)b.size(); i++) {
            d[i] += b[b.size() - 1 - i] - '0';
        }

        bool changed = true;
        while (changed) {
            changed = false;
            for (int i = 0; i < len - 2; i++) {
                if (d[i] >= 1 && d[i + 1] >= 1) {
                    d[i]--;
                    d[i + 1]--;
                    d[i + 2]++;
                    changed = true;
                }
            }
            for (int i = 0; i < len - 2; i++) {
                if (d[i] >= 2) {
                    d[i] -= 2;
                    d[i + 1]++;
                    if (i == 1) {
                        d[0]++;
                    } else if (i >= 2) {
                        d[i - 2]++;
                    }
                    changed = true;
                }
            }
        }

        int top = len - 1;
        while (top > 0 && d[top] == 0) top--;
        for (int i = top; i >= 0; i--) {
            cout << d[i];
        }
        cout << "\n";
    }

    return 0;
}
