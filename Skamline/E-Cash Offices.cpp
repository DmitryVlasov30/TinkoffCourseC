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
        int h, m, s, h1, m1, s1; cin >> h >> m >> s >> h1 >> m1 >> s1;
        int sec_s = h*3600 + m*60 + s, sec_f = h1*3600 + m1*60 + s1;
        if (sec_s < sec_f){
            arr.emp(sec_s, 1); arr.emp(sec_f, -1);
        } else {
            arr.emp(sec_s, 1); arr.emp(86400, -1); arr.emp(0, 1); arr.emp(sec_f, -1);
        }
    }
    sort(all(arr));
    int last = 0, balance = 0, ans = 0;
    for (auto el : arr){
        if (balance == n){
            ans += el.first - last;
        }
        balance += el.second;
        last = el.first;
    }
    cout << ans;
}