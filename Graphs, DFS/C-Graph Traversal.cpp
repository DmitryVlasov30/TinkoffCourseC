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

void dfs(int v, vector<vector<int>> &graf, vector<int> &used){
    used[v] = 1;
    for (int &u : graf[v]){
        if (used[u] != 1){
            dfs(u, graf, used);
        }
    }
}


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, s; cin >> n >> s;
    vector<vector<int>> graf(n);
    --s;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            int el; cin >> el;
            if (el == 1){
                graf[i].emp(j);
            }
        }
    }

    vector<int> used(n);
    dfs(s, graf, used);
    int count = 0;
    for (int i = 0; i < len(used); ++i){
        if (used[i] == 1){
            ++count;
        }
    }
    cout << count;
}