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

vector<int> graf[maxn + 1];
vector<int> c(maxn + 1);
void dfs(int u) {
    c[u] = 1; 
    for (int v : graf[u]) {
        if (c[v] == 0) {
            dfs(v);
        } else if (c[v] == 1) { 
            cout << 1; exit(0);
        }
    }
    c[u] = 2;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        graf[u].emp(v);
    }
    for (int u = 1; u <= n; ++u) {
        if (c[u] == 0) {
            dfs(u);
        }
    }
    cout << 0;
}