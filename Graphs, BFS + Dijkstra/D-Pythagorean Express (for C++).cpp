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

vector<vector<pair<int,int>>> graf(maxn);
vector<int> c(maxn + 1);

int distance(int x1, int y1, int x2, int y2){
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

vector<int> dijkstra(int s, int n, vector<pair<int, int>>& arr){
    vector<int> dist(n, inf);
    vector<bool> used(n, false);
    dist[s] = 0;

    for(int i = 0; i < n; ++i){
        int v = -1;
        for(int u = 0; u < n; ++u){
            if (!used[u] && (v == -1 || dist[v] > dist[u])){
                v = u;
            }
        }
        for (int u = 0; u < n; ++u){
            int w = distance(arr[v].first, arr[v].second, arr[u].first, arr[u].second);
            dist[u] = min(dist[u], dist[v] + w); 
        }
        used[v] = true;
    }
    return dist;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i){
        int x, y; cin >> x >> y; arr[i] = make_pair(x, y);
    }

    int s, t; cin >> s >> t;
    vector<int> ans = dijkstra(--s, n, arr);
    cout << ans[--t];
}