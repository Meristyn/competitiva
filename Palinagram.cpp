#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    while (cin >> s && s != "#") {
        int cnt[26] = {0};
        for (int i = 0; i < (int)s.size(); i++) {
            cnt[s[i] - 'a']++;
        }

        vector<char> odds;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 != 0) {
                odds.push_back('a' + i);
            }
        }

        string ans = "";
        if ((int)odds.size() > 1) {
            for (int i = 0; i < (int)odds.size() - 1; i++) {
                ans += odds[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
