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
    int n, e; cin >> n >> e;
    vector<vector<int>> graf(n, vector<int>(n, inf)), from(n, vector<int>(n, -1));
    for (int i = 0; i < n; ++i){
        graf[i][i] = 0;
    }

    for (int i = 0; i < e; ++i){
        int a, b, w; cin >> a >> b >> w;
        --a; --b;
        graf[a][b] = min(graf[a][b], w);
        from[a][b] = a;
    }

    for (int v = 0; v < n; ++v){
        for (int a = 0; a < n; ++a){
            for (int b = 0; b < n; ++b){
                if (graf[a][v] != inf && graf[v][b] != inf){
                    if (graf[a][b] > graf[a][v] + graf[v][b]){
                        graf[a][b] = graf[a][v] + graf[v][b];
                        from[a][b] = from[v][b];
                    }
                }
            }
        }
    }

    bool flag = false;
    vector<int> ans;
    for (int v = 0; v < n; ++v){
        if(graf[v][v] < 0){
            flag = true;
            for (int i = 0; i < n - 1; ++i){
                v = from[v][v];
            }
            ans.emp(v);
            for (int cycle = from[v][v]; cycle != v; cycle = from[v][cycle]){
                ans.emp(cycle);
            }
            reverse(all(ans));
            break;
        }
    }
    if (flag) {
        cout << "LOOP\n" << len(ans) << "\n";
        for (auto& el : ans){
            cout << el + 1 << " ";
        }
    } else {
        cout << "NO LOOP" << "\n";
        for (int a = 0; a < n; ++a){
            for (int b = 0; b < n; ++b){
                if (graf[a][b] == inf){
                    cout << "INF "; continue;
                }
                cout << graf[a][b] << " ";
            }
            cout << "\n";
        }
    }
}