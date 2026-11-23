#include <iostream>
#include <string>
#include <set>
#include <sstream>

using namespace std;

int charToVal(char c) {
    if (c == ' ') return 0;
    return c - 'A' + 1;
}

char valToChar(int v) {
    if (v == 0) return ' ';
    return 'A' + v - 1;
}

int main() {
    set<string> dict;
    string w;
    while (cin >> w && w != "#") {
        dict.insert(w);
    }

    string cipher;
    getline(cin, cipher);
    getline(cin, cipher);
    if (!cipher.empty() && cipher.back() == '\r') {
        cipher.pop_back();
    }

    int bestScore = -1;
    string bestText = "";

    for (int k = 0; k < 27; k++) {
        string dec = cipher;
        for (int i = 0; i < (int)dec.size(); i++) {
            int v = charToVal(dec[i]);
            int nv = (v - k + 27) % 27;
            dec[i] = valToChar(nv);
        }

        stringstream ss(dec);
        string word;
        int score = 0;
        while (ss >> word) {
            if (dict.count(word)) score++;
        }

        if (score > bestScore) {
            bestScore = score;
            bestText = dec;
        }
    }

    stringstream ss(bestText);
    string word;
    int col = 0;
    while (ss >> word) {
        if (col == 0) {
            cout << word;
            col = word.size();
        } else if (col + 1 + (int)word.size() <= 60) {
            cout << " " << word;
            col += 1 + word.size();
        } else {
            cout << "\n" << word;
            col = word.size();
        }
    }
    cout << "\n";

    return 0;
}
