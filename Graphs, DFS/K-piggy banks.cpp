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
const int maxn = 100000;

vector<int> graf[maxn + 1];
vector<int> c(maxn + 1);
vector<int> c2(maxn + 1);
vector<int> arr;
void dfs(int u, int color) {
    c[u] = color;
    for (int v : graf[u]) {
        if (c[v] == 0){
            dfs(v, color);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> m;
    n = m;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> v;
        graf[v].emp(i); graf[i].emp(v);
    }
    int cnt = 0;
    for (int u = 1; u <= n; ++u) {
        if (c[u] == 0) {
            ++cnt;
            dfs(u, cnt);
        }
    }
    //cout << "----";
    cout << cnt << "\n";
}