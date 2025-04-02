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
#include <strstream>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <deque>
#include <cstring>
#include <cassert>

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

const int mod = 1e9 + 9;
const int inf = 1e18;
const int maxn = 3e5 + 10;
const int logn = 20;

struct Edge {
    int v, wight;
    Edge (int u, int w){
        v = u; wight = w;
    }
};

vector<int> graf[maxn], gr[maxn];
int timer = 0;
vector<int> used(maxn, 0), size_g(maxn, 0);
vector<int> output;

void dfs_size(int v){
    size_g[v] = 1;
    for (int u : graf[v]){
        dfs_size(u);
        size_g[v] += size_g[u];
    }
}

void dfs(int v, vector<int>& dp){
    dp[v] = size_g[v];
    for (int u : graf[v]){
        dfs(u, dp);
        dp[v] += dp[u];
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> dp(n+1);
    for (int i = 1; i < n; ++i){
        int v; cin >> v;
        --v;
        graf[v].emp(i);
    }

    for (int i = 0; i < n; ++i){
        if (len(graf[i]) > 1){
            sort(all(graf[i]));
        }
    }

    dfs_size(0);
    dfs(0, dp);

    for (int i = 0; i < n; ++i){
        cout << dp[i] << " ";
    }

}