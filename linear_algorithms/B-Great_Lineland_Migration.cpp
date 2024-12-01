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
    vector<int> arr, rez(n, -1);
    for (int i = 0; i < n; ++i){
        int el; cin >> el; arr.emp(el);
    }
    stack<int> new_town;
    for (int i = 0; i < n; ++i){
        while (!new_town.empty() && arr[new_town.top()] > arr[i]){
            rez[new_town.top()] = i;
            new_town.pop();
        }
        new_town.push(i);
        
    }
    for (auto el : rez){
        cout << el << " ";
    }
    
}
