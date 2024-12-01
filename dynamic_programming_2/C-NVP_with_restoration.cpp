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
    vector<int> arr, sort_arr;
    for (int i = 0; i < n; ++i){
        int a;
        cin >> a;
        arr.emp(a);
    }

    vector<int> dp(n, 1), prev(n, -1);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < i; ++j){
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }

    int now = 0, ans = dp[0];
    for (int i = 0; i < n; ++i){
        if (dp[i] > ans){
            now = i;
            ans = dp[i];
        }
    }

    vector<int> res;
    while(now != -1){
        res.emp(arr[now]);
        now = prev[now];
    }

    reverse(all(res));
    cout << ans << "\n";
    for (int i = 0; i < len(res); ++i){
        cout << res[i] << " ";
    }
}
