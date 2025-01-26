//#define _GLIBCXX_DEBUG
#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <vector>
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

struct Event {
    int x, type;
    Event(int x, int type, int idx) : x(x), type(type) {};
};

bool comp(Event a, Event b){
    return make_pair(a.x, a.type) < make_pair(b.x, b.type);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m; cin >> m;
    vector<pair<int,int>> arr, res;
    
    while (true){
        int s, f; cin >> s >> f;
        if (s == f && f == 0){
            break;
        }
        if (f < 0) continue;
        arr.emp(s, f);
    }

    sort(all(arr));
    int i = 0, cur = 0;

    while (true){
        int best_end = cur, idx = -1;
        
        while (i < len(arr) && arr[i].first <= cur) {
            if (arr[i].second > best_end){
                best_end = arr[i].second; idx = i;
            }
            ++i;
        }

        if (idx == -1) {cout << "No solution"; return 0;}
        res.emp(arr[idx]);
        cur = res.back().second;
        if (cur >= m){
            break;
        }
    }

    cout << len(res) << "\n";
    for (auto& el : res){
        cout << el.first << ' ' << el.second << "\n";
    }
}