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

vector<int> act(int n){
    vector<int> res;
    if (n <= 8999){
        res.emp(n+1000);
    } if (n % 10 != 1) {
        res.emp(n-1);
    } 
    string s_prom = to_string(n), ans_right = "", ans_left = "";
    char s1 = s_prom[0], s2 = s_prom[1], s3 = s_prom[2], s4 = s_prom[3];
    ans_right += s4; ans_right += s1; ans_right += s2; ans_right += s3;
    ans_left += s2; ans_left += s3; ans_left += s4; ans_left += s1;
    res.emp(stoi(ans_left)); res.emp(stoi(ans_right));
    return res;
}

vector<int> bfs(int n, int m){
    set<int> used;
    used.insert(n);
    queue<pair<int,vector<int>>> q;
    q.push({n, {n}});
    while (!q.empty()) {
        int u = q.front().fir;
        vector<int> path = q.front().sec;
        q.pop();
        if (u == m){
            return path;
        }
        vector<int> action = act(u);
        for (auto el : action){
            if (used.find(el) == used.end()){
                vector<int> arr = path;
                arr.emp(el);
                used.insert(el); q.push({el, arr});    
            }
        }
    }
    return {};
    
}


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> ans = bfs(n, m);
    cout << len(ans) << "\n";
    for(int i = 0; i < len(ans); ++i){
        cout << ans[i] << "\n";
    }
    /*
    cout << "\n";
    for (auto el : act(n)){
        cout << el << "\n";
    }
    */
}