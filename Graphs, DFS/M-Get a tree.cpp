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
vector<int> color(maxn + 1, 0);
vector<pair<int,int>> ans;
void dfs(int v){
    color[v] = 1;
    for (auto u : graf[v]){
        if (color[u] == 0){
            ans.emp(make_pair(u, v));
            dfs(u);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        graf[u].emp(v); graf[v].emp(u);
    }
    dfs(1);
    for (auto [u, v] : ans){
        cout << v << " " << u << "\n";
    }
}