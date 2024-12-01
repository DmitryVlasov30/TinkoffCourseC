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

vector<int> count_sort(vector<int> arr, int n){
    int max_num = 0, min_num = inf;
    for(int i = 0; i < n; ++i){
        if (arr[i] > max_num){max_num = arr[i];}
        if (arr[i] < min_num){min_num = arr[i];}
    }
    vector<int> ans(max_num-min_num+1);
    for (int i = 0; i < n; ++i){
        //cout << arr[i] - min_num << "<-----\n";
        ans[arr[i] - min_num]++;
    }
    /*
    cout << len(ans) << "]\n";
    for(int i = 0; i < len(ans); ++i){
        cout << ans[i] << "--\n";
    }
    */
    vector<int> res;
    for (int i = 0; i < max_num - min_num + 1; ++i){
        for (int j = 0; j < ans[i]; ++j){
            res.emp(i+min_num);
        }
    }
    return res;
}


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; ++i){
        int el; cin >> el; arr.emp(el);
    }
    for(auto el : count_sort(arr, n)){
        cout << el << " ";
    }
}
