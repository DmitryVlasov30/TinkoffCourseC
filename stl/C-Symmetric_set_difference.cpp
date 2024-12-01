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

#define int long long
#define len(x) x.size()
#define all(x) x.begin(), x.end()
#define ld long double

using namespace std;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n;
    set<int> ans, set1, set2;
    for (int i = 0; i < n; ++i){
        int el;
        cin >> el;
        set1.insert(el);
    } 
    cin >> m;
    for (int i = 0; i < m; ++i){
        int el;
        cin >> el;
        set2.insert(el);
        if (set1.find(el) == set1.end()){
            ans.insert(el);
        }
    }

    for(auto el : set1){
        if (set2.find(el) == set2.end()){
            ans.insert(el);
        }
    }
    cout << len(ans) << "\n";
    for(auto el : ans){
        cout << el << " ";
    }
}
