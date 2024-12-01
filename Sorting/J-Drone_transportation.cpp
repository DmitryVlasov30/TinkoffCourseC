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
    int n, m; cin >> n >> m;
    vector<int> a, b;
    for (int i = 0; i < n*m; ++i){
        int el; cin >> el; a.emp(el);
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i){
        int el1; cin >> el1; b.emp(el1); 
    } 
    sort(all(a));
    sort(all(b));
    int j = 0, ans = 0;
    for (int i = 0; i < n*m; ++i){
        while(j < k && a[i] >= b[j]){
            //cout << a[i] << ' ' << b[j] << "\n";
            ans++;
            ++j;
            break;
        }
    }
    cout << ans;
}   
