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

bool comp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<pair<int,int>> arr;
    for (int i = 0; i < n; ++i){
        int s, deadline; cin >> s >> deadline;
        arr.emp(s, deadline);
    }
    sort(all(arr));
    int ans = 0, now = 0;
    for (auto [s, d] : arr){
        now += s;
        ans += d - now;
    }
    cout << ans;
}