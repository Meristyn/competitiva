#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        int words = 0;
        bool inWord = false;
        for (int i = 0; i < (int)line.size(); i++) {
            if (isalpha((unsigned char)line[i])) {
                if (!inWord) {
                    words++;
                    inWord = true;
                }
            } else {
                inWord = false;
            }
        }
        cout << words << "\n";
    }
    return 0;
}
