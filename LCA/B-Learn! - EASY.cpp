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
const int maxn = 1e5;
const int logn = 20;

vector<int> graph[maxn];
int up[maxn][logn];
int timer = 0;

void dfs(int v, int p = 0) {
    up[v][0] = p;
    for (int i = 1; i < logn; ++i) {
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for (int u : graph[v]) {
        if (u != p) dfs(u, v);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;

    for (int i = 1; i < n; ++i) {
        int v; cin >> v;
        graph[v].emplace_back(i); graph[i].emplace_back(v);
    }

    dfs(0);
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        int v, u, k; cin >> v >> k;
        int l = logn;
        while (l >= 0){
            if (k >= pow(2, l)){
                v = up[v][l];
                k -= pow(2, l);
            }
            l--;
        }
        //cout << v << "\n";
        sum += v;
    }
    cout << sum;
}