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

int bfs(pair<int,int> e, pair<int,int> s, vector<vector<char>>& arr){
    vector<pair<int,int>> action = {
        {0, 1}, 
        {0, -1}, 
        {1, 0},
        {-1, 0}
    };
    queue<pair<pair<int,int>,int>> q;
    q.push({s, 0});
    set<pair<int,int>> used;
    used.insert({0, 0});
    while (!q.empty()){
        int i = q.front().first.first, j = q.front().first.second, l = q.front().second;;
        q.pop();
        if (i == e.first && j == e.second){
            return l;
        }
        for (auto [x, y] : action){
            int i1 = i + x, j1 = j + y;
            if (i1 >= 0 && i1 < len(arr) && j1 >= 0 && j1 < len(arr[0])){
            //cout << arr[i1][j1] << " " << i1 << " " << j1 << " i, j\n";
                if (used.find({i1, j1}) == used.end() && arr[i1][j1] == '.'){
                    used.insert({i1, j1});
                    q.push({{i1, j1}, l+1});
                }
            }
        }
    }
    return -1;
}


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<char>> arr;
    for (int i = 0; i < n; ++i){
        string el; cin >> el;
        vector<char> arr_prom;
        for (char el1 : el){arr_prom.emp(el1);}
        arr.emp(arr_prom);
    }
    pair<int,int> end1 = {n-1, m-1}, s = {0,0};
    int ans = bfs(end1, s, arr);
    cout << ans;
}