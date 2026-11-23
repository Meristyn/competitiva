#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool kmpSearch(const string& text, const string& pat) {
    int n = text.size();
    int m = pat.size();
    if (m > n) return false;

    vector<int> pi(m, 0);
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && pat[i] != pat[j]) j = pi[j - 1];
        if (pat[i] == pat[j]) j++;
        pi[i] = j;
    }

    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && text[i] != pat[j]) j = pi[j - 1];
        if (text[i] == pat[j]) j++;
        if (j == m) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string rev = s;
        reverse(rev.begin(), rev.end());

        int n = s.size();
        bool isAlindrome = false;
        if (n >= 2) {
            string doubled = s + s;
            string mid = doubled.substr(1, 2 * n - 2);
            if (kmpSearch(mid, rev)) {
                isAlindrome = true;
            }
        }

        if (isAlindrome) {
            cout << "alindrome\n";
        } else if (s == rev) {
            cout << "palindrome\n";
        } else {
            cout << "simple\n";
        }
    }

    return 0;
}
