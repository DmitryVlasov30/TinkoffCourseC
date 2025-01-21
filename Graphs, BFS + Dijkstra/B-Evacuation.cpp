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
vector<int> bfs(int n, vector<int>& starts){
    vector<int> dist(n+1, inf);
    //dist[start] = 0;
    queue<int> q;
    for (int i = 0; i < len(starts); ++i){
        q.push(starts[i]);
        dist[starts[i]] = 0;
    }
    //cout << 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : graf[u]){
            if (dist[v] == inf){
                q.push(v);
                dist[v] = dist[u] + 1;
            }
        }
    }
    return dist;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> starts;
    for (int i = 0; i < k; ++i){
        int el; cin >> el; starts.emp(el);
    }

    int m; cin >> m;
    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v; 
        graf[u].emp(v); graf[v].emp(u); 
    }

    vector<int> ans = bfs(n, starts);
    for (int i = 1; i < len(ans); ++i){
        cout << ans[i] << " ";
    }

}