//#define _GLIBCXX_DEBUG
#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <cmath>
#include <stdio.h>
#include <strstream>
#include <unordered_map>
#include <unordered_set>

#define int long long
#define len(x) x.size()
#define all(x) x.begin(), x.end()
#define ld long double

using namespace std;

bool fn(int j, int i, vector<int>& arr) {
    for (int k = 0; k < j; ++k) {
        int curr = arr[k];
        if (curr == i || abs(k - j) == abs(curr - i)) {
            return false;
        }
    }
    return true;
}

int recur_fn(int n, int r, vector<int>& arr) {
    if (r == n) {
        return 1;
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (fn(r, i, arr)) {
            arr[r] = i;
            count += recur_fn(n, r + 1, arr);
            arr[r] = -1;
        }
    }
    return count;
}

int32_t main() {
    int n;
    cin >> n;
    vector<int> arr(n, -1);
    int ans = recur_fn(n, 0, arr);
    cout << ans;
}
