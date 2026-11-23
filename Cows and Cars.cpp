#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double ncows, ncars, nshow;
    cout << fixed << setprecision(5);

    while (cin >> ncows >> ncars >> nshow) {
        double total = ncows + ncars;
        double ans = (ncars * (total - 1.0)) / (total * (total - nshow - 1.0));
        cout << ans << "\n";
    }

    return 0;
}
