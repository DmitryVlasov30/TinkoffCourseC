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
    int n, m, start = 0; cin >> n >> m;
    vector<Edge> edges(m);
    for (auto& [a, b, w] : edges){
        cin >> a >> b >> w;
        --a; --b;
    }

    vector<int> dist(n, inf);
    dist[start] = 0;
    for (int i = 0; i < n-1; ++i){
        for (auto& [a, b, w] : edges){
            if (dist[a] != inf && dist[b] > dist[a] + w){
                dist[b] = dist[a] + w;
            }
        }
    }

    for (auto el : dist){
        if (el == inf){
            cout << 30000 << " "; continue;
        }
        cout << el << " ";
    }
}