//#define _GLIBCXX_DEBUG
#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <vector>
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
const int maxn = 1e3;

vector<vector<int>> graf(maxn, vector<int>(maxn, 0)); 
vector<vector<int>> used(maxn, vector<int>(maxn, 0));

void dfs(int i, int j, int color) {
    if (i < 0 || i >= maxn || j < 0 || j >= maxn || graf[i][j] == 0 || used[i][j]) {
        return;
    }
    used[i][j] = color;
    dfs(i + 1, j, color);
    dfs(i - 1, j, color);
    dfs(i, j - 1, color);
    dfs(i, j + 1, color);
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, color = 1; cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char el; cin >> el;
            if (el == '.') graf[i][j] = 0;
            else graf[i][j] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (graf[i][j] && !used[i][j]) {
                dfs(i, j, color);
                ++color;
            }
        }
    }
    
    cout << --color;
}