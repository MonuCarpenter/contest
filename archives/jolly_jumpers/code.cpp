/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 08:50 PM IST
 * Problem: <problem-name>
 */

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

class Solution {
   public:
    bool isJolly(int n) {
        int arr[n];

        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            arr[i] = x;
        }

        int start = 1;

        for (int i = 0; i < n - 1; i++) {
            arr[i] = std::abs(arr[i] - arr[i + 1]);
        }
        std::sort(arr, arr + n - 1);

        for (int i = 1; i < n; i++) {
            if (i != arr[i - 1]) return false;
        }
        return true;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution sol;

    int n;
    while (std::cin >> n) {
        bool result = sol.isJolly(n);
        std::cout << (result ? "Jolly" : "Not jolly") << std::endl;
    }
    return 0;
}
