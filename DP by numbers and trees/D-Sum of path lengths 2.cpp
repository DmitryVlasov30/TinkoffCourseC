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
#include <cstring>
#include <cassert>

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define int long long
#define len(x) x.size()
#define all(x) x.begin(), x.end()
#define ld long double
#define fir first
#define sec second
#define emp emplace_back

using namespace std;

const int mod = 1e9 + 9;
const int inf = 1e18;
const int maxn = 1e5 + 10;
const int logn = 20;

struct Edge {
    int v, wight;
    Edge (int u, int w){
        v = u; wight = w;
    }
};

vector<vector<Edge>> graph(maxn);
vector<int> size_tree(maxn), sum(maxn, 0);

void dfs1(int v, int p){
    size_tree[v] = 1;

    for (Edge& e : graph[v]){
        if (e.v != p){
            dfs1(e.v, v);
            size_tree[v] += size_tree[e.v];
            sum[v] += sum[e.v] + e.wight * size_tree[e.v];
        }
    }
}


void dfs2(int v, int p, int p_cont, vector<int>& answer){
    answer[v] = sum[v] + p_cont;
    for (Edge& e : graph[v]){
        if (e.v != p){
            int new_parent = p_cont + (sum[v] - (sum[e.v] + e.wight * size_tree[e.v])) + e.wight * (size_tree[0] - size_tree[e.v]);
            dfs2(e.v, v, new_parent, answer);
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> answer(n);
    for (int i = 0; i < n-1; ++i){
        int u, v, w; cin >> u >> v >> w;
        --u; --v;
        graph[u].emp(Edge(v, w)); graph[v].emp(Edge(u, w));
    }

    dfs1(0, -1);
    dfs2(0, -1, 0, answer);
    for (int el : answer){
        cout << el << " ";
    }

}