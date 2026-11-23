#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;

string normalize(string s) {
    for (int i = 0; i < (int)s.size(); i++) {
        s[i] = tolower((unsigned char)s[i]);
    }
    sort(s.begin(), s.end());
    return s;
}

int main() {
    vector<string> words;
    map<string, int> freq;
    string w;

    while (cin >> w && w != "#") {
        words.push_back(w);
        freq[normalize(w)]++;
    }

    vector<string> ans;
    for (int i = 0; i < (int)words.size(); i++) {
        if (freq[normalize(words[i])] == 1) {
            ans.push_back(words[i]);
        }
    }

    sort(ans.begin(), ans.end());
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}
