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

const int mod = 1e9 + 7;
const int inf = 1e18;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    vector<int> dp(n, 0);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    sort(all(arr));

    if(n == 2){
       cout << arr[1] + arr[0];
       return 0;
    }
    dp[0] = arr[1] - arr[0];
    dp[1] = arr[2] - arr[0];
    for(int i = 2; i < n-1; ++i){
        dp[i] = arr[i+1] - arr[i] + min(dp[i-1], dp[i-2]);
    }
    cout << dp[n-2];
}
