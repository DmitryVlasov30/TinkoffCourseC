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

bool comp(string a, string b){
    return a+b > b+a;
}


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<string> arr;
    string el;
    while (cin >> el){
        arr.emp(el);
    }
    sort(all(arr), comp);
    for(auto el : arr){
        cout << el;
    }
}   


