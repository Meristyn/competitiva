#include <iostream>
#include <string>

using namespace std;

long long countPaths() {
    long long paths = 1;
    string tok;
    while (cin >> tok) {
        if (tok == "IF") {
            long long leftPaths = countPaths();
            long long rightPaths = countPaths();
            paths *= (leftPaths + rightPaths);
        } else if (tok == "ELSE" || tok == "END_IF" || tok == "ENDPROGRAM") {
            return paths;
        }
    }
    return paths;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << countPaths() << "\n";
    }
    return 0;
}
