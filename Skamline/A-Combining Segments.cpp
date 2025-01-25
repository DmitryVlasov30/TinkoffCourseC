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


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<pair<int,int>> event, ans;
    for (int i = 0; i < n; ++i){
        int f, s; cin >> f >> s; 
        event.emp(f, s);
    }
    sort(all(event));
    pair<int,int> unif = event.front();
    for (int i = 0; i < n; ++i){
        if (event[i].fir <= unif.sec){
            unif.sec = max(unif.sec, event[i].sec);
        } else {
            ans.emp(unif);
            unif = event[i];
        }
    }
    if (ans.empty() || unif != ans.back()){
        ans.emp(unif);
    }
    cout << len(ans) << "\n";
    for (auto el : ans){
        cout << el.fir << ' ' << el.sec << "\n";
    }

}