#include <iostream>
#include <string>

using namespace std;

string removeSpaces(const string& s) {
    string res = "";
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] != ' ') res += s[i];
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    string dummy;
    getline(cin, dummy);

    for (int tc = 1; tc <= t; tc++) {
        string team, judge;
        getline(cin, team);
        getline(cin, judge);
        if (!team.empty() && team.back() == '\r') team.pop_back();
        if (!judge.empty() && judge.back() == '\r') judge.pop_back();

        cout << "Case " << tc << ": ";
        if (team == judge) {
            cout << "Yes\n";
        } else if (removeSpaces(team) == removeSpaces(judge)) {
            cout << "Output Format Error\n";
        } else {
            cout << "Wrong Answer\n";
        }
    }
    return 0;
}
