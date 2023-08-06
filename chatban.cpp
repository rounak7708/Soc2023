#include <bits/stdc++.h>
using namespace std;

/*

k = 4

e -> 1
e e
e e e
e e e e -> k
e e e -> (k + 1: from top) or (k - 1: from bottom)
e e
e -> 2k - 1

------------------------------------------

k = 3
e
e e
e e e
e e
e

*/

long long get(int x) {
    return x * 1LL * (x + 1) / 2;
}

void test_case() {
    int k;
    long long x;
    cin >> k >> x;
    long long low = 1, high = 2 * k - 1;
    long long ans = high;
    bool checker = false;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (mid >= k) {
            checker = (get(k) + get(k - 1) - get(2 * k - 1 - mid) >= x);
        } else {
            checker = (get(mid) >= x);
        }
        if (checker) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        test_case();
    }
}