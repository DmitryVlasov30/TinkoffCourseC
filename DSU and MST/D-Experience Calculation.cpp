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
const int maxn = 2e5 + 1;
const int logn = 20;

struct Edge {
    int a, b, w;
};

vector<Edge> g;
int timer = 0;
vector<int> used(maxn, 0), color(maxn, 0);
vector<int> rk(maxn, 0);
vector<int> p(maxn);
vector<int> sum(maxn);


int get_root(int i){
    if (p[i] == i) return i;
    return get_root(p[i]);
}


int get_sum(int i){
    if (p[i] == i) return sum[i];
    return get_sum(p[i]) + sum[i];
}

void join(int i, int j){
    i = get_root(i);
    j = get_root(j);
    if (i == j) return;
    if (rk[i] < rk[j]) swap(i, j);
    p[j] = i;
    sum[j] -= sum[i];
    if (rk[i] == rk[j]) rk[i]++;
}


void add(int i, int x){
    sum[get_root(i)] += x;
}



signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < maxn; ++i) p[i] = i;
    for (int i = 0; i < m; ++i){
        string com; cin >> com;
        if (com == "add") {
            int x, v; cin >> x >> v;
            add(x, v);
        } else if (com == "join"){
            int u, v; cin >> u >> v;
            join(u, v);
        } else {
            int x; cin >> x;
            cout << get_sum(x) << "\n";
        }
    }

}