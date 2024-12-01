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
    string s, left = "", right = ""; cin >> s;
    map<char, int> col_char;
    for(int i = 0; i < n; ++i){
        col_char[s[i]]++;
    }
    bool flag = false;
    int count = 0;
    vector<char> arr;
    for (auto el : col_char){  
        if (el.sec % 2 != 0){
            arr.emp(el.first);
            el.second--;
        }
        for (int i = 0; i < el.second/2; ++i){
            left += el.first;
            right += el.first;
        }
    }
    string ans = "";
    if (len(arr) != 0){
        sort(all(arr));
        ans += arr[0];
    }
    sort(all(left)); sort(all(right));
    reverse(all(right));
    cout << left << ans << right;

}
