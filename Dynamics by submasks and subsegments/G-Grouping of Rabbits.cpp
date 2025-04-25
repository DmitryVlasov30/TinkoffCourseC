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
#include <random>
#include <deque>

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define int long long
//#define len(x) x.size()
#define all(x) x.begin(), x.end()
#define ld long double
#define fir first
#define sec second
#define emp emplace_back
#define ins insert

using namespace std;

const int mod = 1e9 + 7;
const int inf = 1e18;
const int maxn = 1e5;
const int logn = 20;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<vector<int>> arr(n, vector<int> (n, 0));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> arr[i][j];
        }
    }

    vector<int> dp(1 << n, 0);
    for (int mask = 1; mask < (1 << n); ++mask){
        for (int i = 0; i < n; ++i){
            if (mask & (1 << i)){
                for (int j = i + 1; j < n; ++j){
                    if (mask & (1 << j)) dp[mask] += arr[i][j];
                }
            }
        }

        for (int submask = mask; submask; submask = (submask - 1) & mask){
            dp[mask] = max(dp[mask], dp[submask] + dp[mask ^ submask]);
        }
    }

    cout << dp[(1 << n) - 1];
}