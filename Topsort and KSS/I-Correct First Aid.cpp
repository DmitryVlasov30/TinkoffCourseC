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
const int maxn = 1e5 + 10;
const int logn = 20;

struct Edge {
    int v, wight;
    Edge (int u, int w){
        v = u; wight = w;
    }
};

vector<int> graf[maxn], gr[maxn];
int timer = 0;
vector<int> used(maxn, 0), color(maxn, 0), used_dfs(maxn, 0);
vector<int> output;


void topsort(int v) {
    used[v] = 1;
    for (int u : graf[v]) {
        if (!used[u]) topsort(u);
    }
    output.emp(v);
}

void condense(int v, int c) {
    used[v] = 1;
    color[v] = c;
    for (int u : gr[v]) {
        if (!used[u]) condense(u, c);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        graf[v].emp(u);
        gr[u].emp(v);
    }

    for (int v = 1; v <= n; ++v) {
        if (!used[v]) topsort(v);
    }

    for (int i = 1; i <= n; ++i) {
        used[i] = 0;
    }

    reverse(all(output));

    int count = 0;
    for (int v : output) {
        if (!used[v]) {
            condense(v, ++count);
        }
    }

    int ans = 0;
    vector<int> check(count + 1, 0);

    for (int v = 1; v <= n; ++v) {
        for (int u : graf[v]) {
            if (color[v] != color[u]) {
                check[color[u]] = 1;
            }
        }
    }

    for (int i = 1; i <= count; ++i) {
        if (!check[i]) ans++;
    }
    cout << ans;
}