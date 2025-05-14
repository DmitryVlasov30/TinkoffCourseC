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

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define int long long
#define len(x) x.size()
#define all(x) x.begin(), x.end()
#define ld long double
#define fir first
#define sec second
#define emp emplace_back
#define ins insert

using namespace std;

const int mod = 1e9 + 7;
const int inf = 1e18;
const int maxn = 31;
const int logn = 20;
const int p = 31;

vector<vector<bool>> visited(maxn + 1e3, vector<bool> (maxn+1e3, false));
vector<int> move_x = {0, -1, 0, 1};
vector<int> move_y = {-1, 0, 1, 0};
vector<string> name_moves = {"SOUTH", "WEST", "NORTH", "EAST"};


bool check_move(const string& name_move){
    cout << name_move << endl;
    string ans; cin >> ans;
    return ans == "EMPTY";
}

void dfs(int x, int y){
    if (visited[x][y]) return;
    visited[x][y] = true;

    for (int dir = 0; dir < 4; ++dir){
        bool res = check_move(name_moves[dir]);
        if (res){
            dfs(x + move_x[dir], y + move_y[dir]);
            check_move(name_moves[(dir+2) % 4]);
        }

    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dfs(100, 100);
    cout << "DONE" << endl;
}