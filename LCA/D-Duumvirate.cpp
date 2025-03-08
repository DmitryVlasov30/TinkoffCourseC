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
vector<int> tin(maxn), tout(maxn);
int up[maxn][logn];
int l;
vector<int> sums(maxn);

void dfs(int v, int p, int d, vector<int>& w){
    tin[v] = d;
    sums[v] = (p == -1 ? w[v] : sums[p] + w[v]);
    up[v][0] = p;
    
    for (int i = 1; i < logn; ++i){
        if (up[v][i-1] != -1){
            up[v][i] = up[up[v][i-1]][i-1];
        } else {
            up[v][i] = -1;
        }
    }

    for (int u : graph[v]){
        if (u != p){
            dfs(u, v, d+1, w);
        }
    }
}

int lca(int u, int v){
    if (tin[u] < tin[v]){
        swap(u, v);
    }

    for (int i = logn-1; i >= 0; --i){
        if (up[u][i] != -1 && tin[up[u][i]] >= tin[v]){
            u = up[u][i];
        }
    }

    if (u == v) return u;

    for (int i = logn-1; i >= 0; --i){
        if (up[u][i] != -1 && up[v][i] != -1 && up[u][i] != up[v][i]){
            u = up[u][i]; v = up[v][i];
        }
    }
    return up[u][0];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> w(maxn);
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }

    for (int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        graph[a].emp(b); graph[b].emp(a);
    }

    for (int i = 0; i < maxn; ++i){
        for (int j = 0; j < logn; ++j){
            up[i][j] = -1;
        }
    }

    dfs(1, -1, 0, w);
    int m; cin >> m;
    for(int i = 1; i <= m; ++i){
        int u, v; cin >> u >> v;
        int anc = lca(u, v);
        int ans = sums[u] + sums[v] - 2 * sums[anc] + w[anc];
        cout << ans << "\n";
    }
}