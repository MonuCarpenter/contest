#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int min_frequency = n;  // Initialize with the maximum possible value

    // Iterate over all divisors of n
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            // i is a divisor
            int d1 = i;
            int d2 = n / i;

            // Case when A2 = d1
            if (n % (d1 * d1) == 0) {
                min_frequency = min(min_frequency, n / (d1 * d1));
            }

            // Case when A2 = d2
            if (n % (d2 * d2) == 0) {
                min_frequency = min(min_frequency, n / (d2 * d2));
            }
        }
    }

    cout << min_frequency << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
