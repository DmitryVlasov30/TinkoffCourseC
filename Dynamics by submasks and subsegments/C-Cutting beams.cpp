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
#define len(x) x.size()
#define all(x) x.begin(), x.end()
#define ld long double
#define fir first
#define sec second
#define emp emplace_back
#define ins insert

using namespace std;

const int mod = 1e9 + 7;
const int inf = 1e18;
const int maxn = 20;
const int logn = 20;

struct Edge {
    int a, b, w;
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int length, n; cin >> length >> n;
    vector<int> arr;
    for (int i = 0; i < n; ++i){
        int el; cin >> el; arr.emp(el);
    }
    n += 2;
    vector<vector<int>> dp(n, vector<int>(n, inf));
    vector<int> p;

    p.emp(0);
    for (int el : arr){
        p.emp(el);
    }
    p.emp(length);

    for (int i = 0; i < n - 1; ++i) {
        dp[i][i+1] = 0;
    }

    for (int k = 2; k < n; ++k){
        for (int l = 0; l + k < n; ++l){
            int r = k + l;
            for (int m = l + 1; m < r; ++m){
                int cost = dp[l][m] + dp[m][r] + (p[r] - p[l]);
                dp[l][r] = min(cost, dp[l][r]);
            }
        }
    }
    cout << dp[0][n-1];
}