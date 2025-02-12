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

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> graf(n, vector<int>(n));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> graf[i][j];
            if (graf[i][j] == 0) graf[i][j] = inf;
        }
    }

    for (int v = 0; v < n; ++v){
        for (int a = 0; a < n; ++a){
            for (int b = 0; b < n; ++b){
                if (graf[a][v] != inf && graf[v][b] != inf){
                    if (graf[a][b] > graf[a][v] + graf[v][b]){
                        graf[a][b] = graf[a][v] + graf[v][b];
                    }
                }
            }
        }
    }

    int ans = -inf;
    for (int a = 0; a < n; ++a){
        for (int b = 0; b < n; ++b){
            if (graf[a][b] == inf) cout << 0 << " ";
            else cout << 1 << " ";
        }
        cout << "\n";
    }
}