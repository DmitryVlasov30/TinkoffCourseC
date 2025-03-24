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
const int maxn = 2e5 + 1;
const int logn = 20;

struct Edge {
    int a, b, w;
};

vector<int> g[maxn];
vector<int> c;
vector<vector<int>> dp;

void dfs(int v, int p){
    dp[1][v] += c[v];
    for (auto u : g[v]) {
        if (u == p) continue;
        dfs(u, v);
        dp[1][v] += dp[0][u];
        dp[0][v] += max(dp[0][u], dp[1][u]);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; c.emp(x);
    }
    for (int i = 0; i < n-1; ++i){
        int u, v; cin >> u >> v;
        --u; --v;
        g[u].emp(v); g[v].emp(u);
    }
    dp.resize(2, vector<int>(n, 0));
    dfs(0, -1);
    cout << max(dp[1][0], dp[0][0]);
}