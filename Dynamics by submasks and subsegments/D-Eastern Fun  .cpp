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
    vector<int> arr, pref(n+1, 0);
    for (int i = 0; i < n; ++i){
        int el; cin >> el; arr.emp(el);
    }

    for (int i = 0; i < n; ++i)
        pref[i+1] = pref[i] + arr[i];

    vector<vector<int>> dp(n, vector<int>(n, 0));
    int ans = 0;
    for (int i = 0; i < n; ++i){
        dp[i][i] = 1; ans = max(ans, arr[i]);
    }

    for (int len = 2; len <= n; ++len){
        for (int l = 0; l + len <= n; ++l){
            int r = l + len - 1;
            int left = l, right = r;
            while (left < right){
                int sum_l = pref[left + 1] - pref[l], sum_r = pref[r + 1] - pref[right];
                if (sum_l == sum_r){
                    if ((left == right - 1 || dp[left+1][right-1]) && dp[l][left] && dp[right][r]){
                        dp[l][r] = 1; break;
                    }
                    ++left;
                    --right;
                } else if (sum_l < sum_r){
                    ++left;
                } else {
                    --right;
                }
            }
            if (dp[l][r]){
                ans = max(ans, pref[r + 1] - pref[l]);
            }
        }
    }

    cout << ans;
}