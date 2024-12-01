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
    vector<pair<int,int>> res;
    for(int i = 0; i < n; ++i){
        int c, min_el = inf;
        cin >> c;
        vector<int> a;
        for (int j = 0; j < c*2; ++j){
            int el;
            cin >> el;
            a.emp(el);
        }
        for (int j = 0; j < c*2; j+=2){
            if (a[j] < min_el){
                min_el = a[j];
            }
        }
        res.emp(make_pair(min_el, i));
    }

    sort(all(res));
    vector<int> ans(n);
    for (int i = 0; i < len(res); ++i){
        ans[res[i].second] = i;
    }
    for (int i = 0; i < n; ++i){
        cout << ans[i] << " ";
    }
    
}   

