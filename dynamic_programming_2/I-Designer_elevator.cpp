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


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int a, b, c; cin >> a >> b >> c;
    vector<int> dp(n + max({a, b, c}), 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i){
        if (dp[i]){
            dp[i+a] = 1;
            dp[i+b] = 1;
            dp[i+c] = 1;
        }
    }
    int count = 0;
    for(int i = 0; i < n; ++i){
        if(dp[i]){
            ++count;
        }
    }
    cout << count;
}   
