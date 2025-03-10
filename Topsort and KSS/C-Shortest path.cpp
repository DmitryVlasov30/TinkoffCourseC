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

vector<pair<int,int>> graph[maxn];     
int timer = 0;
vector<int> used(maxn, 0);
vector<int> output;


void topsort(int v){
    if (used[v]) return;
    used[v] = 1;
    for (auto [u, w] : graph[v]){
        topsort(u);
    } 
    output.emp(v);
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, s, t; cin >> n >> m >> s >> t;
    for (int i = 0; i < m; ++i){
        int u, v, w; cin >> u >> v >> w;
        graph[u].emp(v, w);
    }
    vector<int> dp(n+1, inf);
    dp[s] = 0;
    topsort(s);
    reverse(all(output));
    for (int v : output){
        if (dp[v] != inf){
            for (auto [to, w] : graph[v]){
                dp[to] = min(dp[to], dp[v] + w);
            }
        }
    }
    if (dp[t] == inf) cout << "Unreachable";
    else cout << dp[t];
}