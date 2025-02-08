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
const int maxn = 2*1e5;

vector<vector<pair<int,int>>> graf(maxn);
vector<int> c(maxn + 1);
vector<int> pred(maxn, -1);

struct elem {
    int dir;
    int i, j;
    elem(int dir, int i, int j) : dir(dir), i(i), j(j) {}
};

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    int sx = -1, sy = -1, fx = -1, fy = -1;

    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < len(s); ++j) {
            arr[i][j] = s[j];
            if (arr[i][j] == 'S') {
                if (sx == -1 && sy == -1) {
                    sx = i; sy = j;
                    arr[i][j] = '.';
                }
            } else if (arr[i][j] == 'F') {
                if (fx == -1 && fy == -1) {
                    fx = i; fy = j;
                    arr[i][j] = '.';
                }
            }
        }
    }

    vector<vector<vector<int>>> dist(4, vector<vector<int>>(n, vector<int>(m, -1)));
    queue<elem> q;
    vector<int> di = {-1, 0, 1, 0};
    vector<int> dj = {0, 1, 0, -1};
    for (int d = 0; d < 4; ++d) {
        dist[d][sx][sy] = 0;
        q.push(elem(d, sx, sy));
    }

    while (!q.empty()) {
        elem cur = q.front();
        q.pop();
        if (cur.i == fx && cur.j == fy) {
            cout << dist[cur.dir][cur.i][cur.j];
            return 0;
        }
        for (int dd = 0; dd < 2; ++dd) {
            int newd = (cur.dir + dd) % 4;
            int newi = cur.i + di[newd], newj = cur.j + dj[newd];
            if (arr[newi][newj] == '.' && dist[newd][newi][newj] == -1) {
                dist[newd][newi][newj] = dist[cur.dir][cur.i][cur.j] + 1; 
                q.push(elem(newd, newi, newj));
            }
        }
    }
}