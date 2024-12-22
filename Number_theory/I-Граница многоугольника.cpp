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
    int n; cin >> n;
    vector<pair<int,int>> arr;
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y; arr.emp(make_pair(x, y));
    }
    int last_x = arr[0].fir, last_y = arr[0].sec, res = 0;
    
    for (int i = 1; i < n; ++i){
        res += __gcd(abs(arr[i].fir - last_x), abs(arr[i].sec - last_y));
        last_x = arr[i].fir; last_y = arr[i].sec;
    }

    cout << res + __gcd(abs(last_x - arr[0].fir), abs(last_y - arr[0].sec));

}
