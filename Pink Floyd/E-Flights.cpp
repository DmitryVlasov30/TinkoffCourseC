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
const int maxn = 1e2;

vector<int> c(maxn + 1);
vector<int> pred(maxn, -1);

struct Edge {
    int a, b, w;
};


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, s, k, f; cin >> n >> m >> k >> s >> f;
    s--; f--;
    vector<Edge> edges(m);
    for (auto& [a, b, w] : edges){
        cin >> a >> b >> w;
        --a; --b;
    }

    vector<vector<int>> dist(k+1, vector<int>(n, inf));
    dist[0][s] = 0;
    for (int i = 0; i < k; ++i){
        for (auto& [a, b, w] : edges){
            if (dist[i][a] != inf && dist[i+1][b] > dist[i][a] + w){
                dist[i+1][b] = dist[i][a] + w;
            }
        }
    }

    int ans = inf;
    for (int i = 0; i <= k; ++i){
        ans = min(ans, dist[i][f]);
    }

    if (ans == inf) cout << -1;
    else cout << ans;

}