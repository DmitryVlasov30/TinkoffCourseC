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
const int maxn = 6e4;
const int logn = 20;

vector<pair<int,int>> graph[maxn];      
int timer = 0;
vector<int> tin(maxn), tout(maxn);
pair<int,int> up[maxn][logn];
int l;

void dfs(int v, int p = 1, int c = inf){
    tin[v] = timer++;
    up[v][0] = {p, c};
    for (int i = 1; i <= l; ++i){
        up[v][i].first = up[up[v][i-1].first][i-1].first;
        up[v][i].second = min(up[v][i-1].second, up[up[v][i-1].first][i-1].second);   
    }   

    for (auto [a, c] : graph[v]){
        dfs(a, v, c);
    }
    tout[v] = timer++;
}

bool is_pr(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}


int lca(int u, int v){
    int ans = inf;

    for (int i = l; i >= 0; --i){
        if (!is_pr(up[u][i].first, v)){
            ans = min(ans, up[u][i].second);
            u = up[u][i].first;
        }
    }
    
    if (!is_pr(u, v)) ans = min(ans, up[u][0].second);

    for (int i = l; i >= 0; --i){
        if (!is_pr(up[v][i].first, u)){
            ans = min(ans, up[v][i].second);
            v = up[v][i].first;
        }
    }

    if (!is_pr(v, u)) ans = min(ans, up[v][0].second);

    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n;

    l = 0;
    int i = 1;
    while (i <= n){
        ++l;
        i *= 2;
    }

    for (int i = 2; i <= n; ++i){
        int u, v; cin >> u >> v;
        graph[u].emp(i, v);
    }

    dfs(1);

    cin >> m;
    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        cout << lca(u, v) << "\n";
    }

}