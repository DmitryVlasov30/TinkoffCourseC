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
const int maxn = 1e6;
const int logn = 20;

vector<int> graph[maxn];      
int timer = 0;
vector<int> tin(maxn), tout(maxn);
int up[maxn][logn];
int l;


void dfs(int v, int p = 0) {
    tin[v] = timer++;

    up[v][0] = p;
    
    for (int i = 1; i <= l; ++i){
        up[v][i] = up[up[v][i-1]][i-1];
    }

    for (int u : graph[v]) {
        if (u != p) {
            dfs(u, v);
        }
    }
    tout[v] = timer++;
}

bool is_pr(int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int lca(int u, int v) {
    if (is_pr(u, v)) return u;
    if (is_pr(v, u)) return v;
    for (int i = l; i >= 0; i--) {
        int w = up[u][i];
        if (!is_pr(w, v)) {
            u = w;
        }
    }
    return up[u][0];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;

    l = 0;
    int i = 1;
    while (i <= n){
        ++l;
        i *= 2;
    }

    for (int i = 1; i < n; i++) {
        int v; cin >> v;
        graph[v].emp(i); graph[i].emp(v);
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= l; ++j) {
            up[i][j] = 0;
        }
    }

    dfs(0);
    int sum = 0;
    for(int i = 0; i < m; ++i){
        int v, u; cin >> v >> u;
        sum += lca(v, u);
    }
    cout << sum;
}