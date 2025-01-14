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

void dfs2(int u, int color) {
    c2[u] = color;
    arr.emp(u);
    for (int v : graf[u]) {
        if (c2[v] == 0){
            dfs2(v, color);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        graf[u].emp(v); graf[v].emp(u);
    }
    int cnt = 0;
    for (int u = 1; u <= n; ++u) {
        if (c[u] == 0) {
            ++cnt;
            dfs(u, cnt);
        }
    }
    cout << cnt << "\n";
    cnt = 0;
    for (int u = 1; u <= n; ++u){
        if(c2[u] == 0){
            ++cnt;
            dfs2(u, cnt);
            cout << len(arr) << "\n";
            sort(all(arr));
            for (auto el : arr){
                cout << el << " ";
            }
            cout << "\n";
            arr.clear();
        }
    }
}