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
#include <numbers>
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
    dp[1] = 0;
    for(int i = 2; i <= n; ++i){
        dp[i] = dp[i-1]+1;
        if (i % 3 == 0){
            dp[i] = min(dp[i], dp[i/3]+1);
        } if (i % 2 == 0){
            dp[i] = min(dp[i], dp[i/2]+1);
        }
    }
    int ans = dp[n];
    int i = n;
    vector<int> ans_arr;
    while (i > 0){
        if (i % 3 == 0 && dp[i/3] == dp[i]-1){
            i /= 3;
        } else if (i % 2 == 0 && dp[i/2] == dp[i]-1){
            i /= 2;
        } else {
            i -= 1;
        }
        ans_arr.emplace_back(i);
    }

    reverse(all(ans_arr));
    ans_arr.emplace_back(n);
    cout << ans << "\n";
    for(int i = 1; i < len(ans_arr); ++i){
        cout << ans_arr[i] << " "; 
    }
}
