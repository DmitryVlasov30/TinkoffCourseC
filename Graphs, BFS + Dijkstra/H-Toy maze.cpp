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


int32_t bfs(vector<vector<int>>& arr, int n, int m){
    vector<vector<int>> dist(n+2, vector<int>(m+2, -1));
    queue<pair<int,int>> q;
    dist[1][1] = 0; q.push(make_pair(1, 1));
    while(!q.empty()){
        int i = q.front().fir, j = q.front().sec;
        q.pop();
        if (arr[i][j] == 2){
            return dist[i][j];
        }
        for (int sti = -1; sti <= 1; ++sti){
            for (int stj = -1; stj <= 1; ++stj){
                if (sti*sti + stj*stj == 1){
                    int ki = i, kj = j;
                    while (true){
                        if (arr[ki][kj] == 2 || arr[ki+sti][kj+stj] == 1){
                            break;
                        }
                        ki += sti; kj += stj;
                    }
                    if (dist[ki][kj] == -1){
                        dist[ki][kj] = dist[i][j] + 1;
                        q.push(make_pair(ki, kj));
                    }
                }
            }
        }
    }
    return 0;
}


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> arr(n+2, vector<int> (m+2, 1));
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> arr[i][j];
        }
    }
    cout << bfs(arr, n, m);
}