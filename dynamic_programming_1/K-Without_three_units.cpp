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

#define int long long
#define len(x) x.size()
#define all(x) x.begin(), x.end()
#define ld long double

using namespace std;


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> dp(n+1, 0);
    dp[1] = 2;
    if (n > 1){
        dp[2] = 4;
    } if (n > 2){
        dp[3] = 7;
    }
    for (int i = 4; i <= n; ++i){
        dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
    }
    cout << dp[n];

}
