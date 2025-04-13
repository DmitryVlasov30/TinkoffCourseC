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

using namespace std;

const int mod = 1e9 + 7;
const int inf = 1e18;
const int maxn = 20;
const int logn = 20;

struct Edge {
    int a, b, w;
};

vector<vector<int>> g(maxn, vector<int> (maxn));

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            int el; cin >> el;
            g[i][j] = el;
            if (g[i][j] == 0) g[i][j] = inf;
        }
    }

    vector<vector<int>> dp(1 << n, vector<int> (n, inf));
    vector<vector<int>> prev(1 << n, vector<int> (n, -1));
    dp[1][0] = 0;
    for (int mask = 1; mask < (1 << n); ++mask){
        for (int j = 0; j < n; ++j){
            if (mask & (1 << j) && dp[mask][j] != inf){
                for (int v = 0; v < n; ++v){
                    if (mask & (1 << v)) continue;
                    int new_mask = mask | (1 << v);
                    if (dp[mask][j] + g[j][v] < dp[new_mask][v]){
                        dp[new_mask][v] = dp[mask][j] + g[j][v];
                        prev[new_mask][v] = j;
                    }
                }
            }
        }
    }
    int mask = (1 << n) - 1;
    int ans = inf, u = -1;
    for (int v = 0; v < n; ++v){
        if (dp[mask][v] < ans){
            ans = dp[mask][v]; u = v;
        }
    }
    if (ans == inf) { cout << -1; return 0; }

    vector<int> res;
    int now_mask = mask;
    int idx = u;
    while (idx != -1){
        res.emp(idx);
        int last = prev[now_mask][idx];
        now_mask ^= (1 << idx);
        idx = last;
    }

    reverse(all(res));
    cout << ans << "\n";
    for (int el : res)
        cout << el + 1 << " ";
}