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

vector<int> dijkstra(int s, int n){
    vector<int> dist(n, inf);
    dist[s] = 0;

    set<pair<int,int>> S;
    S.insert({0, s});

    while(!S.empty()){
        auto [d, u] = *S.begin();
        S.erase(S.begin());

        for (auto [v, w] : graf[u]){
            if(dist[v] > dist[u] + w){
                S.erase({dist[v], v});
                dist[v] = dist[u] + w;
                pred[v] = u;
                S.insert({dist[v], v});
            }
        }
    }
    return dist;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, s, t; cin >> n >> m >> s >> t;
    for (int i = 0; i < m; ++i){
        int u, v, w; cin >> u >> v >> w;
        graf[v-1].emp(make_pair(u-1, w)); graf[u-1].emp(make_pair(v-1, w));
    }

    vector<int> ans = dijkstra(s-1, n);
    vector<int> path;
    int res = ans[--t];
    if (res == inf){
        cout << -1;
        return 0;
    }
    while(pred[t] != -1){
        path.emp(t);
        t = pred[t];
    }
    cout << res << " " << len(path)+1 << "\n";
    reverse(all(path));
    cout << s << " ";
    for (auto el : path){
        cout << el+1 << " ";
    }
}