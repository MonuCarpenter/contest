/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 2024-09-08 12:26:58
 * Problem: 1969/b
 **/

#include <iostream>
#include <string>
#include <vector>
/**
 *  Learning of the day
 *  `long long` and `int64_t` are both integer data types designed to hold large whole numbers. However, there's a subtle difference in their origin and guarantees:

 * **`long long`:**
    * It's a fundamental data type introduced in the C++ standard (C++11).
    * Its size is guaranteed to be *at least* 64 bits, but the exact size can vary depending on the compiler and platform.
    * It's generally considered the preferred way to represent 64-bit integers in C++.

 * **`int64_t`:**
    * It's defined in the `<cstdint>` header (which is part of the C standard and included in C++).
    * It's a typedef (an alias) for a specific integer type that is *exactly* 64 bits wide.
    * Its availability is tied to the `<cstdint>` header, which might not be available on very old or unusual platforms.

**In summary:**

* For most practical purposes, you can treat `long long` and `int64_t` as interchangeable when you need a 64-bit integer in C++.
* `long long` is generally preferred due to its being a built-in type and its wider availability.
* If you absolutely need to guarantee that the integer is exactly 64 bits wide across different platforms, you can use `int64_t`.
 */
using namespace std;
void solve() {
    string s;
    cin >> s;

    long long result = 0;
    long long prevOne = 0;
    for (char ch : s) {
        if (ch == '0') {
            result += prevOne ? prevOne + 1 : 0;
        } else {
            prevOne++;
        }
    }

    std::cout << result << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}