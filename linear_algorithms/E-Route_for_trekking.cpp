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
const int inf = 1e7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> arr;
    for (int i = 0; i < n; ++i){
        int el; cin >> el; arr.emp(el);
    }
    vector<int> dp(n, 0);
    for (int i = 1; i < n; ++i){
        if (arr[i] > arr[i-1]){
            dp[i] = dp[i-1] + 1;
        } else {
            dp[i] = dp[i-1];
        }
    }
    int ans = inf;
    for (int i = 0; i < n; ++i){
        if (i + (k-1) < n){
            ans = min(ans, dp[i+k-1] - dp[i]);
        }
    }
    cout << ans;
}
