#include <iostream>
#include <string>

using namespace std;

int readBit() {
    char c;
    while (cin.get(c)) {
        if (c == '0' || c == '1') {
            return c - '0';
        }
    }
    return -1;
}

int readInt(int len) {
    int val = 0;
    for (int i = 0; i < len; i++) {
        val = val * 2 + readBit();
    }
    return val;
}

int main() {
    string header;
    while (getline(cin, header)) {
        if (!header.empty() && header.back() == '\r') {
            header.pop_back();
        }
        if (header.empty()) continue;

        char code[8][128];
        int idx = 0;
        for (int len = 1; len <= 7 && idx < (int)header.size(); len++) {
            for (int v = 0; v < (1 << len) - 1 && idx < (int)header.size(); v++) {
                code[len][v] = header[idx++];
            }
        }

        while (true) {
            int len = readInt(3);
            if (len == 0) break;
            while (true) {
                int v = readInt(len);
                if (v == (1 << len) - 1) break;
                cout << code[len][v];
            }
        }
        cout << "\n";
    }
    return 0;
}
