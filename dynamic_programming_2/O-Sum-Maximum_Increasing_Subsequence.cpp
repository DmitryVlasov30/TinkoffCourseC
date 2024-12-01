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
const int inf = 1e7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; ++i){
        int el; cin >> el;
        arr.emp(el);
    }

    vector<int> dp(n, 0), prev(n, -1);
    for(int i = 0; i < n; ++i){
        dp[i] = arr[i];
    }

    int sum_m = 0, idx_m = 0;

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < i; ++j){
            if (arr[i] > arr[j] && dp[j] + arr[i] > dp[i]){
                dp[i] = dp[j] + arr[i];
                prev[i] = j;
            }
        }
        if (dp[i] > sum_m){
            sum_m = dp[i]; idx_m = i;
        }
    }

    vector<int> res;
    int i = idx_m;
    while(i != -1){
        res.emp(arr[i]);
        i = prev[i];

    }
    reverse(all(res));
    for (int i = 0; i < len(res); ++i){
        cout << res[i] << " ";
    }
}
